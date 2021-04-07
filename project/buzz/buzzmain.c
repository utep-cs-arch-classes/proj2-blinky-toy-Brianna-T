#include <msp430.h>
#include "timer.h"

int main(){
  configureClocks();
  buzzer();
  start();

  or_sr(0x18); //CPU off, GIE on power save
}
