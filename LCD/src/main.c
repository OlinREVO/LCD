/**
* LCD Sensor Node
* REVO
* Author: Jay, Nitya, Pratool
* Description: ADM12864H Ver1.0
*/
#include <stdint.h>
#include "lcd.h"

//structure of window coordinates
struct window {
	uint8_t xmin;
	uint8_t ymin;
	uint8_t xmax;
	uint8_t ymax;
} win;

void delay1s(void)
{
	volatile uint16_t i;
	for(i=0; i<15000; i++);
}


int main(void) {
	// Wait a little while the display starts up
	delay1s();
	// Initialize the LCD
	ks0108Init(0);
	//set active window area
	//setWindow(0,0,63,31);
	//draw signal
	char msg[13] = "Hello World";
	ks0108Puts(msg);
	delay1s();
	
	while(1);
}