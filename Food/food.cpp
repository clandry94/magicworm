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

#include <GL/glew.h>
#include <glfw3.h>

using namespace std;

// Generate random X and Y coordinates for food to appear on

void Food::generateFood() {
  // Create random values
  srand(time(NULL));
  randomValue();

  // Draw food using OpenGL

  return 0;
}
void Food::randomValue() {
  // Generate new food location
  foodX = rand() % 100 + 1;
  foodY = rand() % 100 + 1;
  if (foodX == powerupX && foodY == powerupY)
    generateFood();
}
