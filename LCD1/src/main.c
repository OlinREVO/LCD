/* main.c -- (c) chris kern -- Mon Feb 16 20:35:41 EST 2009     */
/* "Don't fear the pen. When in doubt, draw a pretty picture."  */
/*     -- Baker's Third Law of Design.                           */

#include <stdint.h>
#include <avr/pgmspace.h>
#include "lcd.h"
#include <avr/io.h>
#include "uart.h"

int main(void){
  initUART();

  uint8_t x, y, z = 0;
  DDRC |= _BV(PC5);
  //PORTC |= _BV(PC5); //turns on LCD
  _delay_ms(500);
  UART_putString("in main, PC5 on");

  //endUART();
  //UART_putString("UART initialized\n"); 
  lcd_init();
  UART_putString("LCD initialized\n");
  //print some text
  lcd_set_cursor(0, 11);
  lcd_putstr("128x64 lcd");
  lcd_set_cursor(2, 11);
  lcd_putstr("hello");
  lcd_set_cursor(3, 11);
  lcd_putstr("world");
  lcd_flush();
  UART_putString("finished writing stuff");
  while(1) {

    // draw an animated barberpole on the left side of the screen
    for(x = 0; x < 64; ++x) {
      for(y = 0; y < 64; ++y) {
        if ((y+x+z) % 8 < 4) {
          lcd_setbit(x, y, 1);
          _delay_ms(500);
          UART_putString("barberpole!");
          PORTC |= _BV(PC5);
        } else {
          lcd_setbit(x, y, 0);
          UART_putString("turning off LED");
          PORTC &= ~_BV(PC5);

        }
      }
    }
    ++z;
    if (z == 8) z = 0;
  }
  
  return 0;
}
