/**
 * Game Class
 * Author: Bill Chung (truco)
 */

#include "lib/Game.h"

// #include <iostream>
#include <cstdio>

Game::Game(row=18, col=8)
{
	this.row = row;
	this.col = col;

	// clear game area
	for (int i=0; i<row; ++i) {
		for (int j=0; j<col; ++j) {
			area[i][j] = 0;
		}
	}
}

void Game::debug(option="print")
{
	switch (option) {
		case "print":
			for (int i=0; i<this.row; ++i) {
				for (int j=0; j<this.col; ++j) {
					printf("%d", this.area[i][j]);
				}
				printf("\n");
			}
			break;

		default:
			// do nothing
			break;
	}

	return ;
}

bool Game::tick()
{
	bool isCrashed = false;

	for (int i=0; i<4; ++i) {
		if (crashed(this.next[i])) {
			isCrashed = true;
		}
	}

	if (!isCrashed) {
		for (int i=0; i<4; ++i) {
			next[i][1]++;
		}
		return true;
	} else {
		if (!this.endGame()) {
			this.generate();
		}
	}
}