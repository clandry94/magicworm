#include <SDL2/SDL.h>
#include "Node.h"
#include <vector>

#ifndef SNAKE_H
#define SNAKE_H

using namespace std;

class Snake {

	private:

		int speed;	//speed of the snake
		string color;

	public:
		Node * head;
		bool hasPowerup; //Snake has powerup t/f

		Snake(int speed, string color, int startX, int startY);

		int getSpeed();
		void setSpeed(int val);
		void incrementSpeed();
		void incrementSize(int x, int y);
		void killLast();
		int getSize();
		string getColor();
		void setColor(string newColor);

		void eat();
		int getX();
		int getY();
		void setX(int iX);
		void setY(int iY);

};


#endif
