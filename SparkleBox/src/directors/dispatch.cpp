#include "dispatch.h"

// working variables
uint32_t frameNumber = 0;
uint8_t selectedDirector = 0;


void setupDirectors () {

  loadDataFromEEPROM();

  // Start by blacking all POSSIBLE leds.
  fill_solid(globalLeds.leds, MAX_LEDS, CRGB(0,0,0));
  fill_solid(globalLeds.sceneWorkingLeds, MAX_LEDS, CRGB(0,0,0));
  fill_solid(globalLeds.patternWorkingLeds, MAX_LEDS, CRGB(0,0,0));


  /*
  Here's how I set up two led strips in FastLED from 
  one array of pixel data before... I'm trying to replicate this now.

  CRGB bigLedArray[10];

  FastLED.addLeds<LED_TYPE, 15>(&bigLedArray[0], 5);
  FastLED.addLeds<LED_TYPE, 2>(&bigLedArray[5], 5);

  while (true) {
    fill_solid(&bigLedArray[0], 5, CRGB(0,0,0));
    fill_solid(&bigLedArray[5], 5, CRGB(0,0,0));
    FastLED.show();
    delay(300);

    fill_solid(&bigLedArray[0], 5, CRGB(0,255,0)); // one strip on pin 15 blinks green
    fill_solid(&bigLedArray[5], 5, CRGB(0,0,255)); // the other strip on pin 2 blinks red
    FastLED.show();
    delay(300);
  }
  */


  // TODO call the setup function for each director.
}


void dispatchDirector () {
  frameNumber++;

  // set all leds to black.
  blackAllLeds();

  // fill_solid(globalLeds.leds, globalLeds.num_leds_configured, CRGB(0,0,0));

  switch (selectedDirector) {
    case 0:
      //tickSimpleDirector(leds, numberOfLeds, frameNumber);
      // TODO - figure out struct syntax
       tickSimpleDirector(frameNumber);
      break;
    default:
      Serial.println("Woah!! we don't have a valid director selected!");
      break;
  }

  // TODO - dalay here until 1/30 of a second has gone by.
  FastLED.show();
}


/*

scenes = [
    {
        name: "Under the Sea"
        patterns: [
            {
                id: 5,
                opacity: .75,
                blending_thingy: ? maybe we want to tell this something about how to blend the layers in here? 
                setting_A: 123, // float
                setting_B: 123, // float
                setting_C: 123, // float
                setting_D: 123, // float
                setting_E: 123, // float
            },
            { ... },
            { ... },
            { ... },
        ]
    }
]

get_scene_spec (scene_id) {
    return scenes[scene_id]
}

*/