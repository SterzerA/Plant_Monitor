#include <stm32wb55xx.h>
#include "bsp.h"

int main(void){

BSP_init();

	while(1){
	
		BSP_ledRedOn();	
		BSP_ledGreenOn();
		BSP_ledBlueOn();
		
		BSP_delay(500U);
		
		BSP_ledRedOff();	
		BSP_ledGreenOff();
		BSP_ledBlueOff();
		
		BSP_delay(500U);
	
	}
	
	return 0;
}
