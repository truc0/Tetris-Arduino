/**
 * Pause and Resume functions uses ultrasonic
 * sensor
 * 
 * 
 */


#include "lib/US.h"

bool US::init()
{
	// init ultrasonic sensor

	if (!enableUS) return false;

	Serial.begin(9600);
	pinMode(USTrig, OUTPUT);
	pinMode(USEcho, INPUT);
	Serial.println("[INFO] ultrasonic sensor started.");

	return true;
}

double US::detect(int delaySeconds=500)
{
	// detect the distance

	double distance = 0.0;

	// make pulse
	digitalWrite(USTrig, LOW);
	delayMicroseconds(2);
	digitalWrite(USTrig, HIGH);
	delayMicroseconds(10);
	digitalWrite(USTrig, LOW);

	distance = pulseIn(USEcho, HIGH) / 58.00;
	delay(delaySeconds);

	return distance;
}
