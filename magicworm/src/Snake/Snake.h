#include <SDL2/SDL.h>

#ifndef SNAKE_H
#define SNAKE_H

using namespace std;

class Snake {

	private:
		int speed;	//speed of the snake
		int x;
		int y;
		string color;

	public:

		bool hasPowerup; //Snake has powerup t/f

		Snake(int speed, string color, int startX, int startY);

		void incrementSize();

		int getSpeed();
		void setSpeed(int val);
		void incrementSpeed();

		string getColor();
		void setColor(string newColor);

		void eat();
		void setCoordinate(int x, int y);
		int getX();
		int getY();
		void setX(int iX);
		void setY(int iY);

};


#endif
