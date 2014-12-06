#include <SDL2/SDL.h>
#include "Node.h"
#include <vector>

#ifndef SNAKE_H
#define SNAKE_H

using namespace std;

class Snake {

	private:
		Node * head;
		int speed;	//speed of the snake
		string color;

	public:

		bool hasPowerup; //Snake has powerup t/f

		Snake(int speed, string color, int startX, int startY);

		int getSpeed();
		void setSpeed(int val);
		void incrementSpeed();
		void incrementSize(int lastKeyPress);

		string getColor();
		void setColor(string newColor);

		void eat();
		int getX();
		int getY();
		void setX(int iX);
		void setY(int iY);

};


#endif
