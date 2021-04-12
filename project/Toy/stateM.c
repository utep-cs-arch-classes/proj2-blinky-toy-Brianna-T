#include <msp430.h>
#include "stateM.h"
#include "Blinkled.h"

char toggle_red()/* always toggles */
{
  static char state = 0;

  switch (state) {
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }
  return 1; /*changes an led */
}

void state_advance(){
  char changed=0;

  static enum {R=0, G=1} color=G; //Green starts on
  switch (color){ //blinking only green, wanted red, but instead green
  case G: changed = toggle_red(); color=R; break;
  case R: changed = toggle_red(); color=G; break;
  }

  led_changed = changed;
  led_update();
}
