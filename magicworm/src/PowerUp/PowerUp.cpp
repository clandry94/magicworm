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

int PowerUp::getX() {
	return powerUpX;
}

int PowerUp::getY() {
	return powerUpY;
}

void PowerUp::placePowerUp() {
	int powerUpX = rand() % 100 + 1;
	int powerUpY = rand() % 100 + 1;
	while ((powerUpX == food.getX() && powerUpY == food.getY()) ||
			(powerUpX == snake.getX() && powerUpY == snake.getY())){
		 powerUpX = rand() % 100 + 1;
		 powerUpY = rand() % 100 + 1;
	}

	int whichPowerUp = (rand() % 6);
	if (whichPowerUp == 0) {
		speedUp(powerUpX, powerUpY);
	}
	else if (whichPowerUp == 1) {
		slowDown(powerUpX, powerUpY);
	}
	else if (whichPowerUp == 2) {
		changeColor(powerUpX, powerUpY);
	}
	else if (whichPowerUp == 3) {
		extraFood(powerUpX, powerUpY);
	}
	else if (whichPowerUp == 4) {
		minusScore(powerUpX, powerUpY);
	}
	else if (whichPowerUp == 5) {
		invertDirections(powerUpX, powerUpY);
	}
	isPowerUp = true;
}

void PowerUp::removePowerUp() {
	isPowerUp = false;
	powerUpX = -1;
	powerUpY = -1;
}

void PowerUp::speedUp(int x, int y) {
	while (isPowerUp = true) {
		if (x = snake.getX() && y = snake.getY()) {
			removePowerUp();
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
		}
	}
}

void PowerUp::slowDown(int x, int y) {
	while (isPowerUp = true) {
		if (x = snake.getX() && y = snake.getY()) {
			removePowerUp();
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
		}
	}
}

void PowerUp::changeColor(int x, int y) {
	while (isPowerUp = true) {
		if (x = snake.getX() && y = snake.getY()) {
			removePowerUp();
			int whichColor = rand() % 2;
			if (whichColor = 0) {
				//color =
			}
			else if (whichColor = 1) {
				//color =
			}
			else if (whichColor = 2) {
				//color =
			}
		}
	}
}

void PowerUp::extraFood(int x, int y) {
	while (isPowerUp = true) {
		if (x = snake.getX() && y = snake.getY()) {
			removePowerUp();
			food.generateFood();
			food.generateFood();
		}
	}
}

void PowerUp::minusScore(int x, int y) {
	while (isPowerUp = true) {
		if (x = snake.getX() && y = snake.getY()) {
			removePowerUp();
			score -=3;
		}
	}
}

void PowerUp::invertDirections(int x, int y) {
	while (isPowerUp = true) {
		if (x = snake.getX() && y = snake.getY()) {
			removePowerUp();

		}
	}
}
