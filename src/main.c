/**
* LCD Sensor Node
* REVO
* Author: Jay, Nitya, Pratool
* Description: ADM12864H Ver1.0
*/
#include <stdint.h>
#include "lcd.h"
#include "lcd.c"

//structure of window coordinates
struct window {
	uint8_t xmin;
	uint8_t ymin;
	uint8_t xmax;
	uint8_t ymax;
} win;

void delay1s(void)
{
	uint8_t i;
	for(i=0;i<100;i++)
	_delay_ms(10);
}


int main(void) {
	// Wait a little while the display starts up
	for(volatile uint16_t i=0; i<15000; i++);
	// Initialize the LCD
	ks0108Init(0);
	//set active window area
	setWindow(0,0,63,31);
	//draw signal
	char[30] msg = "Hello World";
	ks0108Puts(msg)
	delay1s();
	
	//set active window area
	setWindow(0,0,127,63);
	//ks0108ClearScreen();

	while(1);
}