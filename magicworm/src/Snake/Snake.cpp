#include <iostream>
#include <SDL2/SDL.h>

#include "Snake.h"

Snake::Snake(int iSpeed, string iColor, int iX, int iY) {
  speed = iSpeed;
  color = iColor;
  head = new Node(iX, iY);
}

int Snake::getSpeed() {
  return speed;
}

void Snake::setSpeed(int val) {
  speed = val;
}

void Snake::incrementSpeed() {
  speed += 1;
}
/*
void Snake::incrementSize(int lastKeyPress) {
  const int incrementVal = 16;
  Node * body;
  body = head;
  int iX;
  int iY;

  switch(lastKeyPress) {
    case 1:
      iX = body->x - incrementVal;
      iY = body->y;
      break;
    case 2:
      iX = body->x + incrementVal;
      iY = body->y;
      break;
    case 3:
      iX = body->x;
      iY = body->y + incrementVal;
      break;;
    case 4:
      iX = body->x;
      iY = body->y - incrementVal;
      break;
    default:
      iX = 0;
      iY = 0;
  }



	while(body->next != NULL)
		body=body->next;
	body->next = new Node(iX, iY);

}
*/

void Snake::eat() {
  incrementSpeed();
  //incrementSize();
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
