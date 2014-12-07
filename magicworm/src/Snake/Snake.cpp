#include <iostream>
#include <SDL2/SDL.h>

#include "Snake.h"

Snake::Snake(double iSpeed, string iColor, int iX, int iY) {
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
