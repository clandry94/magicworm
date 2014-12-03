#include <iostream>

#include "Snake.h"

Snake::Snake(int size, int speed, string color, artifact startCoords) {
  size = this->size;
  speed = this->speed;
  color = this->color;
  coordinates.at(0).x = startCoords.x;
  coordinates.at(0).y = startCoords.y;
  coordinates.at(0).type = 1;
  coordinates.at(0).color = color;
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

void Snake::setCoordinate(int position, int x, int y) {
  getCoordinates().at(position).x = x;
  getCoordinates().at(position).y = y;
}
