#include <iostream>
#include <stdlib.h>
#include "PowerUp.h"
#include <ctime>
#include "../artifact/artifact.h"
#include "../food/food.h"
//#include "../snake/snake.cpp"
#include <SDL2/SDL.h>
#include "../commonSDL.h"

using namespace std;

PowerUp::PowerUp(SDL_Renderer * irenderer, Snake * isnake) {
	powerUpX = -1;
	powerUpY = -1;
	isPowerUp = false;
	renderer = irenderer;
	snake = isnake;
}

int PowerUp::getX() {
	return powerUpX;
}

int PowerUp::getY() {
	return powerUpY;
}

void PowerUp::placePowerUp() {
	powerUpX = rand() % SCREEN_WIDTH;
	powerUpY = rand() % SCREEN_HEIGHT;
	cout << "1" << endl;
	while (powerUpX == snake->getX() && powerUpY == snake->getY()){
		cout << "2" << endl;
		 powerUpX = rand() % SCREEN_WIDTH;
		 powerUpY = rand() % SCREEN_HEIGHT;
	}

	isPowerUp = true;
	//int whichPowerUp = (rand() % 6);
	int whichPowerUp = 0;
	if (whichPowerUp == 0) {
		cout << "3" << endl;
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
}

void PowerUp::removePowerUp() {
	isPowerUp = false;
	powerUpX = -1;
	powerUpY = -1;
}

void PowerUp::speedUp(int x, int y) {
	cout << "4" << endl;

		cout << "5" << endl;
		const string speedUpPath = getResourcePath("magicworm") + "speedUp.bmp";
		cout << "6" << endl;
		SDL_Texture * speedUp = loadTexture(speedUpPath, renderer);
		cout << "7" << endl;
			if (speedUp == nullptr){
				SDL_Quit();
			}
		cout << x << ", " << y << endl;
		SDL_RenderClear(renderer);
		renderTexture(speedUp, renderer, x, y);
		SDL_RenderPresent(renderer);
		cout << "8" << endl;
		/*
while (isPowerUp) {
		if (x == snake->getX() && y == snake->getY()) {
			removePowerUp();
			snake->setSpeed(snake->getSpeed() + 3);
			clock_t startTime = clock();
			clock_t endTime;
			double timeInSeconds = 0;
			while (timeInSeconds < 30) {
				endTime = clock();
				clock_t ticksTaken = startTime - endTime;
				timeInSeconds = ticksTaken / (double) CLOCKS_PER_SEC;
			}
			snake->setSpeed(snake->getSpeed() - 3);
		}
	}
	*/
}

void PowerUp::slowDown(int x, int y) {
	while (isPowerUp) {
		const string slowDownPath = getResourcePath("magicworm") + "slowDown.bmp";
			SDL_Texture * slowDown = loadTexture(slowDownPath, renderer);
				if (slowDown == nullptr){
					SDL_Quit();
				}
		renderTexture(slowDown, renderer, x, y);

		if (x == snake->getX() && y == snake->getY()) {
			removePowerUp();
			snake->setSpeed(snake->getSpeed() - 3);
			clock_t startTime = clock();
			clock_t endTime;
			double timeInSeconds = 0;
			while (timeInSeconds < 30) {
				endTime = clock();
				clock_t ticksTaken = startTime - endTime;
				timeInSeconds = ticksTaken / (double) CLOCKS_PER_SEC;
			}
				snake->setSpeed(snake->getSpeed() + 3);
		}
	}
}

void PowerUp::changeColor(int x, int y) {
	while (isPowerUp) {
		const string changeColorPath = getResourcePath("magicworm") + "changeColor.bmp";
			SDL_Texture * changeColor = loadTexture(changeColorPath, renderer);
				if (changeColor == nullptr){
					SDL_Quit();
				}
		renderTexture(changeColor, renderer, x, y);
		if (x == snake->getX() && y == snake->getY()) {
			removePowerUp();
			int whichColor = rand() % 2;
			if (whichColor == 0) {
				//color =
			}
			else if (whichColor == 1) {
				//color =
			}
			else if (whichColor == 2) {
				//color =
			}
		}
	}
}

void PowerUp::extraFood(int x, int y) {
	while (isPowerUp) {
		const string extraFoodPath = getResourcePath("magicworm") + "extraFood.bmp";
			SDL_Texture * extraFood = loadTexture(extraFoodPath, renderer);
				if (extraFood == nullptr){
					SDL_Quit();
				}
		renderTexture(extraFood, renderer, x, y);
		if (x == snake->getX() && y == snake->getY()) {
			removePowerUp();
			//food.generateFood();
			//food.generateFood();
		}
	}
}

void PowerUp::minusScore(int x, int y) {
	while (isPowerUp) {
		const string minusScorePath = getResourcePath("magicworm") + "minusScore.bmp";
			SDL_Texture * minusScore = loadTexture(minusScorePath, renderer);
				if (minusScore == nullptr){
					SDL_Quit();
				}
		renderTexture(minusScore, renderer, x, y);
		if (x == snake->getX() && y == snake->getY()) {
			removePowerUp();
			//score -=3;
		}
	}
}

void PowerUp::invertDirections(int x, int y) {
	while (isPowerUp) {
		const string invertDirectionsPath = getResourcePath("magicworm") + "invertDirections.bmp";
			SDL_Texture * invertDirections = loadTexture(invertDirectionsPath, renderer);
				if (invertDirections == nullptr){
					SDL_Quit();
				}
		renderTexture(invertDirections, renderer, x, y);
		if (x == snake->getX() && y == snake->getY()) {
			removePowerUp();

		}
	}
}
