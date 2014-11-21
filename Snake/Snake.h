#include <vector>

#ifndef SNAKE_H
#define SNAKE_H

using namespace std;

class Snake {

	private:
		int size;	//size of the snake
		int speed;	//speed of the snake
		string color;
		vector<position> coordinates;

	public:
		bool hasPowerup; //Snake has powerup t/f

		Snake(int size, int speed, string color, position initCoords);

		int getSize();
		void incrementSize();

		int getSpeed();
		void setSpeed(int val);
		void incrementSpeed();

		string getColor();
		void setColor(string newColor);

		void eat();

		vector<position> getPositions();
		void setPositions();
		
};


#endif
