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
#include "ess_app.h"
#include "stm32_seq.h"


typedef struct
{
  ESS_MeasVal_t MeasurementvalueChar;
  uint8_t TimerMeasurement_Id;

} ESSAPP_Context_t;

#define ESSAPP_MEASUREMENT_INTERVAL   (10000000/CFG_TS_TICK_VAL)  /**< 10s */

static ESSAPP_Context_t ESSAPP_Context;

static void ESMeas( void );
static void ESSAPP_Measurement(void);
static uint32_t ESSAPP_Read_RTC_SSR_SS ( void );


void ESSAPP_Init(void)
{
  UTIL_SEQ_RegTask( 1<< CFG_TASK_MEAS_REQ_ID, UTIL_SEQ_RFU, ESSAPP_Measurement );
/* USER CODE BEGIN PMSAPP_Init */
  
  /**
   * Create timer for Humidity Measurement
   */
  HW_TS_Create(CFG_TIM_PROC_ID_ISR, &(ESSAPP_Context.TimerMeasurement_Id), hw_ts_Repeated, ESMeas);

/* USER CODE END HRSAPP_Init */
  return;
}

static void ESSAPP_Measurement(void)
{
/* USER CODE BEGIN HRSAPP_Measurement */
  uint32_t measurement;

  measurement = ((ESSAPP_Read_RTC_SSR_SS()) & 0x07) + 65;

  ESSAPP_Context.MeasurementvalueChar.MeasurementValue = measurement;

  ESS_UpdateChar(HUMIDITY_UUID ,(uint8_t *)&ESSAPP_Context.MeasurementvalueChar);

/* USER CODE END HRSAPP_Measurement */
  return;
}

static void ESMeas( void )
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

static uint32_t ESSAPP_Read_RTC_SSR_SS ( void )
{
  return ((uint32_t)(READ_BIT(RTC->SSR, RTC_SSR_SS)));
}

