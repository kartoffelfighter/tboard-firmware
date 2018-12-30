/*
* config for tboard
* (c) marc fischer (marc@marcfischer.org)
* 11-12-18
*/

#ifndef __config_h
#define __config_h

#define swap_rotary_encoder false // define, if rotary encoder turns in wrong direction
#define BAUDRATE 115200          // Baudrate for legacy serial connection

#define POLLRATE 125 // define poll rate of computer for usb devices in Hz

// possible keys: https://docs.microsoft.com/en-us/windows/desktop/inputdev/virtual-key-codes
// implemented in consumer-library: https://github.com/NicoHood/HID/wiki/Consumer-API
/*
#define MEDIA_FAST_FORWARD	0xB3
#define MEDIA_REWIND	0xB4
#define MEDIA_NEXT	0xB5
#define MEDIA_PREVIOUS	0xB6
#define MEDIA_STOP	0xB7
#define MEDIA_PLAY_PAUSE	0xCD

#define MEDIA_VOLUME_MUTE	0xE2
#define MEDIA_VOLUME_UP	0xE9
#define MEDIA_VOLUME_DOWN	0xEA

#define CONSUMER_EMAIL_READER	0x18A
#define CONSUMER_CALCULATOR	0x192
#define CONSUMER_EXPLORER	0x194

#define CONSUMER_BROWSER_HOME	0x223
#define CONSUMER_BROWSER_BACK	0x224
#define CONSUMER_BROWSER_FORWARD	0x225
#define CONSUMER_BROWSER_REFRESH	0x227
#define CONSUMER_BROWSER_BOOKMARKS	0x22A

*/

//#define KEY_F13 0x7C
//#define KEY_F14 0x7D
//#define KEY_F15 0x7E

#define mappedKey1 MEDIA_PAUSE
#define mappedKey2 MEDIA_PREVIOUS
#define mappedKey3 MEDIA_NEXT
#define mappedKey4 CONSUMER_CALCULATOR
#define mappedKey5 CONSUMER_CALCULATOR
#define mappedKey6 CONSUMER_CALCULATOR
#define mappedKey7 CONSUMER_CALCULATOR
#define mappedKey8 CONSUMER_CALCULATOR
#define mappedKey9 MEDIA_VOL_MUTE
#define mappedKeyRotLeft  MEDIA_VOLUME_UP
#define mappedKeyRotRight MEDIA_VOLUME_DOWN

#define NUM_LEDS 8 // amount of leds in strip

#endif