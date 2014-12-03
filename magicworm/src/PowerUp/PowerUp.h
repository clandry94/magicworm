#ifndef POWERUP_H_
#define POWERUP_H_

#include "Position.h"

class PowerUp {
	private:
		PowerUp();
		void placePowerUp(int x, int y);
		void removePowerUp(int x, int y);

	public:
		void speedUp(int speed);
		void slowDown(int speed);
		void changeColor();
		void extraFood();
		void minusScore(int score);
		void invertDirections();
};

#endif
