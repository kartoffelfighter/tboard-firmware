#ifndef __tboard_h // prevent double inclusion
#define __tboard_h

#include <Arduino.h>
//#define LAYOUT_GERMAN  // do not define if F13+ keys are used
#include "config.h"
#include "pins.h"

void keyboardSetup(void);
void sendAction(int button);

#endif