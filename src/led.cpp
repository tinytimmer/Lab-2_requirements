// Description: This file implements turnOnLED and initLED to control
// the LEDs.
//----------------------------------------------------------------------//


#include <avr/io.h>
#include <util/delay.h>
#include "led.h"

/* Initialize PA0, PA1, PA2, and PA3 to outputs
*/

/* The pins for these on our board is the following:
PA0 = pin 22
PA1 = pin 23
PA2 = pin 24
PA3 = pin 25
*/
void initLED(){
//this set the LEDs as outputs
  DDRA |= (1 << DDA0);
  DDRA |= (1 << DDA1);
  DDRA |= (1 << DDA2);
  DDRA |= (1 << DDA3);
}

/* This must be one line of code.
* In this function you will be giving a number "num" which will be represented
* in binary by four LEDs. You must effectively assign the lowest four bits of
* "num" to the appropriate bits of PORTA.
*/

void turnOnLEDWithChar(unsigned char num){
  PORTA = (PORTA & 0xF0) | (num & 0x0F);
}
