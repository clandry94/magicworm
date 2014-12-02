#include "../artifact/artifact.h"
#include "../gameboard/gameboard.h"
#include "../food/food.h"
#include "../snake/snake.h"
#include "../powerup/powerup.h"
#include "food.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <GL/glew.h>
#include <glfw3.h>
#include <glm/glm.hpp>

using namespace std;

// Generate random X and Y coordinates for food to appear on
void Food::generateFood() {
  // When the snake intersects with the food or score is 0 (for when the game starts)
  if ((snakeX == foodX && snakeY == foodY) || (score = 0)){
    // Generate new food location
    foodX = rand() % 100 + 1;
    foodY = rand() % 100 + 1;

    // Draw food


  }
}
