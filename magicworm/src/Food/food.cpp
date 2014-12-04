// Food
#include "food.h"

using namespace std;

// Generate random X and Y coordinates for food to appear on
void Food::generateFood() {
  // Create random values
  if(gameboard.score > 0)
    eraseFood();
  srand(time(NULL));
  randomValue();

  drawFood();

  return 0;
}
void Food::randomValue() {
  // Generate new food location
  foodX = rand() % 640 + 1;
  foodY = rand() % 480 + 1;
  if ((foodX == powerup.getX() && foodY == powerup.getY()) || (foodX == snake.getX() && foodY == snake.getY()))
    randomValue();
}

void Food::renderFood(foodX, foodY) {
  // Draw food in SDL
  SDL_Surface *image;
  SDL_Surface *temp;

  respath.getResourcePath("magicworm") + "cupcake";
}

void Food::eraseFood(foodX, foodY) {
  // Remove food
}

void Food::getX() {
  return foodX;
}

void Food::getY() {
  return foodY;
}
