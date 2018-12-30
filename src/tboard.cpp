//#include <Keyboard.h>
#include "tboard.h"
#include <HID.h>
#include <HID-Project.h>




volatile ConsumerKeycode mappedKeys[] = {mappedKey1, mappedKey2, mappedKey3, mappedKey4, mappedKey5, mappedKey6, mappedKey7, mappedKey8, mappedKey9, mappedKeyRotLeft, mappedKeyRotRight};

void keyboardSetup(){
    Consumer.begin();
}

void sendAction(int button){
    Consumer.write(mappedKeys[button]);
}
