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

		void eat();
		int getX();
		int getY();
		void setX(int iX);
		void setY(int iY);
		void draw();

};


#endif
