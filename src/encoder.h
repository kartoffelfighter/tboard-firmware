// header file for encoder.cpp

#ifndef __encoder_h
    #define __encoder_h

void encoderSetup();
    // declare function
    // does setup for encoder
    // reads the initial value when booting
    // no returns

void doISRA(void); 
    // declare function
    // returns nothing, modifies a global


void doISRB(void);
    // declare function
    // returns nothing, modifies a global

long encoderLoop(void);


#endif
