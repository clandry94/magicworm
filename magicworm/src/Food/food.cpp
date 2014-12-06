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

Food::Food(SDL_Renderer * irenderer, Snake * isnake, PowerUp * ipowerup) {
  renderer = irenderer;
  snake = isnake;
  powerup = ipowerup;
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
  if (totalFood < 1) {
    // If the snake lands on the same coordinates, erase food
    //if(foodX == snake->getX() && foodY == snake->getY())
      //eraseFood(foodX, foodY);
    srand(time(NULL));
    randomValue();
    renderFood(foodX, foodY);
  }
  else
    generateFood();
}

// Generate new food location with x and y coordinates
void Food::randomValue() {
  foodX = rand() % SCREEN_WIDTH;
  foodY = rand() % SCREEN_HEIGHT;
  if ((foodX == powerup->getX() && foodY == powerup->getY()) || (foodX == snake->getX() && foodY == snake->getY()))
    randomValue();
}

// Draws food on the gameboard
void Food::renderFood(int x, int y) {
  string cupcakePath = getResourcePath("magicworm") + "cupcake.bmp";
  SDL_Texture * renderFood = loadTexture(cupcakePath, renderer);
  if (renderFood == nullptr){
    SDL_Quit();
  }

  SDL_RenderClear(renderer);
  renderTexture(renderFood, renderer, x, y);
  SDL_RenderPresent(renderer);

  totalFood++;
}
/*
// Remove food from the gameboard, increment score, decrement total food in case extra food powerup was used
void Food::eraseFood(int x, int y) {

  totalFood--;
  score++;
  generateFood();
  snake->eat();
}
*/
