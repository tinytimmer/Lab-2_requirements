// Description: This file implements functions that utilize the timers
//----------------------------------------------------------------------//

#include "timer.h"

/* Initialize timer 0, you should not turn the timer on here.
* You will need to use CTC mode */
//Got it!
void initTimer0(){
    //set up timer0 for ctc mode
    TCCR0A &= ~(1 << WGM00);
    TCCR0A |= (1 << WGM01);
    TCCR0A &= ~(1 << WGM02);
}

/* This delays the program an amount specified by unsigned int delay.
* Use timer 0. Keep in mind that you need to choose your prescalar wisely
* such that your timer is precise to 1 millisecond and can be used for
* 100-200 milliseconds
*/
void delayMs(unsigned int delay){
    
}
