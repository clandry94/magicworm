#include <SDL2/SDL.h>
#include "Node.h"
#include <vector>

#ifndef SNAKE_H
#define SNAKE_H

class Snake {

	private:
		double speed;	//speed of the snake
		std::string snakePath;
		SDL_Texture * image;
		SDL_Renderer * renderer;
		int y_vel = 0;
		int x_vel = 0;

	public:
		Node * head;
		bool hasPowerup; //Snake has powerup t/f
		Snake(SDL_Renderer * renderer, double speed, int startX, int startY);
		void setTexture(std::string path);
		std::string getTexture();
		int getSpeed();
		void setSpeed(int val);
		void incrementSpeed();
		void incrementSize(int x, int y);
		void killLast();
		int getSize();
		void checkVelocity();
		void eat();
		int getX();
		int getY();
		void setX(int iX);
		void setY(int iY);
		void draw();

		int getY_Vel();
		void setY_Vel(int val);
		int getX_Vel();
		void setX_Vel(int val);

};


#endif
