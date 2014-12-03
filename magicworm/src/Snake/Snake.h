#include <vector>
#include "../artifact/artifact.h"

#ifndef SNAKE_H
#define SNAKE_H

using namespace std;

class Snake {

	private:
		int size;	//size of the snake
		int speed;	//speed of the snake
		string color;
		vector<artifact> coordinates;

	public:

		bool hasPowerup; //Snake has powerup t/f

		Snake(int size, int speed, string color, artifact initCoords);

		int getSize();
		void incrementSize();

		int getSpeed();
		void setSpeed(int val);
		void incrementSpeed();

		string getColor();
		void setColor(string newColor);

		void eat();

		vector<artifact> getCoordinates() { return coordinates; }
		void setCoordinate(int position, int x, int y);

};


#endif
