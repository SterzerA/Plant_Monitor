#include <humidity_meas.h>


/* private function prototypes */

uint16_t readADC(void);
uint16_t averageMeasurement(void);
uint8_t normalizeHumidity(uint16_t measurement);
void filterHumidity(void);

extern ADC_HandleTypeDef hadc1;

uint8_t filteredNormalizedHumidity = 0;

volatile sRingBuffer myBuffer;


/*function definitions */

/* Calculate rolling average based on sRingBuffer myBuffer*/
uint16_t averageMeasurement(){

	uint16_t filteredMeasurement = 0;
	uint8_t n = 0;
	uint32_t sumOfMeasurements = 0;

	//sum up measurements for average calculation
    for (n = 0; n < myBuffer.numberOfValidElements; ++n){
		sumOfMeasurements += myBuffer.buf[n];
	}

	//calculate moving average to filter measurement. Decimals are cut off
	filteredMeasurement = sumOfMeasurements / myBuffer.numberOfValidElements;

	return filteredMeasurement;
}

/*Conversion of absolute humidity values to percentage*/
uint8_t normalizeHumidity(uint16_t measurement){
	double relativeHumidity = 0.0;

	// calculate relateiveHumidity based on sensor calibration values for water
	// (SENSOR_MIN) and air (SENSOR_MAX) environment. Decimals are cut off

	relativeHumidity = (((double)(SENSOR_MAX - measurement) / (SENSOR_MAX - SENSOR_MIN)))*100;

	return relativeHumidity;
}

/* provide humidity as percentage based on n=BUFFERSIZE last measurements.
 * 0% equals air, 100% equals water.
 * Rolling arithmetic mean is calculated and outlier measurement values are
 * limited via floor/ceiling function. */
uint8_t getHumidity(void){

	filterHumidity();

	filteredNormalizedHumidity = normalizeHumidity(averageMeasurement());
	return filteredNormalizedHumidity;

}
/*Initialization of ringbuffer to store adc measurements*/
void initBuffer(void){

	for (uint8_t n = 0; n<BUFFERSIZE;++n){
		myBuffer.buf[n] = 0;
	}

	myBuffer.size = BUFFERSIZE;
	myBuffer.write = 0;
	myBuffer.numberOfValidElements = 0;
}

/*Limiting ADC values to SENSOR_MAX and SENSOR_MIN boundaries*/
void filterHumidity(void){

	for(uint8_t n = 0; n < BUFFERSIZE;++n){
		myBuffer.buf[n] = MAX(SENSOR_MIN,myBuffer.buf[n]);
		myBuffer.buf[n] = MIN(SENSOR_MAX,myBuffer.buf[n]);
	}

}


void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
  /* Retrieve ADC conversion data */

	myBuffer.buf[myBuffer.write] = HAL_ADC_GetValue(hadc);

	//check if myBuffer.wirte is within valid array boundaries
	if (myBuffer.write < myBuffer.size - 1){
		++myBuffer.write;
		//increase myBuffer.numberOfValidElements only if BUFFERSIZE has not been reached
		myBuffer.numberOfValidElements = myBuffer.numberOfValidElements >= BUFFERSIZE ? BUFFERSIZE : ++myBuffer.numberOfValidElements;
	}
	else{
		myBuffer.write = 0;
	}

}
