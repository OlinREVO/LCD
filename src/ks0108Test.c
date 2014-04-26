/*
 * Copyright:      Fabian Maximilian Thiele  mailto:me@apetech.de
 * Author:         Fabian Maximilian Thiele
 * Remarks:        this Copyright must be included
 * known Problems: none
 * Version:        1.1
 * Description:    KS0108 Library Demo Program 
 * 
 */

#include <inttypes.h>
#include <avr/io.h>
#include <avr/pgmspace.h>

#include "ks0108.h"
#include "arial_bold_14.h"
#include "SC.h"
#include "Bitmap.h"


int main(void) {
	
	// Wait a little while the display starts up
	for(volatile uint16_t i=0; i<15000; i++);
	
	// Initialize the LCD
	ks0108Init(0);
	
	// Select a font
	//ks0108SelectFont(Arial_Bold_14, ks0108ReadFontData, BLACK);
	// Set a position
	//ks0108GotoXY(15,10);
	// Print some text
	//ks0108Puts_P(PSTR("test"));
	// a nice little round rect
	//ks0108DrawRoundRect(5, 5, 117, 20, 8, BLACK);

	// Once again :)
	// Select a font
	//ks0108SelectFont(SC, ks0108ReadFontData, BLACK);
	// Set a position
	//ks0108GotoXY(5,30);
	// Print some text
	//ks0108Puts("test");
   // ks0108DrawLine(0, 0, 100, 50, BLACK);
	//ks0108DrawCircle(50, 40, 20, BLACK);
	ks0108ClearScreen();
	LoadBitmap(IMAGE);
	while(1);
}
