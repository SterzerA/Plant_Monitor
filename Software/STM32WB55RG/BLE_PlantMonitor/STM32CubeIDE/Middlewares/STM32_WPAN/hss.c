/**
  ******************************************************************************
  * @file    ess.c
  * @author  Alexander Sterzer
  * @brief   Environmental Sensing Service
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


/* Includes ------------------------------------------------------------------*/
#include "common_blesvc.h"

/* Private typedef -----------------------------------------------------------*/
typedef struct
{
  uint16_t	HumiditySvcHdle;		/**< Service handle */
  uint16_t	HumidityCharHdle;				/**< Characteristic handle */

}HSS_Context_t;


/**
 * START of Section BLE_DRIVER_CONTEXT
 */

PLACE_IN_SECTION("BLE_DRIVER_CONTEXT") static HSS_Context_t HSS_Context;


/**
 * END of Section BLE_DRIVER_CONTEXT
 */


/* Private function prototypes -----------------------------------------------*/

static tBleStatus Update_Char_Measurement(HSS_MeasVal_t *pMeasurement );
static SVCCTL_EvtAckStatus_t HumiditySensing_Event_Handler(void *Event);


/* Functions Definition ------------------------------
 * ------------------------*/
/* Private functions ----------------------------------------------------------*/

#define COPY_UUID_128(uuid_struct, uuid_15, uuid_14, uuid_13, uuid_12, uuid_11, uuid_10, uuid_9, uuid_8, uuid_7, uuid_6, uuid_5, uuid_4, uuid_3, uuid_2, uuid_1, uuid_0) \
do {\
    uuid_struct[0] = uuid_0; uuid_struct[1] = uuid_1; uuid_struct[2] = uuid_2; uuid_struct[3] = uuid_3; \
    uuid_struct[4] = uuid_4; uuid_struct[5] = uuid_5; uuid_struct[6] = uuid_6; uuid_struct[7] = uuid_7; \
    uuid_struct[8] = uuid_8; uuid_struct[9] = uuid_9; uuid_struct[10] = uuid_10; uuid_struct[11] = uuid_11; \
    uuid_struct[12] = uuid_12; uuid_struct[13] = uuid_13; uuid_struct[14] = uuid_14; uuid_struct[15] = uuid_15; \
}while(0)

/* Humidity Characteristics Service */
/*
 The following 128bits UUIDs have been generated from a random UUID
 generator:
 B92B2B2C-7FB5-48AE-81F7-D4311E2DAA5A: Service 128bits UUID
 7364556E-87F2-4CF8-A1CF-FB4B7FF12758: Characteristic_1 128bits UUID
 */
#define COPY_MY_HUMIDTY_SERVICE_UUID(uuid_struct)          COPY_UUID_128(uuid_struct,0xB9,0x2B,0x2B,0x2C,0x7F,0xB5,0x48,0xAE,0x81,0xF7,0xD4,0x31,0x1E,0x2D,0xAA,0x5A)
#define COPY_MY_HUMIDTY_CHAR_UUID(uuid_struct)    COPY_UUID_128(uuid_struct,0x73,0x64,0x55,0x6E,0x87,0xF2,0x4C,0xF8,0xA1,0xCF,0xFB,0x4B,0x7F,0xF1,0x27,0x58)


/**
 * @brief  Event handler
 * @param  Event: Address of the buffer holding the Event
 * @retval Ack: Return whether the Event has been managed or not
 */
static SVCCTL_EvtAckStatus_t HumiditySensing_Event_Handler(void *Event)
{
  SVCCTL_EvtAckStatus_t return_value;
  hci_event_pckt *event_pckt;
  evt_blecore_aci *blecore_evt;
  aci_gatt_attribute_modified_event_rp0    * attribute_modified;
  HSS_App_Notification_evt_t Notification;

  return_value = SVCCTL_EvtNotAck;
  event_pckt = (hci_event_pckt *)(((hci_uart_pckt*)Event)->data);

  switch(event_pckt->evt)
  {
    case HCI_VENDOR_SPECIFIC_DEBUG_EVT_CODE:
    {
      blecore_evt = (evt_blecore_aci*)event_pckt->data;
      switch(blecore_evt->ecode)
      {
        case ACI_GATT_ATTRIBUTE_MODIFIED_VSEVT_CODE:
        {
          attribute_modified = (aci_gatt_attribute_modified_event_rp0*)blecore_evt->data;
          if(attribute_modified->Attr_Handle == (HSS_Context.HumidityCharHdle + 2))
          {
            return_value = SVCCTL_EvtAckFlowEnable;

            /**
             * Notify the application to start measurement
             */
            if(attribute_modified->Attr_Data[0] & COMSVC_Notification)
            {
            	APP_DBG_MSG("ACI_GATT_ATTRIBUTE_MODIFIED_VSEVT_CODE HSS_NOTIFICATION_ENABLED\n");
              Notification.HSS_Evt_Opcode = HSS_NOTIFICATION_ENABLED;
              HSS_Notification(&Notification);
            }
            else
            {
            	APP_DBG_MSG("ACI_GATT_ATTRIBUTE_MODIFIED_VSEVT_CODE HSS_NOTIFICATION_DISABLED\n");
              Notification.HSS_Evt_Opcode =HSS_NOTIFICATION_DISABLED;
              HSS_Notification(&Notification);
            }
          }
        }
        break;
        default:
        break;
      }
    }
    break; /* HCI_HCI_VENDOR_SPECIFIC_DEBUG_EVT_CODE_SPECIFIC */

    default:
    break;
  }

  return(return_value);
}/* end EnvironmentalSensing_Event_Handler */

/**
 * @brief  Heart rate Measurement Characteristic update
 * @param  Service_Instance: Instance of the service to which the characteristic belongs
 * @param  pBodySensorLocationValue: The address of the new value to be written
 * @retval None
 */
static tBleStatus Update_Char_Measurement (HSS_MeasVal_t *pMeasurement )
{
  tBleStatus return_value=BLE_STATUS_SUCCESS;

  return_value = aci_gatt_update_char_value(HSS_Context.HumiditySvcHdle,
                                            HSS_Context.HumidityCharHdle,
                                            0, /* charValOffset */
                                            2, /* charValueLen */
											(uint8_t *) &pMeasurement->MeasurementValue);

  return return_value;
}/* end Update_Char_Measurement() */


/* Public functions ----------------------------------------------------------*/

/**
 * @brief  Service initialization
 * @param  None
 * @retval None
 */
void HSS_Init(void)
{
	Char_UUID_t  uuid;
	tBleStatus ret = BLE_STATUS_INVALID_PARAMS;

  /**
   *	Register the event handler to the BLE controller
   */
  SVCCTL_RegisterSvcHandler(HumiditySensing_Event_Handler);

  /**
   *  Add Heart Rate Service
   *
   * Max_Attribute_Records = 2*no_of_char + 1
   * service_max_attribute_record = 1 for heart rate service +
   *                                2 for hear rate measurement characteristic +
   *                                1 for client char configuration descriptor +
   *                                2 for body sensor location characteristic +
   *                                2 for control point characteristic
   */
  COPY_MY_HUMIDTY_SERVICE_UUID(uuid.Char_UUID_128);

  ret = aci_gatt_add_service(UUID_TYPE_128,
                                   (Service_UUID_t *) &uuid,
                                   PRIMARY_SERVICE,
                                   6,
                                   &(HSS_Context.HumiditySvcHdle));

  if (ret == BLE_STATUS_SUCCESS)
  {
    BLE_DBG_HRS_MSG ("Humidity Sensing Service (HSS) is added Successfully %04X\n",
                        HSS_Context.HumiditySvcHdle);
  }
  else
  {
    BLE_DBG_HRS_MSG ("FAILED to add Humidity Sensing Service (HSS), Error: %02X !!\n",
                        ret);
  }

  /**
   *  Add Heart Rate Measurement Characteristic
   */
  COPY_MY_HUMIDTY_CHAR_UUID(uuid.Char_UUID_128);
  ret = aci_gatt_add_char(HSS_Context.HumiditySvcHdle,
                                   UUID_TYPE_128,
                                   &uuid ,
                                   2,                                   /** Measure */
                                   CHAR_PROP_READ,
                                   ATTR_PERMISSION_NONE,
                                   GATT_DONT_NOTIFY_EVENTS, /* gattEvtMask */
                                   10, /* encryKeySize */
                                   0, /* isVariable */
                                   &(HSS_Context.HumidityCharHdle));

  if (ret == BLE_STATUS_SUCCESS)
  {
    BLE_DBG_HRS_MSG ("Humidity Measurement Characteristic Added Successfully  %04X \n",
                        HSS_Context.HumidityCharHdle);
  }
  else
  {
    BLE_DBG_HRS_MSG ("FAILED to add Humidity Measurement Characteristic, Error: %02X !!\n",
                        ret);
  }


  return;
}

/**
 * @brief  Characteristic update
 * @param  UUID: UUID of the characteristic
 * @retval BodySensorLocationValue: The new value to be written
 */
tBleStatus HSS_UpdateChar(uint16_t UUID, uint8_t *pPayload)
{
  tBleStatus return_value=0;
  return_value = Update_Char_Measurement((HSS_MeasVal_t*)pPayload);

  return return_value;
}/* end HSS_UpdateChar() */


