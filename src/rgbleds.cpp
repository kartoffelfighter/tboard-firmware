#include "rgbleds.h"

CRGB leds[NUM_LEDS];

void ledsSetup()
{ // define LEDs style here (change WS2812, GRB (to RGB, BGR etc))
    FastLED.addLeds<WS2812, RGB_PIN, GRB>(leds, NUM_LEDS);
    for (int i = 0; i < NUM_LEDS - 1; i++)
    {
        leds[i] = 0x000000;
    }
    FastLED.show();
    for (int i = 0; i < NUM_LEDS - 1; i++)
    {
        leds[i].r = i * 32;
        leds[i].g = i * 16;
        leds[i].b = i * 8;
        FastLED.show();
        delay(150);
    }
    for (int i = 0; i < NUM_LEDS - 1; i++)
    {
        leds[i] = 0x000000;
    }
    FastLED.show();
}

void ledsShow(int showID)
{
    switch (showID)
    {
    default:
    case 1:
        for (int i = 0; i < NUM_LEDS - 1; i++)
        {
            leds[i] = 0xFF0000;
        }
        break;
    case 2:
        for (int i = 0; i < NUM_LEDS - 1; i++)
        {
            leds[i] = 0x000000;
        }
        break;
    }
    FastLED.show();
}

void ledShow(int num, int ledR, int ledG, int ledB)
{
    leds[num].r = ledR;
    leds[num].g = ledG;
    leds[num].b = ledB;
    FastLED.show();
}