// Food

#include "../artifact/artifact.h"
#include "../gameboard/gameboard.h"
#include "../snake/snake.h"
#include "../powerup/powerup.h"
#include "food.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <SDL/SDL.h>
#include <mingw32>
#include <SDLmain>
#include <SDL>

using namespace std;

// Generate random X and Y coordinates for food to appear on
void Food::generateFood() {
  // Create random values
  srand(time(NULL));
  randomValue();

  drawFood();

  return 0;
}
void Food::randomValue() {
  // Generate new food location
  foodX = rand() % 100 + 1;
  foodY = rand() % 100 + 1;
  if ((foodX == powerup.getX() && foodY == powerup.getY()) || (foodX == snake.getX() && foodY == snake.getY()))
    randomValue();
}

void Food::drawFood() {

}
