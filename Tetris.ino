/**
 * Library
 */

// official
#include <FastLED.h>

// custom
#include "lib/US.h"
#include "lib/Buttons.h"
#include "lib/pt/pt.h"

#define LED_PIN 10
#define NUM_LEDS 144
#define USTrig 2
#define USEcho 3

using namespace std;

// LED_TYPE = WS2812;
const bool enableUS = true;

CRGB leds[NUM_LEDS];

double distance = 0.0;
bool isPaused = false;


static struct pt M_US, M_Btn;

// define missons
static int mission_US(struct pt *pt)
{
	PT_BEGIN(pt);
	distance = US::detect();
	
	if (distance < 10 && isPaused) {
		resume();
	} else if (distance > 10 && !isPaused) {
		pause();
	}
	PT_END(pt);
}

static int mission_Btn(struct pt *pt)
{
	PT_BEGIN(pt);
	Buttons::detect();
	PT_END(pt);
}

void setup() {
	// init FastLED
	FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
	// init ultrasonic sensor
	if (enableUS) {
		bool started = US::init();
	}

	// init Buttons
	Buttons::init();

	// init threads
	PT_INIT(&M_US);
	PT_INIT(&M_Btn);
}

void loop() {
	// mission_US(&M_US);
	mission_Btn(&M_Btn);
}
