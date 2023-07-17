/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    pms_app.c
  * @author  Alexander Sterzer
  * @brief   Plant Monitor Service Application
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "app_common.h"

#include "ble.h"
#include "pms_app.h"
#include "stm32_seq.h"


typedef struct
{
  HRS_BodySensorLocation_t BodySensorLocationChar;
  HRS_MeasVal_t MeasurementvalueChar;
  uint8_t ResetEnergyExpended;
  uint8_t TimerMeasurement_Id;

} HRSAPP_Context_t;

#define PMSAPP_MEASUREMENT_INTERVAL   (10000000/CFG_TS_TICK_VAL)  /**< 10s */

static HRSAPP_Context_t HRSAPP_Context;

static void PHMeas( void );
static void PMSAPP_Measurement(void);
static uint32_t PMSAPP_Read_RTC_SSR_SS ( void );

/* Functions Definition ------------------------------------------------------*/
void PMS_Notification(HRS_App_Notification_evt_t *pNotification)
{
/* USER CODE BEGIN HRS_Notification_1 */

/* USER CODE END HRS_Notification_1 */
  switch(pNotification->HRS_Evt_Opcode)
  {
/* USER CODE BEGIN HRS_Notification_HRS_Evt_Opcode */

/* USER CODE END HRS_Notification_HRS_Evt_Opcode */
#if (BLE_CFG_HRS_ENERGY_EXPENDED_INFO_FLAG != 0)
    case HRS_RESET_ENERGY_EXPENDED_EVT:
/* USER CODE BEGIN HRS_RESET_ENERGY_EXPENDED_EVT */
      HRSAPP_Context.MeasurementvalueChar.EnergyExpended = 0;
      HRSAPP_Context.ResetEnergyExpended = 1;
/* USER CODE END HRS_RESET_ENERGY_EXPENDED_EVT */
      break;
#endif

    case HRS_NOTIFICATION_ENABLED:
/* USER CODE BEGIN HRS_NOTIFICATION_ENABLED */
      /**
       * It could be the enable notification is received twice without the disable notification in between
       */
      HW_TS_Stop(HRSAPP_Context.TimerMeasurement_Id);
      HW_TS_Start(HRSAPP_Context.TimerMeasurement_Id, PMSAPP_MEASUREMENT_INTERVAL);
/* USER CODE END HRS_NOTIFICATION_ENABLED */
      break;

    case HRS_NOTIFICATION_DISABLED:
/* USER CODE BEGIN HRS_NOTIFICATION_DISABLED */
      HW_TS_Stop(HRSAPP_Context.TimerMeasurement_Id);
/* USER CODE END HRS_NOTIFICATION_DISABLED */
      break;

#if (BLE_CFG_OTA_REBOOT_CHAR != 0)
    case HRS_STM_BOOT_REQUEST_EVT:
/* USER CODE BEGIN HRS_STM_BOOT_REQUEST_EVT */
      *(uint32_t*)SRAM1_BASE = *(uint32_t*)pNotification->DataTransfered.pPayload;
      NVIC_SystemReset();
/* USER CODE END HRS_STM_BOOT_REQUEST_EVT */
      break;
#endif

   default:
/* USER CODE BEGIN HRS_Notification_Default */

/* USER CODE END HRS_Notification_Default */
      break;
  }
/* USER CODE BEGIN HRS_Notification_2 */

/* USER CODE END HRS_Notification_2 */
  return;
}

void PMSAPP_Init(void)
{
  UTIL_SEQ_RegTask( 1<< CFG_TASK_MEAS_REQ_ID, UTIL_SEQ_RFU, PMSAPP_Measurement );
/* USER CODE BEGIN HRSAPP_Init */
  /**
   * Set Body Sensor Location
   */
  HRSAPP_Context.ResetEnergyExpended = 0;
  HRSAPP_Context.BodySensorLocationChar = HRS_BODY_SENSOR_LOCATION_HAND;
  HRS_UpdateChar(SENSOR_LOCATION_UUID, (uint8_t *)&HRSAPP_Context.BodySensorLocationChar);


  /**
   * Set Flags for measurement value
   */

  HRSAPP_Context.MeasurementvalueChar.Flags = ( HRS_HRM_VALUE_FORMAT_UINT16      | 
                                                  HRS_HRM_SENSOR_CONTACTS_PRESENT   | 
                                                  HRS_HRM_SENSOR_CONTACTS_SUPPORTED |
                                                  HRS_HRM_ENERGY_EXPENDED_PRESENT  |
                                                  HRS_HRM_RR_INTERVAL_PRESENT );

#if (BLE_CFG_HRS_ENERGY_EXPENDED_INFO_FLAG != 0)
  if(HRSAPP_Context.MeasurementvalueChar.Flags & HRS_HRM_ENERGY_EXPENDED_PRESENT)
    HRSAPP_Context.MeasurementvalueChar.EnergyExpended = 10;
#endif
  
#if (BLE_CFG_HRS_ENERGY_RR_INTERVAL_FLAG != 0)
  if(HRSAPP_Context.MeasurementvalueChar.Flags & HRS_HRM_RR_INTERVAL_PRESENT)
  {
    uint8_t i;
    
    HRSAPP_Context.MeasurementvalueChar.NbreOfValidRRIntervalValues = BLE_CFG_HRS_ENERGY_RR_INTERVAL_FLAG;
    for(i = 0; i < BLE_CFG_HRS_ENERGY_RR_INTERVAL_FLAG; i++)
      HRSAPP_Context.MeasurementvalueChar.aRRIntervalValues[i] = 1024;
  }
#endif
  
  /**
   * Create timer for Heart Rate Measurement
   */
  HW_TS_Create(CFG_TIM_PROC_ID_ISR, &(HRSAPP_Context.TimerMeasurement_Id), hw_ts_Repeated, PHMeas);

/* USER CODE END HRSAPP_Init */
  return;
}

static void PMSAPP_Measurement(void)
{
/* USER CODE BEGIN HRSAPP_Measurement */
  uint32_t measurement;

  measurement = ((HRSAPP_Read_RTC_SSR_SS()) & 0x07) + 65;

  HRSAPP_Context.MeasurementvalueChar.MeasurementValue = measurement;
#if (BLE_CFG_HRS_ENERGY_EXPENDED_INFO_FLAG != 0)
  if((HRSAPP_Context.MeasurementvalueChar.Flags & HRS_HRM_ENERGY_EXPENDED_PRESENT) &&
     (HRSAPP_Context.ResetEnergyExpended == 0))
    HRSAPP_Context.MeasurementvalueChar.EnergyExpended += 5;
  else if(HRSAPP_Context.ResetEnergyExpended == 1)
    HRSAPP_Context.ResetEnergyExpended = 0;
#endif

  HRS_UpdateChar(HEART_RATE_MEASURMENT_UUID, (uint8_t *)&HRSAPP_Context.MeasurementvalueChar);

/* USER CODE END HRSAPP_Measurement */
  return;
}

static void PHMeas( void )
{
  /**
   * The code shall be executed in the background as aci command may be sent
   * The background is the only place where the application can make sure a new aci command
   * is not sent if there is a pending one
   */
  UTIL_SEQ_SetTask( 1<<CFG_TASK_MEAS_REQ_ID, CFG_SCH_PRIO_0);
/* USER CODE BEGIN HrMeas */

/* USER CODE END HrMeas */

  return;
}

static uint32_t PMSAPP_Read_RTC_SSR_SS ( void )
{
  return ((uint32_t)(READ_BIT(RTC->SSR, RTC_SSR_SS)));
}

