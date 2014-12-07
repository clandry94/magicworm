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

  mEat.h = foodHeight;
  mEat.w = foodWidth;
}



bool checkCollision(SDL_Rect a, SDL_Rect b) {
  //The sides of the rectangles
  int leftA, leftB;
  int rightA, rightB;
  int topA, topB;
  int bottomA, bottomB;

  //Calculate the sides of rect A
  leftA = a.x;
  rightA = a.x + a.w;
  topA = a.y;
  bottomA = a.y + a.h;

  //Calculate the sides of rect B
  leftB = b.x;
  rightB = b.x + b.w;
  topB = b.y;
  bottomB = b.y + b.h;

  //If any of the sides from A are outside of B
  if( bottomA <= topB )
    return false;

  if( topA >= bottomB )
    return false;

  if(rightA <= leftB)
    return false;

  if(leftA >= rightB)
    return false;


  //If none of the sides from A are outside B
  return true;
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

  mEat.x = foodX;
  mEat.y = foodY;
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
  if(foodX == snake->getX() && foodY == snake->getY()) {
    cout << "eat food" << endl;
    snake->eat();
    score++;
    dropFood = false;
    generateFood();
  }
}
