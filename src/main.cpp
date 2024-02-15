// Author:      Carmen Timmer   
// Net ID:      cvtimmer   
// Date:        Feb. 14, 2024  
// Assignment:     Lab 2
//
// Description: This file contains a programmatic overall description of the
// program. It should never contain assignments to special function registers
// for the exception key one-line code such as checking the state of the pin.
//
//----------------------------------------------------------------------//
#include <Arduino.h>
#include <avr/io.h>
#include "led.h"
#include "switch.h"
#include "timer.h"

/*
 * Define a set of states that can be used in the state machine using an enum.
 */

/*Alright so heres a plan i got:
  - will need parameters to set the different speeds as seen in the video
  - set up a state machine that takes into account of when the button is pressed and when its been released
  - set up a pin change interrupt so that the code/machine knows what to do when the switch has been pressed and released while also applying the correct speeds tto the LEDs

*/

int main(){
  
  /*
  * Implement a state machine in the while loop which achieves the assignment
  * requirements.
  */
	while (1) {

	}
  return 0;
}

/* Implement an Pin Change Interrupt which handles the switch being
* pressed and released. When the switch is pressed and released, the LEDs
* change at twice the original rate. If the LEDs are already changing at twice
* the original rate, it goes back to the original rate.
*/
ISR(){
  
}