/*
* main loop for tboard
* (c) marc fischer (marc@marcfischer.org)
* 11-12-18
*/
#include <Arduino.h>
#include "pins.h"
#include "config.h"
#include "encoder.h"
#include "rgbleds.h"
#include "tboard.h"
#include "interface.h"

volatile uint_fast32_t prev_millis = 0;
volatile long actualRotaryTicks = 0;
volatile long rotBefore = 0;
volatile bool rotTurned = 0;
volatile int volChange = 0;
volatile bool volMinus = 0;

volatile int buttonRead[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
volatile int buttonLastRead[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
volatile int buttonSet[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
volatile int buttons[] = {SW1, SW2, SW3, SW4, SW5, SW6, SW7, SW8, SW9};

volatile int millisBeginRead = 0;
volatile int keyRecTook = 0;

void recogniceKeypress()
{
  millisBeginRead = millis();
  for (int i = 0; i <= 8; i++)
  {
    buttonRead[i] = digitalRead(buttons[i]);
  }
  delay(40);
  for (int i = 0; i <= 8; i++)
  {
    buttonLastRead[i] = buttonRead[i];
  }
  delay(40);
  for (int i = 0; i <= 8; i++)
  {
    buttonRead[i] = digitalRead(buttons[i]);
  }

  for (int i = 0; i <= 8; i++)
  {
    if (buttonLastRead[i] == buttonRead[i])
    {
      buttonSet[i] = buttonRead[i];
    }
    else
    {
      buttonSet[i] = 0;
    }
  }

  keyRecTook = millis() - millisBeginRead;
}

// ticky is called every poll time. define pollrate in config. default: 125Hz (8 times per Sec)
// no interrupt here
void ticky()
{
  //Serial.println("polling...");
  //Serial.print("runtime (s): ");
  //Serial.println(prev_millis/1000);
  //Serial.print("rotary ticks: ");
  //Serial.println(actualRotaryTicks);
  for (int i = 0; i <= 8; i++)
  {
    if (buttonSet[i])
    {
      Serial.print("SW");
      Serial.print(i);
      Serial.println(" gedrückt.");
      sendAction(i);
      ledShow(i, random(0,255),random(0,255),random(0,120)); // Augenkrebs
    }
  }
  if (rotTurned)
  {
    if (volMinus)
    {
      Serial.print("Verringere die Lautstärke um ");
      sendAction(9);
      //ledsShow(2);
    }
    else
    {
      Serial.print("erhöhe die Lautstärke um ");
      sendAction(10);
      //ledsShow(1);
    }
    Serial.println(volChange);
    rotTurned = false;
  }
  //Serial.print("recognition took [ms]: ");
  //Serial.println(keyRecTook);
}

void setup()
{
  keyboardSetup();
  Serial.begin(BAUDRATE);
  /*while (Serial.available() <= 0)
  {
    Serial.println("wait for input..");
    Serial.println("type any character");
    delay(1000);
  } */
  // wait for serial connection
  Serial.println("t.board connected");
  for (int i = 0; i <= 8; i++)
  {
    pinMode(buttons[i], INPUT);
    Serial.print("Set PinMode of SW");
    Serial.println(i + 1);
  }
  encoderSetup();
  ledsSetup();
}

void loop()
{
  if (millis() >= prev_millis + (1000 / POLLRATE))
  {
    ticky();
    prev_millis = millis();
  }
  actualRotaryTicks = encoderLoop();
  if (actualRotaryTicks != rotBefore)
  {                                                 // unterscheiden sich die Rotary Ticks von den Rotary Ticks zuvor?
    rotTurned = 1;                                  // setze Encoder gedreht auf true
    volChange = abs(actualRotaryTicks - rotBefore); // volume change ist die anzahl wie oft der VOL- bzw. VOL+ gesendet werden
    if (actualRotaryTicks <= rotBefore)
    {               // wenn die aktuellen rotary ticks kleiner sind als die rotary ticks zuvor,
      if(swap_rotary_encoder){
        volMinus = 0;
      } else{
        volMinus = 1; // setze volMinus zu true
      }
    }
    else
    {
      if(swap_rotary_encoder){
        volMinus = 1;
      } else{
        volMinus = 0; // setze volMinus zu false
      }
    }
    int rgbfader = map(volChange, 0, abs(actualRotaryTicks), 0, 7); // Augenkrebs
    ledShow(rgbfader, random(0,255), random(0,255), random(0,255)); // Augenkrebs
    rotBefore = actualRotaryTicks; // setze die rotator variable zurück
  }
  recogniceKeypress();
  if(Serial.available() > 0){
    check_for_serial_incoming();
  }
}