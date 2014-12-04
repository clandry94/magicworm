// Food
#include "food.h"

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
