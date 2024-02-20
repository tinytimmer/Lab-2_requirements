// Description: This file implements functions that utilize the timers
//----------------------------------------------------------------------//

#include "timer.h"
#include <HardwareSerial.h> //error on Serial, had to put this in

/* Initialize timer 0, you should not turn the timer on here.
* You will need to use CTC mode */
//Got it!
void initTimer0(){
    //set up timer0 for ctc mode
    TCCR0A &= ~(1 << WGM00);
    TCCR0A |= (1 << WGM01);
    TCCR0A &= ~(1 << WGM02);

    //set the bits for prescalar
    //TCCR0B |= (1 << CS02)|(1 << CS01)|(1 << CS00);

    TCCR0B |= (1 << CS00);
    TCCR0B &= ~(1 << CS01);
    TCCR0B |= (1 << CS02); 

    //CTC compare value
    OCR0A = 156;
    
     //initilize counter
    TCNT0 = 0;

}

/* This delays the program an amount specified by unsigned int delay.
* Use timer 0. Keep in mind that you need to choose your prescalar wisely
* such that your timer is precise to 1 millisecond and can be used for
* 100-200 milliseconds
*/
void delayMs(unsigned int delay){
    int timer_count = 0;
    int prescalar = 64;
    
    timer_count = ((delay * 0.001) * (16000000 / prescalar)) - 1;
    Serial.println(timer_count);
    OCR0A = timer_count;
    
    while (1)
    {
        if (TCNT0 >= OCR0A)
        {
            break;
        }
        TIFR0 |= (1 << OCF0A); //this part will turn off the flag
    }
    

}
