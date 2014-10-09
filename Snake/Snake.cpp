#include <iostream>
#include "snake.h"

Snake::Snake(int size, int speed) {

}

int Snake::getSize() {
  return size;
}

void Snake::setSize(int val) {
  size += val;
}

int Snake::getSpeed() {
  return speed;
}

void Snake::setSpeed(int val) {
  speed += val;
}
