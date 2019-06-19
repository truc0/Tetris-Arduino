#include "lib/Buttons.h"

int pin_up = 4;
int pin_left = 5;
int pin_down = 6;
int pin_right = 7;
int state[100];
int prevState[100];


void Buttons::init()
{
	for (int i=0; i<100; ++i) {
		state[i] = 0;
		prevState[i] = 0;
	}

	pinMode(pin_up, INPUT_PULLUP);
	pinMode(pin_down, INPUT_PULLUP);
	pinMode(pin_left, INPUT_PULLUP);
	pinMode(pin_right, INPUT_PULLUP);
}

bool Buttons::detect_single(int port)
{
	state[port] = digitalRead(port);
	bool isSame = (state[port] == prevState[port]);

	// update
	prevState[port] = state[port];
	
	return !isSame;
}

int Buttons::detect()
{
	if (detect_single(pin_up) && state[pin_up]==HIGH) {
		return 1;
	}

	if (detect_single(pin_down) && state[pin_down]==HIGH) {
		return 4;
	}

	if (detect_single(pin_left) && state[pin_left]==HIGH) {
		return 3;
	}

	if (detect_single(pin_right) && state[pin_right]==HIGH) {
		return 2;
	}

	delay(100);
}