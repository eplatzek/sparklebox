#ifndef GLOBALS_H
  #define GLOBALS_H

  // FastLED
  #define FASTLED_ALLOW_INTERRUPTS 0
  #include "FastLED.h"
  FASTLED_USING_NAMESPACE

  // Arduino
  #include "Arduino.h"

  // Pixel and Microcontroller settings
  #define DATA_PIN 3
  #define LED_TYPE WS2812B
  #define MAX_STRIPS 30
  #define MAX_LEDS 3000

  // Structs
  typedef struct {
    uint16_t numberOfStrips;
    uint16_t numberOfLedsInStrip[MAX_STRIPS];
    uint16_t ledOffsetForStrip[MAX_STRIPS];
    uint16_t pinNumberForStrip[MAX_STRIPS];
    uint16_t totalNumberOfLeds;
    CRGB leds[MAX_LEDS];
    CRGB sceneWorkingLeds[MAX_LEDS];
    CRGB patternWorkingLeds[MAX_LEDS];
  } led_struct_t;

  // globals variables
  extern led_struct_t globalLeds;
  // TODO - set up a new struct and global variable to store current
  // scene info (with director overrides)

#endif