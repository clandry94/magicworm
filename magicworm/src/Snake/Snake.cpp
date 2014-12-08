#include <iostream>
#include <SDL2/SDL.h>
#include "../respath.h"
#include "Node.h"
#include "../commonSDL.h"

#include "Snake.h"

using namespace std;

Snake::Snake(SDL_Renderer * irenderer, double iSpeed, int iX, int iY) {
  speed = iSpeed;
  head = new Node(iX, iY);
  renderer = irenderer;
  snakePath = getResourcePath("magicworm") + "snake.bmp";
  setTexture(snakePath);
}

/*
 * Sets current velocity of the snake according to velocity
 *  with respect to current direction
 */
void Snake::checkVelocity() {
  if(x_vel != 0) {
    if(x_vel > 0) {
      x_vel = speed;
    } else {
      x_vel = speed * -1;
    }
  }

  if(y_vel != 0) {
    if(y_vel > 0) {
      y_vel = speed;
    } else {
      y_vel = speed * -1;
    }
  }
}

bool Snake::isCollision(int &x, int &y, int i) {
  int hX = getX();
  int hY = getY();

  if((hX == x && hY == y) && i >= 1) {
    return true;
  }

  return false;
}

void Snake::setX_Vel(int val) {
  x_vel = val;
}

int Snake::getX_Vel() {
  return x_vel;
}

void Snake::setY_Vel(int val) {
  y_vel = val;
}

int Snake::getY_Vel() {
  return y_vel;
}

std::string Snake::getTexture() {
  return snakePath;
}

void Snake::setTexture(std::string path) {
  snakePath = path;

  image = loadTexture(snakePath, renderer);
  if (image == nullptr){
    //cleanup(background, image, render, window);
    cout << "Problem loading texture" << endl;
    SDL_Quit();
  }

}

int Snake::getSpeed() {
  return speed;
}

void Snake::setSpeed(int val) {
  speed = val;
}

void Snake::incrementSpeed() {
  speed += .5;
}

int Snake::getSize() {
  int size = 1;
	for(Node * body = head; body->next != NULL; body = body->next) {
		size++;
	}
	return size;
}

/*
  1. Move the head forward one.
  2. Put a body segment where the head was.
  3. Erase the last body segment.
*/
void Snake::incrementSize(int x, int y) {
  Node * body;
	body = head;

	while(body->next != NULL){
    body = body->next;
  }

	body->next = new Node (x, y);
  //cout << "NEW NODE: " << "(" << x << "," << y << ")";
}

//actually kills first
void Snake::killLast() {

  Node * p;
	p = head;

	Node *pPre = NULL, *pDel = NULL;

  pPre = head;
	pDel = head->next;

	//If not first then find value
	// and perform shifting operations.
	while (pDel != NULL) {
			pPre->next = pDel->next;
			delete pDel;
			pDel  = pPre->next;
			break;

		//cout << pDel->data;
	}


}

void Snake::eat() {
  incrementSpeed();
  for(int i = 0; i < 4; i++) {
    incrementSize(Snake::getX(), Snake::getY());
  }

}

int Snake::getX() {
  return head->x;
}

int Snake::getY() {
  return head->y;
}

//Sets the new x and y position
void Snake::setX(int iX) {
  head->x = iX;
}

void Snake::setY(int iY) {
  head->y = iY;
}

bool Snake::draw() {
    Node * body;
    body = head;
    int i = 0;

  /*
    1. Move the head forward one.
    2. Put a body segment where the head was.
    3. Erase the last body segment.
  */
    incrementSize(getX(), getY());
    killLast();
    SDL_RenderClear(renderer);
    //renderTexture(image, renderer, body->x, body->y);

    while(body != NULL) {
      renderTexture(image, renderer, body->x, body->y);
      if(body->next != NULL) {
        if(isCollision(body->x, body->y, i)) {
          return false;
        }
      }
      body = body->next;
      i++;
    }

    SDL_RenderPresent(renderer);

    return true;
}
