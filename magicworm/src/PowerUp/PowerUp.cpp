#include <iostream>
#include <stdlib.h>
#include "PowerUp.h"
#include <ctime>
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
	if (isPowerUp = false) {
		int whichPowerUp = (rand() % 6);
		powerUpX = rand() % SCREEN_WIDTH;
		powerUpY = rand() % SCREEN_HEIGHT;

		while (powerUpX == snake->getX() && powerUpY == snake->getY()){
			powerUpX = rand() % SCREEN_WIDTH;
			powerUpY = rand() % SCREEN_HEIGHT;
		}
	}

	isPowerUp = true;

	//int whichPowerUp = 0;

	if (whichPowerUp == 0) {
		const string speedUpPath = getResourcePath("magicworm") + "speedUp.bmp";
		SDL_Texture * speedUp = loadTexture(speedUpPath, renderer);
			if (speedUp == nullptr){
				SDL_Quit();
			}
		cout << x << ", " << y << endl;
		SDL_RenderClear(renderer);
		renderTexture(speedUp, renderer, x, y);
		SDL_RenderPresent(renderer);

		if (powerUpX == snake->getX() && powerUpY == snake->getY()) {
			speedUp(powerUpX, powerUpY);
		}
	}
	else if (whichPowerUp == 1) {
		const string speedUpPath = getResourcePath("magicworm") + "slowDown.bmp";
		SDL_Texture * slowDown = loadTexture(slowDownPath, renderer);
			if (slowDown == nullptr){
				SDL_Quit();
			}
		cout << x << ", " << y << endl;
		SDL_RenderClear(renderer);
		renderTexture(slowDown, renderer, x, y);
		SDL_RenderPresent(renderer);
		if (powerUpX == snake->getX() && powerUpY == snake->getY()) {
			slowDown();
		}
	}
	else if (whichPowerUp == 2) {
		const string changeColor = getResourcePath("magicworm") + "changeColor.bmp";
		SDL_Texture * changeColor = loadTexture(changeColorPath, renderer);
			if (changeColor == nullptr){
				SDL_Quit();
			}
		cout << x << ", " << y << endl;
		SDL_RenderClear(renderer);
		renderTexture(changeColor, renderer, x, y);
		SDL_RenderPresent(renderer);
		if (powerUpX == snake->getX() && powerUpY == snake->getY()) {
			changeColor();
		}
	}
	else if (whichPowerUp == 3) {
		const string extraFoodPath = getResourcePath("magicworm") + "extraFood.bmp";
		SDL_Texture * extraFood = loadTexture(extraFoodPath, renderer);
		if (extraFood == nullptr){
				SDL_Quit();
			}
		cout << x << ", " << y << endl;
		SDL_RenderClear(renderer);
		renderTexture(extraFood, renderer, x, y);
		SDL_RenderPresent(renderer);
		if (powerUpX == snake->getX() && powerUpY == snake->getY()) {
			extraFood();
		}
	}
	else if (whichPowerUp == 4) {
		const string minusScorePath = getResourcePath("magicworm") + "minusScore.bmp";
		SDL_Texture * minusScore = loadTexture(minusScorePath, renderer);
			if (minusScore == nullptr){
				SDL_Quit();
			}
		cout << x << ", " << y << endl;
		SDL_RenderClear(renderer);
		renderTexture(minusScore, renderer, x, y);
		SDL_RenderPresent(renderer);
		if (powerUpX == snake->getX() && powerUpY == snake->getY()) {
			minusScore();
		}
	}
	else if (whichPowerUp == 5) {
		const string invertDirectionsPath = getResourcePath("magicworm") + "invertDirections.bmp";
		SDL_Texture * invertDirections = loadTexture(invertDirectionsPath, renderer);
			if (invertDirections == nullptr){
				SDL_Quit();
			}
		cout << x << ", " << y << endl;
		SDL_RenderClear(renderer);
		renderTexture(invertDirections, renderer, x, y);
		SDL_RenderPresent(renderer);
		if (powerUpX == snake->getX() && powerUpY == snake->getY()) {
			invertDirections();
		}
	}

}

void PowerUp::removePowerUp() {
	isPowerUp = false;
}

void PowerUp::speedUp() {
	removePowerUp();
	snake->setSpeed(snake->getSpeed() + 3);
	clock_t startTime = clock();
	clock_t endTime;
	double timeInSeconds = 0;
	/*while (timeInSeconds < 30) {
		endTime = clock();
		clock_t ticksTaken = startTime - endTime;
		timeInSeconds = ticksTaken / (double) CLOCKS_PER_SEC;
	}
	snake->setSpeed(snake->getSpeed() - 3);*/
}

void PowerUp::slowDown() {
		removePowerUp();
		snake->setSpeed(snake->getSpeed() - 3);
		clock_t startTime = clock();
		clock_t endTime;
		double timeInSeconds = 0;
		/*
		while (timeInSeconds < 30) {
			endTime = clock();
			clock_t ticksTaken = startTime - endTime;
			timeInSeconds = ticksTaken / (double) CLOCKS_PER_SEC;
		}
			snake->setSpeed(snake->getSpeed() + 3);
		*/
	}

void PowerUp::changeColor() {
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
