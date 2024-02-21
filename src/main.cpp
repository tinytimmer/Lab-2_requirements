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

#define NORMAL_SPEED 1
#define DOUBLE_SPEED 2

/*
 * Define a set of states that can be used in the state machine using an enum.
 */

  typedef enum stateType_enum{
    wait_press, button_press, wait_release, button_release
  }  stateType;

  //next well make some volatile variables below
  volatile stateType state = wait_press;
  volatile int counter = 0;
  volatile int multiplier = NORMAL_SPEED;

/*Alright so heres a plan i got:
  - will need parameters to set the different speeds as seen in the video
  - set up a state machine that takes into account of when the button is pressed and when its been released
  - set up a pin change interrupt so that the code/machine knows what to do when the switch has been pressed and released while also applying the correct speeds tto the LEDs

*/

int main(){

    Serial.begin(9600);
    initSwitchPB3();
    initTimer0();
    initLED();


/*
  * Implement a state machine in the while loop which achieves the assignment
  * requirements.
  */
 delayMs(100/multiplier);
	while (1) {
    //after 100ms code needs to increment the binary number which is represented by LEDs
    //here is the delay
    delayMs(100/multiplier);
    //counter++;

    //then here is where we turn on the led
    turnOnLEDWithChar(counter);

    //here is the switch statements to go through the different states for the button
    switch (state)
    {
    case wait_press:
      break;

    case button_press:
      //Serial.println("button pressed");
      state = wait_release;
      break;

    case wait_release:
      //Serial.println("wait release");
      break;
    
    case button_release:
      //Serial.println("button release");
      Serial.println(multiplier);
      if (multiplier == NORMAL_SPEED)
      {
        multiplier = DOUBLE_SPEED;
      }

      else if (multiplier == DOUBLE_SPEED)
      {
        multiplier = NORMAL_SPEED;
      }
      
      state = wait_press;
      break;

    }

    //This is the upper limit for the counter
    if (counter == 15)
    {
      counter = 0;
    }
    counter++;
    
	}
  return 0;
}



/* Implement an Pin Change Interrupt which handles the switch being
* pressed and released. When the switch is pressed and released, the LEDs
* change at twice the original rate. If the LEDs are already changing at twice
* the original rate, it goes back to the original rate.
*/
ISR(PCINT0_vect){
  //Serial.println("switch has been HIT");
  if (state == wait_press)
  {
    state = button_press;
  }
  else if (state == wait_release)
  {
    state = button_release;
  }
    
}