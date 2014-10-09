#ifndef SNAKE_H
#define SNAKE_H

class Snake {

	private:
		int size;	//size of the snake
		int speed;	//speed of the snake

	public:
		Snake(int size, int speed);
		
		int getSize();
		void setSize(int val);

		int getSpeed();
		void setSpeed(int val);

};


#endif
