#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include "PowerUp.h"
#include <ctime>
#include <time.h>
#include <SDL2/SDL.h>
#include "../commonSDL.h"

using namespace std;

PowerUp::PowerUp(SDL_Renderer * irenderer, Snake * isnake, Food * ifood) {
	powerUpX = -1;
	powerUpY = -1;
	isPowerUp = false;
	renderer = irenderer;
	snake = isnake;
	food = ifood;
	isSpedUp = false;
	isSlowedDown = false;
	startTime = 0;
	whichPowerUp = -1;
	speedCounter = 0;
	timeInSeconds = 0;
	isExtraFood = false;
	food1 = false;
	food2 = false;
	food1x = -1;
	food2x = -1;
	food1y = -1;
	food2y = -1;
	powerUpTimer = 0;
	isInverted = false;
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
	  if (timeInSeconds >= 0.5) {
			snake->setSpeed(snake->getSpeed() - 3);
			isSpedUp = false;
		}
	}

	if (isSlowedDown) {
		timeInSeconds = (clock() - startTime) / (double) CLOCKS_PER_SEC;
		if (timeInSeconds >= 0.5) {
			if (snake->getSpeed() == 1) {
				snake->setSpeed(1 + speedCounter);
			}
			else {
				snake->setSpeed(snake->getSpeed() + 3);
			}
			isSlowedDown = false;
		}
	}

	if (isExtraFood) {
		if (snake->getX() == food1x && snake->getY() == food1y) {
			food1 = false;
			cout << "eat food" << endl;
			snake->eat();
			food->raiseScore(1);
		}
		if (snake->getX() == food2x && snake->getY() == food2y) {
			food2 = false;
			cout << "eat food" << endl;
			snake->eat();
			food->raiseScore(1);
		}
		if (food1) {
			modifiedRenderFood(food1x, food1y);
		}
		if (food2) {
			modifiedRenderFood(food2x, food1y);
		}
		if (!food1 && !food2) {
			isExtraFood = false;
		}
	}
<<<<<<< HEAD

	if (isInverted) {
		//make the absolute value of vel negative
		timeInSeconds = (clock() - startTime) / (double) CLOCKS_PER_SEC;
		if (timeInSeconds >= 0.5) {
			isInverted = false;
		}
	}
}
=======
}

/*bool PowerUp::isTouching() {
	if((powerUpX == snake->getX() && (powerUpY == snake->getY() + 16 || powerUpY + 16 == snake->getY()) ||
			(powerUpY == snake->getY() && (powerUpX == snake->getX() + 16 || powerUpX + 16 == snake->getY()))
			|| ))
}*/
>>>>>>> Revert "fixed my mistakes pt 3"

/*bool PowerUp::isTouching() {
	if((powerUpX == snake->getX() && (powerUpY == snake->getY() + 16 || powerUpY + 16 == snake->getY()) ||
			(powerUpY == snake->getY() && (powerUpX == snake->getX() + 16 || powerUpX + 16 == snake->getY()))
			|| ))
}*/

void PowerUp::randomNumbers() {
	if (!isPowerUp) {
		powerUpTimer = clock();
		srand(time(NULL));
		whichPowerUp = (rand() % 6);
		powerUpX = rand() % SCREEN_WIDTH;
		powerUpY = rand() % SCREEN_HEIGHT;

<<<<<<< HEAD
<<<<<<< HEAD
		if (isTouching(powerUpX, powerUpY, snake->getX(), snake->getY()) || isTouching(powerUpX, powerUpY, food->getX(), food->getY())) {
=======
		if (powerUpX == snake->getX() && powerUpY == snake->getY()){
>>>>>>> origin/master
=======
		if (powerUpX == snake->getX() && powerUpY == snake->getY()){
>>>>>>> Revert "fixed my mistakes pt 3"
			randomNumbers();
		}
	}
}

void PowerUp::placePowerUp() {
	deactivatePowerUp();

	if (!isSpedUp && !isSlowedDown && !isExtraFood && !isInverted) {
		randomNumbers();

		isPowerUp = true;
		if (((clock() - powerUpTimer) / (double) CLOCKS_PER_SEC) >= .17) {
			isPowerUp = false;
		}

		if (whichPowerUp == 0) {
			const string speedUpPath = getResourcePath("magicworm") + "speedUp.bmp";
			SDL_Texture * speedUp = loadTexture(speedUpPath, renderer);
			if (speedUp == nullptr){
				SDL_Quit();
			}

			//SDL_RenderClear(renderer);
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
		speedCounter = snake->getSpeed() - 1;
		snake->setSpeed(1);
	}
}

void PowerUp::changeColor() {
	PowerUp::removePowerUp();
	srand(time(NULL));
	int whichColor = rand() % 2;
	if (whichColor == 0) {
		const string newImagePath = getResourcePath("magicworm") + "snake.bmp";
		//pass newImagePath into something
	}
	else if (whichColor == 1) {
		const string newImagePath = getResourcePath("magicworm") + "snake1.bmp";
		//pass newImagePath into something
	}
	else if (whichColor == 2) {
		const string newImagePath = getResourcePath("magicworm") + "snake2.bmp";
		//pass newImagePath into something
	}
}

void PowerUp::extraFood() {
	removePowerUp();
	isExtraFood = true;
	food1 = true;
	food2 = true;
	srand(time(NULL));
	food1x = rand() % SCREEN_WIDTH;
	food2x = rand() % SCREEN_WIDTH;
	food1y = rand() % SCREEN_HEIGHT;
	food2y = rand() % SCREEN_HEIGHT;
}

void PowerUp::modifiedRenderFood(int x, int y) {
	 const string cupcakePath = getResourcePath("magicworm") + "cupcake.bmp";
	 SDL_Texture * renderFood = loadTexture(cupcakePath, renderer);
	 if (renderFood == nullptr)
	   SDL_Quit();

	 //SDL_RenderClear(renderer);
	 renderTexture(renderFood, renderer, x, y);
	 SDL_RenderPresent(renderer);
}

void PowerUp::minusScore() {
	removePowerUp();
	food->raiseScore(-3);
}

void PowerUp::invertDirections() {
	removePowerUp();
	startTime = clock();
	isInverted = true;
}
