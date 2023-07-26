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
#include "hss_app.h"
#include "stm32_seq.h"


typedef struct
{
  HSS_MeasVal_t MeasurementvalueChar;
  uint8_t TimerMeasurement_Id;

} HSSAPP_Context_t;

#define HSSAPP_MEASUREMENT_INTERVAL   (10000000/CFG_TS_TICK_VAL)  /**< 10s */

static HSSAPP_Context_t HSSAPP_Context;

static void HSMeas( void );
static void HSSAPP_Measurement(void);
static uint32_t HSSAPP_Read_RTC_SSR_SS ( void );


void HSS_Notification(HSS_App_Notification_evt_t *pNotification)
{
/* USER CODE BEGIN HSS_Notification_1 */

/* USER CODE END HSS_Notification_1 */
  switch(pNotification->HSS_Evt_Opcode)
  {
/* USER CODE BEGIN HSS_Notification_HSS_Evt_Opcode */

/* USER CODE END HSS_Notification_HSS_Evt_Opcode */

    case HSS_NOTIFICATION_ENABLED:
/* USER CODE BEGIN HSS_NOTIFICATION_ENABLED */
      /**
       * It could be the enable notification is received twice without the disable notification in between
       */
      HW_TS_Stop(HSSAPP_Context.TimerMeasurement_Id);
      HW_TS_Start(HSSAPP_Context.TimerMeasurement_Id, HSSAPP_MEASUREMENT_INTERVAL);
/* USER CODE END HSS_NOTIFICATION_ENABLED */
      break;

    case HSS_NOTIFICATION_DISABLED:
/* USER CODE BEGIN HSS_NOTIFICATION_DISABLED */
      HW_TS_Stop(HSSAPP_Context.TimerMeasurement_Id);
/* USER CODE END HSS_NOTIFICATION_DISABLED */
      break;

   default:
/* USER CODE BEGIN HSS_Notification_Default */

/* USER CODE END HSS_Notification_Default */
      break;
  }
/* USER CODE BEGIN HSS_Notification_2 */

/* USER CODE END HSS_Notification_2 */
  return;
}

void HSSAPP_Init(void)
{
  UTIL_SEQ_RegTask( 1<< CFG_TASK_MEAS_REQ_ID, UTIL_SEQ_RFU, HSSAPP_Measurement );
/* USER CODE BEGIN PMSAPP_Init */
  
  /**
   * Create timer for Humidity Measurement
   */
  HW_TS_Create(CFG_TIM_PROC_ID_ISR, &(HSSAPP_Context.TimerMeasurement_Id), hw_ts_Repeated, HSMeas);

/* USER CODE END HSSAPP_Init */
  return;
}

static void HSSAPP_Measurement(void)
{
/* USER CODE BEGIN HSSAPP_Measurement */
  uint32_t measurement;

  measurement = ((HSSAPP_Read_RTC_SSR_SS()) & 0x07) + 65;

  HSSAPP_Context.MeasurementvalueChar.MeasurementValue = measurement;

  HSS_UpdateChar(HUMIDITY_UUID ,(uint8_t *)&HSSAPP_Context.MeasurementvalueChar);

/* USER CODE END HSSAPP_Measurement */
  return;
}

static void HSMeas( void )
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

static uint32_t HSSAPP_Read_RTC_SSR_SS ( void )
{
  return ((uint32_t)(READ_BIT(RTC->SSR, RTC_SSR_SS)));
}

