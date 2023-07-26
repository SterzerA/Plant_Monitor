/**
  ******************************************************************************
  * @file    hss.h
  * @author  Alexander Sterzer
  * @brief   Header for hss.c module
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2018-2021 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */



/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __HSS_H
#define __HSS_H

#ifdef __cplusplus
extern "C" {
#endif

  /* Includes ------------------------------------------------------------------*/
  /* Exported types ------------------------------------------------------------*/
  typedef enum
  {
    HSS_HS_VALUE_FORMAT_UINT16 = 1,
  } HSS_HSFlags_t;

    typedef enum
  {
    HSS_NOTIFICATION_ENABLED,
    HSS_NOTIFICATION_DISABLED,
  } HSS_NotCode_t;

  typedef enum
  {
    HSS_SAMPLING_FUNCTION_UNSPECIFIED = 0x00,
	HSS_SAMPLING_FUNCTION_INSTANTANEOUS = 0x01,
	HSS_SAMPLING_FUNCTION_ARITHMETIC_MEAN = 0x02,
	HSS_SAMPLING_FUNCTION_RMS = 0x03,
	HSS_SAMPLING_FUNCTION_MAXIMUM = 0x04,
	HSS_SAMPLING_FUNCTION_MINIMUM = 0x05,
	HSS_SAMPLING_FUNCTION_ACCUMULATED = 0x06,
	HSS_SAMPLING_FUNCTION_COUNT = 0x07,
  } HSS_SamplingFunction_t;

  typedef enum
  {
	HSS_MEASUREMENT_PERIOD_NOT_IN_USE = 0x00
  } HSS_MeasurementPeriod_t;
  
  typedef enum
  {
	HSS_INTERNAL_UPDATE_INTERVAL_NOT_IN_USE = 0x00,
	HSS_INTERNAL_UPDATE_INTERVAL_1S = 0x01,
  } HSS_InternalUpdateInterval_t;

  typedef enum
  {
	UNSPECIFIED = 0x00,
	AIR = 0x01,
	WATER = 0x02,
	BAROMETRIC = 0x03,
	SOIL = 0x04,
	INFRARED = 0x05,
	MAP_DATABASE = 0x06,
	BAROMETRIC_ELEVATION_SOURCE = 0x07,
	GPS_ONLY_ELEVATION_SOURCE = 0x08,
	GPS_AND_MAP_DATABASE_ELEVATION_SOURCE = 0x09,
	VERTICAL_DATUM_ELEVATION_SOURCE = 0x0A,
	ONSHORE = 0x0B,
	ONBOARD_VESSEL_OR_VEHICLE = 0x0C,
	FRONT = 0x0D,
	BACK_REAR = 0x0E,
	UPPER = 0x0F,
	LOWER = 0x10,
	PRIMARY = 0x11,
	SECONDARY = 0x12,
	OUTDOOR = 0x13,
	INDOOR = 0x14,
	TOP = 0x15,
	BOTTOM = 0x16,
	MAIN = 0x17,
	BACKUP = 0x18,
	AUXILIARY = 0x19,
	SUPPLEMENTARY = 0x1A,
	INSIDE = 0x1B,
	OUTSIDE = 0x1C,
	LEFT = 0x1D,
	RIGHT = 0x1E,
	INTERNAL = 0x1F,
	EXTERNAL = 0x20,
	SOLAR = 0x21
  } HSS_Applications_t;

  typedef enum
  {
    HSS_HS_INFORMATION_NOT_AVAILABLE = 0xFF
  } HSS_MeasurementUncertainty_t;


  typedef struct
{
  uint8_t * pPayload;
  uint8_t     Length;
}HSS_Data_t;

typedef struct
{
  HSS_NotCode_t             HSS_Evt_Opcode;
  HSS_Data_t                DataTransfered;
  uint16_t                  ConnectionHandle;
  uint8_t                   ServiceInstance;
}HSS_App_Notification_evt_t;
  typedef struct{
    uint16_t    MeasurementValue;
  }HSS_MeasVal_t;

  /* Exported constants --------------------------------------------------------*/
  /* External variables --------------------------------------------------------*/
  /* Exported macros -----------------------------------------------------------*/
  /* Exported functions ------------------------------------------------------- */
  void HSS_Init(void);
  
  tBleStatus HSS_UpdateChar(uint16_t uuid, uint8_t *p_payload);
  void HSS_Notification(HSS_App_Notification_evt_t *pNotification);

#ifdef __cplusplus
}
#endif

#endif /*__HRS_H */


