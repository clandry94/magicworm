// Food
#include "food.h"
#include "../Snake/Snake.h"
#include "../PowerUp/PowerUp.h"
#include "../respath.h"
#include "../commonSDL.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <SDL2/SDL.h>

using namespace std;

Food::Food() {
  renderer = irenderer;
  snake = isnake;
}

int Food::getX() {
  return foodX;
}

int Food::getY() {
  return foodY;
}

// Generate random X and Y coordinates for food to appear on
void Food::generateFood() {
  // Create random values
  if (totalFood < 1) {
    if(foodX == snake->getX() && foodY == snake->getY())
      eraseFood();
    srand(time(NULL));
    randomValue();
    renderFood();

    return 0;
  }
  else
    return 0;
}
void Food::randomValue() {
  // Generate new food location
  foodX = rand() % 640 + 1;
  foodY = rand() % 480 + 1;
  if ((foodX == powerup.getX() && foodY == powerup.getY()) || (foodX == snake->getX() && foodY == snake->getY()))
    randomValue();
}

void Food::renderFood(SDL_Texture *tex, SDL_Renderer *ren, foodX, foodY) {
  string cupcakePath = respath.getResourcePath("magicworm") + "cupcake.bmp";
  SDL_Texture * renderFood = loadTexture(cupcakePath, renderer);
  if (renderFood == nullptr){
    SDL_Quit();
    return 1;
  }
  renderTexture(renderFood, renderer, foodX, foodY);
  totalFood++;
}

void Food::eraseFood(foodX, foodY) {
  // Remove food

  totalFood--;
  score++;
  generateFood();
}
