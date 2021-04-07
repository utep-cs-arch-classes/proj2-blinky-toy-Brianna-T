#include <msp430.h>
#include "libTimer.h"
#include "buzz.h"

void buzzer_init(){
  //p2SEL2.6, .7, must be zero
  timerAUpmode(); //used for speaker
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6; //output to speaker(P2.6)
}

char buzzer_set_period(short cycles){
  //buzzer clock
  CCR0 = cycles;
  CCR1 = cycles >> 1; //one half cycle
}

void loop(){
  short tone = buzzer_set_period(10000);

  //loop to go thru tones, still testing
  for(int i=0; i<=2; i++){
    if(i==1){
      tone= buzzer_set_period(1000);
    }
    if(i==2){
      tone= buzzer_set_period(10000);
    }
  }
}
