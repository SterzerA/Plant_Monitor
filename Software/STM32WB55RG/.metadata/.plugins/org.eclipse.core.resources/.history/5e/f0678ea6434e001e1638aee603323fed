/*
 * ess_meas.h
 *
 *  Created on: Aug 1, 2023
 *      Author: alexa
 */

#ifndef ESS_MEAS_H_
#define ESS_MEAS_H_

#include <stdint.h>
#include "main.h"

/* Full-scale digital value with a resolution of 12 bits (voltage range     */
/* determined by analog voltage references Vref+ and Vref-,                 */
/* refer to reference manual).                                              */
#define DIGITAL_SCALE_12BITS             ((uint32_t) 0xFFF)

/* Definitions of environment analog values */
/* Value of analog reference voltage (Vref+), connected to analog voltage   */
/* supply Vdda (unit: mV).                                                  */
#define VDDA_APPLI                       ((uint32_t)3300)
/* Init variable out of ADC expected conversion data range */
#define VAR_CONVERTED_DATA_INIT_VALUE    (DIGITAL_SCALE_12BITS + 1)
#define SENSOR_MIN 2300U
#define SENSOR_MAX 4095U
#define BUFFERSIZE 16


/* Private macro -------------------------------------------------------------*/

/**
  * @brief  Macro to calculate the voltage (unit: mVolt)
  *         corresponding to a ADC conversion data (unit: digital value).
  * @note   ADC measurement data must correspond to a resolution of 12bits
  *         (full scale digital value 4095). If not the case, the data must be
  *         preliminarily rescaled to an equivalent resolution of 12 bits.
  * @note   Analog reference voltage (Vref+) must be known from
  *         user board environment.
  * @param  __VREFANALOG_VOLTAGE__ Analog reference voltage (unit: mV)
  * @param  __ADC_DATA__ ADC conversion data (resolution 12 bits)
  *                       (unit: digital value).
  * @retval ADC conversion data equivalent voltage value (unit: mVolt)
  */
#define __ADC_CALC_DATA_VOLTAGE(__VREFANALOG_VOLTAGE__, __ADC_DATA__)       \
  ((__ADC_DATA__) * (__VREFANALOG_VOLTAGE__) / DIGITAL_SCALE_12BITS)

/* public function prototypes */

uint8_t getHumidity(void);
void initBuffer(void);

typedef uint16_t aBufferArray[BUFFERSIZE];

typedef struct {
	aBufferArray buf;
	uint8_t size;
	uint8_t write;
	uint8_t numberOfValidElements;
}sRingBuffer;



#endif /* ESS_MEAS_H_ */
