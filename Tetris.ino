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
const bool enableUS = false;

CRGB leds[NUM_LEDS];

double distance = 0.0;
bool isPaused = false;

long delays = 0;
short delay_ = 500;
long bdelay = 0;
short buttondelay = 150;
short btdowndelay = 30;
short btsidedelay = 80;
unsigned char blocktype;
unsigned char blockrotation;

int lines = 0;
bool  block[8][18]; //2 extra for rotation
bool  pile[8][16];
bool  disp[8][16];

bool lib[10][5][7];


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

void test() {
	for (int i=0; i<(NUM_LEDS)/8; ++i) {
		for (int j=0; j<8; ++j) {
			leds[i][j] = CRGB::Blue;
		}
		FastLED.show();
		for (int j=0; j<8; ++j) {
			leds[i][j] = CRGB::Black;
		}
		FastLED.show();
	}
}

void setup() {

	Serial.begin(9600);

	// init FastLED
	FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
	// init ultrasonic sensor
	if (enableUS) {
		bool started = US::init();
	}

	test();

	// init Buttons
	Buttons::init();

	// init threads
	PT_INIT(&M_US);
	PT_INIT(&M_Btn);

	newBlock();
}

void loop() {
	// mission_US(&M_US);
	// mission_Btn(&M_Btn);


  if (delays < millis())
   {
     delays = millis() + delay_;
     movedown();
   }

   //buttun actions
  int button = Buttons::detect();
  
  if (button == 1) //up=rotate
    rotate();
  if (button == 2) //right=moveright
    moveright();    
  if (button == 3) //left=moveleft
    moveleft();
  if (button == 4) //down=movedown
    movedown();  
  
  // Serial.print(analogRead(A4));
  // Serial.print(analogRead(A5));
  // Serial.print(analogRead(A6));  
  // Serial.println(analogRead(A7));
   
}
