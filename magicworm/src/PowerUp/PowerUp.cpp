#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include "PowerUp.h"
#include <ctime>
#include <time.h>
#include <math.h>
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
	isInvertedX = false;
	isInvertedY = false;
}

//returns x coordinate of the upper-left pixel of the power up
int PowerUp::getX() {
	return powerUpX;
}

//returns y coordinate of the upper-left pixel of the power up
int PowerUp::getY() {
	return powerUpY;
}

//keeps power ups running until their time is up
void PowerUp::deactivatePowerUp() {
	//if the speedUp power up is in effect
	if (isSpedUp) {
		//wait unitl ~30 secs have passed
		timeInSeconds = (clock() - startTime) / (double) CLOCKS_PER_SEC;
		if (timeInSeconds >= 0.5) {
			//return the speed back to normal and turn off the power up
			snake->setSpeed(snake->getSpeed() - 3);
			isSpedUp = false;
		}
	}
	
	//if the slowDown power up is in effect
	if (isSlowedDown) {
		//wait until ~30 secs have passed
		timeInSeconds = (clock() - startTime) / (double) CLOCKS_PER_SEC;
		if (timeInSeconds >= 0.5) {
			//return the speed back to normal and turn off the power up
			snake->setSpeed(snake->getSpeed() + 3);
			isSlowedDown = false;
		}
	}

	// if the extraFood power up is in effect
	if (isExtraFood) {
		if (isTouching(food1x, food1y, snake->getX(), snake->getY())) {
			//if the worm touches the first of the extra foods then eat it and turn that food off
			food1 = false;
			cout << food->getScore() << endl;
			snake->eat();
			food->raiseScore(1);
		}
		if (isTouching(food2x, food2y, snake->getX(), snake->getY())) {
			//same for the second extra food
			food2 = false;
			cout << food->getScore() << endl;
			snake->eat();
			food->raiseScore(1);
		}
		if (food1) {
			//if the first extra food is on then draw it
			modifiedRenderFood(food1x, food1y);
		}
		if (food2) {
			//if the second extra food is on then draw it
			modifiedRenderFood(food2x, food2y);
		}
		if (!food1 && !food2) {
			//if both foods are off then turn the power up off
			isExtraFood = false;
		}
	}
	
	//if the invertDirections power up is in effect
	if (isInverted) {
		//wait until ~30 secs have passed
		timeInSeconds = (clock() - startTime) / (double) CLOCKS_PER_SEC;
		if (timeInSeconds >= 0.5) {
			//turn off the power up
			isInverted = false;
		}
		if (isInvertedX) {
			//if the X direction is inverted then prevent the worm from moving to the right
			snake->setX_Vel(abs(snake->getX_Vel()) * -1);
		}
		else if (isInvertedY) {
			//if the Y direction is inverted then prevent the worm from moving upwards
			snake->setY_Vel(abs(snake->getY_Vel()) * -1);
		}
		if (!isInverted) {
			//once the power up is off, turn off both inversions
			isInvertedX = false;
			isInvertedY = false;
		}
	}
}

//determine if two objects (food, worm, or a power up) are touching 
//insert the coordinates of the upper-left pixel of each object
bool PowerUp::isTouching(int x1, int y1, int x2, int y2) {
	//start with all collisions being false
	bool leftCollision = false;
	bool rightCollision = false;
	bool topCollision = false;
	bool bottomCollision = false;

	//if two things are touching then the bottom of one is at the same height or below the top of the other
	if (y1 + 16 >= y2) {
		topCollision = true;
	}
	//if two things are touching then the top of one is at the same height or above the bottom of the other
	if (y1 <= y2 + 16) {
		bottomCollision = true;
	}
	//if two things are touching then the right of one is at the same length or to the right of the left of the other
	if (x1 + 16 >= x2) {
		leftCollision = true;
	}
	//if two things are touching then the left one is at the same length or to the left of the right side of the other
	if (x1 <= x2 + 16) {
		rightCollision = true;
	}
	//if all are true then there is a collision
	if (topCollision && bottomCollision && leftCollision && rightCollision) {
		return true;
	}
	//otherwise they are not touching
	else {
		return false;
	}
}

//this generates a random number between 0 and 5 in order to determing which power up to display
//it also randomly determines a set of corrdinates within the game screen and repicks the coordinates if
//there is already a food or power up at that spot
void PowerUp::randomNumbers() {
	if (!isPowerUp) {
		powerUpTimer = clock();
		srand(time(NULL));
		whichPowerUp = (rand() % 6);
		powerUpX = rand() % (SCREEN_WIDTH - 16);
		powerUpY = rand() % (SCREEN_HEIGHT - 16);

		if (isTouching(powerUpX, powerUpY, snake->getX(), snake->getY()) || isTouching(powerUpX, powerUpY, food->getX(), food->getY())) {
			randomNumbers();
		}
	}
}

//draw the randomly chosen power up
void PowerUp::placePowerUp() {
	//check to see if any power ups are still running
	deactivatePowerUp();
	
	//if there is not one running then continue
	if (!isSpedUp && !isSlowedDown && !isExtraFood && !isInverted) {
		//pick a new power up and set of coordinates but only if there isn't a power up already drawn
		randomNumbers();
		
		//mark that a power up is being drawn
		isPowerUp = true;
		
		//reset the power up and location about every 10 seconds
		if (((clock() - powerUpTimer) / (double) CLOCKS_PER_SEC) >= .17) {
			isPowerUp = false;
		}
		
		//if the 0th power up is chosen
		if (whichPowerUp == 0) {
			//draw the speed up symbol
			const string speedUpPath = getResourcePath("magicworm") + "speedUp.bmp";
			SDL_Texture * speedUp = loadTexture(speedUpPath, renderer);
			if (speedUp == nullptr){
				SDL_Quit();
			}

			//SDL_RenderClear(renderer);
			renderTexture(speedUp, renderer, powerUpX,powerUpY);
			SDL_RenderPresent(renderer);

			//once the worm touches the symbol, activate the speed up power up
			if (isTouching(powerUpX, powerUpY, snake->getX(), snake->getY())) {
				PowerUp::speedUp();
			}
		}
		//repeat for each type of power up
		else if (whichPowerUp == 1) {
			const string slowDownPath = getResourcePath("magicworm") + "slowDown.bmp";
			SDL_Texture * slowDown = loadTexture(slowDownPath, renderer);
				if (slowDown == nullptr){
					SDL_Quit();
				}

			//SDL_RenderClear(renderer);
			renderTexture(slowDown, renderer, powerUpX,powerUpY);
			SDL_RenderPresent(renderer);
			if (isTouching(powerUpX, powerUpY, snake->getX(), snake->getY())) {
				PowerUp::slowDown();
			}
		}
		else if (whichPowerUp == 2) {
			const string changeColorPath = getResourcePath("magicworm") + "changeColor.bmp";
			SDL_Texture * changeColor = loadTexture(changeColorPath, renderer);
				if (changeColor == nullptr){
					SDL_Quit();
				}

			//SDL_RenderClear(renderer);
			renderTexture(changeColor, renderer,powerUpX,powerUpY);
			SDL_RenderPresent(renderer);
			if (isTouching(powerUpX, powerUpY, snake->getX(), snake->getY())) {
				PowerUp::changeColor();
			}
		}
		else if (whichPowerUp == 3) {
			const string extraFoodPath = getResourcePath("magicworm") + "extraFood.bmp";
			SDL_Texture * extraFood = loadTexture(extraFoodPath, renderer);
			if (extraFood == nullptr){
					SDL_Quit();
				}

			//SDL_RenderClear(renderer);
			renderTexture(extraFood, renderer,powerUpX,powerUpY);
			SDL_RenderPresent(renderer);
			if (isTouching(powerUpX, powerUpY, snake->getX(), snake->getY())) {
				PowerUp::extraFood();
			}
		}
		else if (whichPowerUp == 4) {
			const string minusScorePath = getResourcePath("magicworm") + "minusScore.bmp";
			SDL_Texture * minusScore = loadTexture(minusScorePath, renderer);
				if (minusScore == nullptr){
					SDL_Quit();
				}

			//SDL_RenderClear(renderer);
			renderTexture(minusScore, renderer,powerUpX,powerUpY);
			SDL_RenderPresent(renderer);
			if (isTouching(powerUpX, powerUpY, snake->getX(), snake->getY())) {
				PowerUp::minusScore();
			}
		}
		else if (whichPowerUp == 5) {
			const string invertDirectionsPath = getResourcePath("magicworm") + "invertDirections.bmp";
			SDL_Texture * invertDirections = loadTexture(invertDirectionsPath, renderer);
				if (invertDirections == nullptr){
					SDL_Quit();
				}

			//SDL_RenderClear(renderer);
			renderTexture(invertDirections, renderer,powerUpX,powerUpY);
			SDL_RenderPresent(renderer);
			if (isTouching(powerUpX, powerUpY, snake->getX(), snake->getY())) {
				PowerUp::invertDirections();
			}
		}
	}
}

//mark that there is no power up currently being drawn
void PowerUp::removePowerUp() {
	isPowerUp = false;
}

//mark the start time for keeping track of the power up duration, turn on the speedUp power up,
//mark that there is no power up currently being drawn, and increase the worm's speed by 3 
void PowerUp::speedUp() {
	startTime = clock();
	isSpedUp = true;
	PowerUp::removePowerUp();
	snake->setSpeed(snake->getSpeed() + 3);

}

//mark the start time for keeping track of the power up duration, turn on the slowDown power up,
//mark that there is no power up currently being drawn, and decrease the worm's speed by 3, 
//but makes sure the speed is greater than zero
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

//mark that there is no power up currently being drawn, change the color of the worm to a random one
//by changing which image is used to draw the worm
void PowerUp::changeColor() {
	PowerUp::removePowerUp();
	srand(time(NULL));
	int whichColor = rand() % 3;
	if (whichColor == 0) {
		string newImagePath = getResourcePath("magicworm") + "snake.bmp";
		snake->setTexture(newImagePath);
	}
	else if (whichColor == 1) {
		string newImagePath = getResourcePath("magicworm") + "snake1.bmp";
		snake->setTexture(newImagePath);
	}
	else if (whichColor == 2) {
		string newImagePath = getResourcePath("magicworm") + "snake2.bmp";
		snake->setTexture(newImagePath);
	}
}

//mark that there is no power up currently being drawn, turn on the extraFood power up, mark that both foods 
//are on, come up with coordinates for both of the extra foods
void PowerUp::extraFood() {
	removePowerUp();
	isExtraFood = true;
	food1 = true;
	food2 = true;
	srand(time(NULL));
	PowerUp::randomNumbers();
	food1x = powerUpX;
	food1y = powerUpY;
	srand(time(NULL));
	PowerUp::randomNumbers();
	food2x = powerUpX;
	food2y = powerUpY;
}

//create food icons at the newly determined locations
void PowerUp::modifiedRenderFood(int x, int y) {
	 const string cupcakePath = getResourcePath("magicworm") + "cupcake.bmp";
	 SDL_Texture * renderFood = loadTexture(cupcakePath, renderer);
	 if (renderFood == nullptr)
	   SDL_Quit();

	 //SDL_RenderClear(renderer);
	 renderTexture(renderFood, renderer, x, y);
	 SDL_RenderPresent(renderer);
}

//mark that there is no longer a power up currently being drawn and reduce the score by 3
void PowerUp::minusScore() {
	removePowerUp();
	food->raiseScore(-3);
}

//mark that there is no longer a power up currently being drawn and mark the start time for the duration of the
//power up
void PowerUp::invertDirections() {
	removePowerUp();
	isInverted = true;
	startTime = clock();
	//if the worm is moving up and down then prevent it from going to the right
	if (snake->getX_Vel() == 0) {
		isInvertedX = true;
	}
	//if the worm is going left or right then prevent it from going down
	else if (snake->getY_Vel() == 0) {
		isInvertedY = true;
	}
}
