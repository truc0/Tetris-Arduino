/**
 * US -- Ultrasonic Sensor
 */

#ifndef US_h
#define US_h

class US {
	public:
		static bool init();
		static double detect(int delaySeconds=500);
};

#endif