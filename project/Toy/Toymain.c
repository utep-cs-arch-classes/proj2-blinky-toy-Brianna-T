#include <msp430.h>
#include "libTimer.h"
#include "Blinkled.h"
#include "buzz.h"

int main(void){
  configureClocks();
  led_init();
  enableWDTInterrupts(); /*timer interrupt*/

  //added from 'Buzzermain.c'
  buzzer_init();
  //buzzer_set_period(10000); //start buzz
  loop(); //start looping notes

  or_sr(0x18); /*CPU off, GIE on, power save*/
}
