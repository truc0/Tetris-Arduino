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
int buttonController = 0;

static struct pt M_US, M_Btn;


long delays = 0;
short delay_ = 500;
long bdelay = 0;
short buttondelay = 150;
short btdowndelay = 30;
short btsidedelay = 80;
unsigned char blocktype;
unsigned char blockrotation;
void movedown();


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
	buttonController = Buttons::detect();
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


  if (delays < millis())
   {
     delays = millis() + delay_;
     movedown();
   }
  
  if (buttonController == 1) //up=rotate
    rotate();
  if (buttonController == 2) //right=moveright
    moveright();    
  if (buttonController == 3) //left=moveleft
    moveleft();
  if (buttonController == 4) //down=movedown
    movedown();  
  buttonController = 0;
  
  
  Serial.print(analogRead(A4));
  Serial.print(analogRead(A5));
  Serial.print(analogRead(A6));  
  Serial.println(analogRead(A7));
   
}
