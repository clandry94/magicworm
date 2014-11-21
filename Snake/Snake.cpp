#include <iostream>
#include "../position/position.h"
#include "snake.h"

Snake::Snake(int size, int speed, string color, position startCoords) {
  size = this->size;
  speed = this->speed;
  color = this->color;
  coordinates.at(0).x = startCoords.x;
  coordinates.at(0).y = startCoords.y;
  coordinates.at(0).type = 1;
}

int Snake::getSize() {
  return size;
}

void Snake::incrementSize() {
  size += 1;
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
  incrementSize();
  incrementSpeed();
}

vector<position> getPositions() {
  return coordinates;
}

void setPositions(int position, int x, int y) {
  coordinates.at(position).x = x;
  coordinates.at(position).y = y;
}
