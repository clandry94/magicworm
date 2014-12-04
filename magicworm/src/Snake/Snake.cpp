#include <iostream>

#include "Snake.h"

Snake::Snake(int speed, string color, int x, int y) {
  speed = this->speed;
  color = this->color;
  x = this->x;
  y = this->y;
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
