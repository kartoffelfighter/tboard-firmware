/*
* pin config for tboard
* (c) marc fischer (marc@marcfischer.org)
* 11-12-18
*/

// legacy pin config

/*
*   /o---- ----- ----- ----- ------o\
*   | SW1   SW2   SW3   SW4         |
*   |----- ----- ----- -----SW9 + RE ) 
*   | SW5   SW6   SW7   SW8         |
*   \o---- ----- ----- ----- ------o/
*
*/

#ifndef __pin_config_h // prevent double inclusion
#define __pin_config_h

#define SW1 12
#define SW2 10
#define SW3 8
#define SW4 6
#define SW5 11
#define SW6 9
#define SW7 7
#define SW8 5
#define SW9 4
#define RGB_PIN 13
#define ISR_A 2 //PD 1
#define ISR_B 3 //PD 0

#define CS1 A3
#define CS2 A4
#define CS3 A5

#endif