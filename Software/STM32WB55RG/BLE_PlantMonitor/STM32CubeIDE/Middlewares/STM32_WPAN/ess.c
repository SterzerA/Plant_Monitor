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
  uint16_t	EnvironmentalSensorSvcHdle;		/**< Service handle */
  uint16_t	HumidityCharHdle;				/**< Characteristic handle */

}ESS_Context_t;


/**
 * START of Section BLE_DRIVER_CONTEXT
 */

PLACE_IN_SECTION("BLE_DRIVER_CONTEXT") static ESS_Context_t ESS_Context;


/**
 * END of Section BLE_DRIVER_CONTEXT
 */


/* Private function prototypes -----------------------------------------------*/

static tBleStatus Update_Char_Measurement(ESS_MeasVal_t *pMeasurement );
static SVCCTL_EvtAckStatus_t EnvironmentalSensing_Event_Handler(void *Event);


/* Functions Definition ------------------------------------------------------*/
/* Private functions ----------------------------------------------------------*/

/**
 * @brief  Event handler
 * @param  Event: Address of the buffer holding the Event
 * @retval Ack: Return whether the Event has been managed or not
 */
static SVCCTL_EvtAckStatus_t EnvironmentalSensing_Event_Handler(void *Event)
{
  SVCCTL_EvtAckStatus_t return_value;
  hci_event_pckt *event_pckt;
  evt_blecore_aci *blecore_evt;
  aci_gatt_attribute_modified_event_rp0    * attribute_modified;
  ESS_App_Notification_evt_t Notification;

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
          if(attribute_modified->Attr_Handle == (ESS_Context.HumidityCharHdle + 2))
          {
            return_value = SVCCTL_EvtAckFlowEnable;

            /**
             * Notify the application to start measurement
             */
            if(attribute_modified->Attr_Data[0] & COMSVC_Notification)
            {
              BLE_DBG_ESS_MSG("ACI_GATT_ATTRIBUTE_MODIFIED_VSEVT_CODE ESS_NOTIFICATION_ENABLED\n");
              Notification.ESS_Evt_Opcode = ESS_NOTIFICATION_ENABLED;
              ESS_Notification(&Notification);
            }
            else
            {
              BLE_DBG_ESS_MSG("ACI_GATT_ATTRIBUTE_MODIFIED_VSEVT_CODE ESS_NOTIFICATION_DISABLED\n");
              Notification.ESS_Evt_Opcode =ESS_NOTIFICATION_DISABLED;
              ESS_Notification(&Notification);
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
static tBleStatus Update_Char_Measurement (ESS_MeasVal_t *pMeasurement )
{
  tBleStatus return_value=BLE_STATUS_SUCCESS;

  return_value = aci_gatt_update_char_value(ESS_Context.EnvironmentalSensorSvcHdle,
                                            ESS_Context.HumidityCharHdle,
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
void ESS_Init(void)
{
  uint16_t uuid;
  tBleStatus hciCmdResult = BLE_STATUS_SUCCESS;

  /**
   *	Register the event handler to the BLE controller
   */
  SVCCTL_RegisterSvcHandler(EnvironmentalSensing_Event_Handler);

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
  uuid = ENVIRONMENTAL_SENSING_SERVICE_UUID;
  hciCmdResult = aci_gatt_add_service(UUID_TYPE_16,
                                   (Service_UUID_t *) &uuid,
                                   PRIMARY_SERVICE,
                                   4,
                                   &(ESS_Context.EnvironmentalSensorSvcHdle));

  if (hciCmdResult == BLE_STATUS_SUCCESS)
  {
    BLE_DBG_HRS_MSG ("Environmental Sensing Service (ESS) is added Successfully %04X\n",
                        HRS_Context.HeartRateSvcHdle);
  }
  else
  {
    BLE_DBG_HRS_MSG ("FAILED to add Environmental Sensing Service (ESS), Error: %02X !!\n",
                        hciCmdResult);
  }

  /**
   *  Add Heart Rate Measurement Characteristic
   */
  uuid = HUMIDITY_UUID;
  hciCmdResult = aci_gatt_add_char(ESS_Context.EnvironmentalSensorSvcHdle,
                                   UUID_TYPE_16,
                                   (Char_UUID_t *) &uuid ,
                                   2,                                   /** Measure */
                                   CHAR_PROP_NOTIFY,
                                   ATTR_PERMISSION_NONE,
                                   GATT_DONT_NOTIFY_EVENTS, /* gattEvtMask */
                                   10, /* encryKeySize */
                                   1, /* isVariable */
                                   &(ESS_Context.HumidityCharHdle));

  if (hciCmdResult == BLE_STATUS_SUCCESS)
  {
    BLE_DBG_HRS_MSG ("Humidity Measurement Characteristic Added Successfully  %04X \n",
                        HRS_Context.HeartRatemeasurementCharHdle);
  }
  else
  {
    BLE_DBG_HRS_MSG ("FAILED to add Humidity Measurement Characteristic, Error: %02X !!\n",
                        hciCmdResult);
  }


  return;
}

/**
 * @brief  Characteristic update
 * @param  UUID: UUID of the characteristic
 * @retval BodySensorLocationValue: The new value to be written
 */
tBleStatus ESS_UpdateChar(uint16_t UUID, uint8_t *pPayload)
{
  tBleStatus return_value=0;
  return_value = Update_Char_Measurement((ESS_MeasVal_t*)pPayload);

  return return_value;
}/* end ESS_UpdateChar() */


