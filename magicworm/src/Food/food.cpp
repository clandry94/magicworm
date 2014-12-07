// Food
#include "food.h"
#include "../Snake/Snake.h"
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

bool Food::isTouching(int x1, int y1, int x2, int y2) {
  bool leftCollision = false;
  bool rightCollision = false;
  bool topCollision = false;
  bool bottomCollision = false;

  if (y1 + 16 >= y2)
    topCollision = true;

  if (y1 <= y2 + 16)
    bottomCollision = true;

  if (x1 + 16 >= x2)
    leftCollision = true;

  if (x1 <= x2 + 16)
    rightCollision = true;

  if (topCollision && bottomCollision && leftCollision && rightCollision)
    return true;

  else
    return false;
}

// Return food's x-coordinate
int Food::getX() {
  return foodX;
}

// Return food's y-coordinate
int Food::getY() {
  return foodY;
}

int Food::getScore() {
  return score;
}

void Food::raiseScore(int val) {
  score += val;
}

// Continuously generates food on the gameboard
void Food::generateFood() {
  if (dropFood == false) {
    randomValue();
    renderFood();
    dropFood = true;
  }
  else if(dropFood == true)
    renderFood();
}

// Generate new food location with x and y coordinates
void Food::randomValue() {
  srand(time(NULL));
  foodX = rand() % SCREEN_WIDTH - 16;
  foodY = rand() % SCREEN_HEIGHT - 16;
  if (foodX == snake->getX() && foodY == snake->getY())
    randomValue();
}

// Draws food on the gameboard
void Food::renderFood() {
  const string cupcakePath = getResourcePath("magicworm") + "cupcake.bmp";
  SDL_Texture * renderFood = loadTexture(cupcakePath, renderer);
  if (renderFood == nullptr)
    SDL_Quit();

  //SDL_RenderClear(renderer);
  renderTexture(renderFood, renderer, foodX, foodY);
  SDL_RenderPresent(renderer);

  // If the snake lands on the same coordinates, erase food
  if (isTouching(foodX, foodY, snake->getX(), snake->getY())) {
    cout << "eat food" << endl;
    snake->eat();
    score++;
    dropFood = false;
    generateFood();
  }
}
