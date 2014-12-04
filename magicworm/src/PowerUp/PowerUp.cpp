#include <iostream>
#include <stdlib.h>
#include "PowerUp.h"
#include <ctime>
#include "../artifact/artifact.h"
#include "../gameboard/gameboard.h"
#include "../food/food.h"
#include "../snake/snake."

using namespace std;

PowerUp::PowerUp() {

}

void PowerUp::placePowerUp() {
	int powerupX = rand() % 100 + 1;
	int powerupY = rand() % 100 + 1;
	while ((powerupX == food.getX() && powerupY == food.getY()) ||
			(powerupX == snake.getX() && powerupY == snake.getY())){
		 powerupX = rand() % 100 + 1;
		 powerupY = rand() % 100 + 1;
	}

	int whichPowerUp = (rand() % 6);
	if (whichPowerUp == 0) {
		speedUp(powerupX, powerupY);
	}
	else if (whichPowerUp == 1) {
		slowDown(powerupX, powerupY);
	}
	else if (whichPowerUp == 2) {
		changeColor(powerupX, powerupY);
	}
	else if (whichPowerUp == 3) {
		extraFood(powerupX, powerupY);
	}
	else if (whichPowerUp == 4) {
		minusScore(powerupX, powerupY);
	}
	else if (whichPowerUp == 5) {
		invertDirections(powerupX, powerupY);
	}
	isPowerUp = true;
}

void PowerUp::removePowerUp() {
	isPowerUp = false;
}

void PowerUp::speedUp(int x, int y) {
	while (isPowerUp = true) {
		if (x = snake.getX() && y = snake.getY()) {
			speed +=3;
			clock_t startTime = clock();
			clock_t endTime;
			double timeInSeconds;
			while (timeInSeconds < 30) {
				endTime = clock();
				clock_t ticksTaken = startTime - endTime;
				timeInSeconds = ticksTaken / (double) CLOCKS_PER_SEC;
			}
			speed -=3;
			removePowerUp();
		}
	}
}

void PowerUp::slowDown(int x, int y) {
	while (isPowerUp = true) {
		if (x = snake.getX() && y = snake.getY()) {
			speed -=3;
			clock_t startTime = clock();
			clock_t endTime;
			double timeInSeconds;
			while (timeInSeconds < 30) {
				endTime = clock();
				clock_t ticksTaken = startTime - endTime;
				timeInSeconds = ticksTaken / (double) CLOCKS_PER_SEC;
			}
				speed +=3;
				removePowerUp();
		}
	}
}

void PowerUp::changeColor(int x, int y) {
	while (isPowerUp = true) {
		if (x = snake.getX() && y = snake.getY()) {
			int whichColor = rand() % 2;
			if (whichColor = 0) {

			}
		}
	}
}

void PowerUp::extraFood(int x, int y) {
	while (isPowerUp = true) {
		if (x = snake.getX() && y = snake.getY()) {
			generateFood();
			generateFood();
			removePowerUp();
		}
	}
}

void PowerUp::minusScore(int x, int y) {
	while (isPowerUp = true) {
		if (x = snake.getX() && y = snake.getY()) {
			score -=3;
			removePowerUp();
		}
	}
}

void PowerUp::invertDirections(int x, int y) {

}
