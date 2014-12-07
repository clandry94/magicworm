#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include "PowerUp.h"
#include <ctime>
#include <time.h>
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
	isSpedUp = false;
	isSlowedDown = false;
	startTime = 0;
	whichPowerUp = -1;
	counter = 0;
	timeInSeconds = 0;
}

int PowerUp::getX() {
	return powerUpX;
}

int PowerUp::getY() {
	return powerUpY;
}

void PowerUp::deactivatePowerUp() {
	if (isSpedUp) {
	  timeInSeconds = (clock() - startTime) / (double) CLOCKS_PER_SEC;
	  if (timeInSeconds >= 1.5) {
			snake->setSpeed(snake->getSpeed() - 3);
			isSpedUp = false;
		}
	}

	if (isSlowedDown) {
		timeInSeconds = (clock() - startTime) / (double) CLOCKS_PER_SEC;
		if (timeInSeconds >= 1.5) {
			if (snake->getSpeed() == 1) {
				snake->setSpeed(1 + counter);
			}
			else {
				snake->setSpeed(snake->getSpeed() + 3);
				isSlowedDown = false;
			}
		}
	}
}

/*bool PowerUp::isTouching() {
	if((powerUpX == snake->getX() && (powerUpY == snake->getY() + 16 || powerUpY + 16 == snake->getY()) ||
			(powerUpY == snake->getY() && (powerUpX == snake->getX() + 16 || powerUpX + 16 == snake->getY()))
			|| ))
}*/

void PowerUp::randomNumbers() {
	if (!isPowerUp) {
		srand(time(NULL));
		whichPowerUp = (rand() % 6);
		powerUpX = rand() % SCREEN_WIDTH;
		powerUpY = rand() % SCREEN_HEIGHT;

		if (powerUpX == snake->getX() && powerUpY == snake->getY()){
			randomNumbers();
		}
	}
}

void PowerUp::placePowerUp() {
	deactivatePowerUp();

	if (!isSpedUp && !isSlowedDown) {
		randomNumbers();

		isPowerUp = true;

		if (whichPowerUp == 0) {
			const string speedUpPath = getResourcePath("magicworm") + "speedUp.bmp";
			SDL_Texture * speedUp = loadTexture(speedUpPath, renderer);
			if (speedUp == nullptr){
				SDL_Quit();
			}

			SDL_RenderClear(renderer);
			renderTexture(speedUp, renderer, powerUpX,powerUpY);
			SDL_RenderPresent(renderer);

			if (powerUpX == snake->getX() && powerUpY == snake->getY()) {
				PowerUp::speedUp();
			}
		}
		else if (whichPowerUp == 1) {
			const string slowDownPath = getResourcePath("magicworm") + "slowDown.bmp";
			SDL_Texture * slowDown = loadTexture(slowDownPath, renderer);
				if (slowDown == nullptr){
					SDL_Quit();
				}

			SDL_RenderClear(renderer);
			renderTexture(slowDown, renderer, powerUpX,powerUpY);
			SDL_RenderPresent(renderer);
			if (powerUpX == snake->getX() && powerUpY == snake->getY()) {
				PowerUp::slowDown();
			}
		}
		else if (whichPowerUp == 2) {
			const string changeColorPath = getResourcePath("magicworm") + "changeColor.bmp";
			SDL_Texture * changeColor = loadTexture(changeColorPath, renderer);
				if (changeColor == nullptr){
					SDL_Quit();
				}

			SDL_RenderClear(renderer);
			renderTexture(changeColor, renderer,powerUpX,powerUpY);
			SDL_RenderPresent(renderer);
			if (powerUpX == snake->getX() && powerUpY == snake->getY()) {
				PowerUp::changeColor();
			}
		}
		else if (whichPowerUp == 3) {
			const string extraFoodPath = getResourcePath("magicworm") + "extraFood.bmp";
			SDL_Texture * extraFood = loadTexture(extraFoodPath, renderer);
			if (extraFood == nullptr){
					SDL_Quit();
				}

			SDL_RenderClear(renderer);
			renderTexture(extraFood, renderer,powerUpX,powerUpY);
			SDL_RenderPresent(renderer);
			if (powerUpX == snake->getX() && powerUpY == snake->getY()) {
				PowerUp::extraFood();
			}
		}
		else if (whichPowerUp == 4) {
			const string minusScorePath = getResourcePath("magicworm") + "minusScore.bmp";
			SDL_Texture * minusScore = loadTexture(minusScorePath, renderer);
				if (minusScore == nullptr){
					SDL_Quit();
				}

			SDL_RenderClear(renderer);
			renderTexture(minusScore, renderer,powerUpX,powerUpY);
			SDL_RenderPresent(renderer);
			if (powerUpX == snake->getX() && powerUpY == snake->getY()) {
				PowerUp::minusScore();
			}
		}
		else if (whichPowerUp == 5) {
			const string invertDirectionsPath = getResourcePath("magicworm") + "invertDirections.bmp";
			SDL_Texture * invertDirections = loadTexture(invertDirectionsPath, renderer);
				if (invertDirections == nullptr){
					SDL_Quit();
				}

			SDL_RenderClear(renderer);
			renderTexture(invertDirections, renderer,powerUpX,powerUpY);
			SDL_RenderPresent(renderer);
			if (powerUpX == snake->getX() && powerUpY == snake->getY()) {
				PowerUp::invertDirections();
			}
		}
	}
}

void PowerUp::removePowerUp() {
	isPowerUp = false;
}

void PowerUp::speedUp() {
	startTime = clock();
	isSpedUp = true;
	PowerUp::removePowerUp();
	snake->setSpeed(snake->getSpeed() + 3);

}

void PowerUp::slowDown() {
	startTime = clock();
	isSlowedDown = true;
	PowerUp::removePowerUp();
	if (snake->getSpeed() > 3) {
		snake->setSpeed(snake->getSpeed() - 3);
	}
	else if (snake->getSpeed() <=3) {
		counter = snake->getSpeed() - 1;
		snake->setSpeed(1);
	}
}

void PowerUp::changeColor() {
	PowerUp::removePowerUp();
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

void PowerUp::extraFood() {
	removePowerUp();
	//food.generateFood();
	//food.generateFood();
}

void PowerUp::minusScore() {
	removePowerUp();
	//score -=3;
}

void PowerUp::invertDirections() {
	removePowerUp();
}
