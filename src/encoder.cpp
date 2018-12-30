#include <Arduino.h>
#include "config.h"
#include "pins.h"

// 'threshold' is the Debounce Adjustment factor for the Rotary Encoder.
//
// The threshold value I'm using limits it to 100 half pulses a second
//
// My encoder has 12 pulses per 360deg rotation and the specs say
// it is rated at a maximum of 100rpm.
//
// This threshold will permit my encoder to reach 250rpm so if it was connected
// to a motor instead of a manually operated knob I
// might possibly need to adjust it to 25000. However, this threshold
// value is working perfectly for my situation
//
volatile unsigned long threshold = 10000;


// 'rotaryHalfSteps' is the counter of half-steps. The actual
// number of steps will be equal to rotaryHalfSteps / 2
//
volatile long rotaryHalfSteps = 0;


// Working variables for the interrupt routines
//
volatile unsigned long int0time = 0;
volatile unsigned long int1time = 0;
volatile uint8_t int0signal = 0;
volatile uint8_t int1signal = 0;
volatile uint8_t int0history = 0;
volatile uint8_t int1history = 0;

void doISRA()
{
  if ( micros() - int0time < threshold )
    return;
  int0history = int0signal;
  int0signal = bitRead(PIND, 1);
  if ( int0history == int0signal )
    return;
  int0time = micros();
  if ( int0signal == int1signal )
    rotaryHalfSteps++;
  else
    rotaryHalfSteps--;
}

void doISRB()
{
  if ( micros() - int1time < threshold )
    return;
  int1history = int1signal;
  int1signal = bitRead(PIND, 0);
  if ( int1history == int1signal )
    return;
  int1time = micros();
}

void encoderSetup(){
  //pinMode(ISR_A, INPUT);
  //pinMode(ISR_B, INPUT);
  
  digitalWrite(ISR_A, HIGH);
  digitalWrite(ISR_B, HIGH);


  attachInterrupt(0, doISRA, CHANGE);   // ISR in encoder.cpp
  attachInterrupt(1, doISRB, CHANGE);   // ISR in encoder.cpp
}

long encoderLoop(){
    return (rotaryHalfSteps / 2);
}