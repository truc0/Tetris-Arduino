/**
 * Library
 */

// official
#include <FastLED.h>

// custom
#include "lib/US.h"
#include "lib/Buttons.h"

#define LED_PIN 6
#define NUM_LEDS 144
#define USTrig 2
#define USEcho 3

using namespace std;

// LED_TYPE = WS2812;
const bool enableUS = true;

CRGB leds[NUM_LEDS];

double distance = 0.0;
bool isPaused = false;

void setup() {
	// init FastLED
	FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
	// init ultrasonic sensor
	if (enableUS) {
		bool started = US::init();
	}

	// init Buttons
	Buttons::init();
}

void loop() {
	// distance = US::detect();
	
	// if (distance < 10 && isPaused) {
		// resume();
	// } else if (distance > 10 && !isPaused) {
		// pause();
	// }

	Buttons::detect();
}
