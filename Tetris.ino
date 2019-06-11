#include <FastLED.h>
#define LED_PIN 6
#define NUM_LEDS 144

// LED_TYPE = WS2812;

CRGB leds[NUM_LEDS];

void setup() {
	FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
}
