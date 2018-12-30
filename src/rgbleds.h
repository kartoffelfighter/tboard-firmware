#ifndef __rgbleds_h
#define __rgbleds_h

#include "config.h"
#include "pins.h"
#include <FastLED.h>

void ledsSetup(void);
// setup

void ledsShow(int showID);
// play show n

void ledShow(int num, int ledR, int ledG, int ledB);
//led num, ledR, ledG, ledB
#endif