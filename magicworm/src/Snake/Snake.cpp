#include <iostream>
#include <SDL2/SDL.h>

#include "Snake.h"

Snake::Snake(int iSpeed, string iColor, int iX, int iY) {
  speed = iSpeed;
  color = iColor;
  x = iX;
  y = iY;
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

void Snake::eat() {
  incrementSpeed();
}

void Snake::setCoordinate(int newX, int newY) {
  x = newX;
  y = newY;
}

int Snake::getX() {
  return x;
}

int Snake::getY() {
  return y;
}


//Sets the new x and y position
void Snake::setX(int iX) {
  x = iX;
}

void Snake::setY(int iY) {
  y = iY;
}
