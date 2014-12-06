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

Food::Food(SDL_Renderer * irenderer, Snake * isnake) {
  renderer = irenderer;
  snake = isnake;
}

// Return food's x-coordinate
int Food::getX() {
  return foodX;
}

// Return food's y-coordinate
int Food::getY() {
  return foodY;
}

// Continuously generates food on the gameboard
void Food::generateFood() {
  // Check if the extra food powerup has been used
  while (totalFood == 0) {
    // If the snake lands on the same coordinates, erase food
    if(foodX == snake->getX() && foodY == snake->getY()) {
      cout << "eat food" << endl;
      snake->eat();
      totalFood--;
      score++;
      generateFood();
    }
    srand(time(NULL));
    randomValue();
    renderFood(foodX, foodY);
    cout << "generated food" << endl;
  }
}

// Generate new food location with x and y coordinates
void Food::randomValue() {
  cout << "random variables" << endl;
  foodX = rand() % SCREEN_WIDTH;
  foodY = rand() % SCREEN_HEIGHT;
  if (foodX == snake->getX() && foodY == snake->getY())
    generateFood();
}

// Draws food on the gameboard
void Food::renderFood(int x, int y) {
  cout << "rendered food" << endl;
  const string cupcakePath = getResourcePath("magicworm") + "cupcake.bmp";
  SDL_Texture * renderFood = loadTexture(cupcakePath, renderer);
  if (renderFood == nullptr){
    SDL_Quit();
  }

  //SDL_RenderClear(renderer);
  renderTexture(renderFood, renderer, x, y);
  SDL_RenderPresent(renderer);

  totalFood++;
}
