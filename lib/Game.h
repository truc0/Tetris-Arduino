/**
 * Tetris Game file
 */

#ifndef Game_h
#define Game_h

#include <FastLED.h>

class Game {
	public:
		Game(row=16, col=8);
		void debug(option="print");
		bool tick();
		void generate();

	private:
		int row, col;
		int next[4][2];
		// CRGB color;
		int area[20][20];
}

#endif