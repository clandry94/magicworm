#include "../food/food.h"
#include "../snake/snake.h"

#ifndef POWERUP_H_
#define POWERUP_H_

class PowerUp {
	private:
		int powerUpX;
		int powerUpY;
		SDL_Renderer * renderer;
		Snake * snake;
		Food * food;
		bool isSpedUp;
		bool isSlowedDown;
		void removePowerUp();
		void speedUp();
		void slowDown();
		void changeColor();
		void extraFood();
		void minusScore();
		void invertDirections();
		void deactivatePowerUp();
		int startTime;
		void randomNumbers();
		int whichPowerUp;
		int counter;
		bool isTouching();
		bool isExtraFood;
		bool food1;
		bool food2;
		int foodx1;
		int foodx2;
		int foody1;
		int foody2;


	public:
		PowerUp(SDL_Renderer * irenderer, Snake * isnake, Food * ifood);
		void placePowerUp();
		double timeInSeconds;
		int getX();
		int getY();
		bool isPowerUp;
};

#endif
