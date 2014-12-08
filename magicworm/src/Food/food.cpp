// Food
#include "food.h"
#include "../Snake/Snake.h"
#include "../respath.h"
#include "../commonSDL.h"
#include "../Snake/Node.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <SDL2/SDL.h>

using namespace std;

//Constructor
Food::Food(SDL_Renderer * irenderer, Snake * isnake) {
  renderer = irenderer;
  snake = isnake;
}

// Checks for collision with snake
bool Food::isTouching(int x1, int y1, int x2, int y2) {
  bool leftCollision = false;
  bool rightCollision = false;
  bool topCollision = false;
  bool bottomCollision = false;

  // Makes sure the snake can hit any part of the food instead of the top left corner
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

// Returns current score
int Food::getScore() {
  return score;
}

// Allows score to be raised
void Food::raiseScore(int val) {
  score += val;
}

// Continuously generates food on the gameboard
void Food::generateFood() {
  // If there is no food on the board, generate random x and y coordinate and render food
  if (dropFood == false) {
    randomValue();
    renderFood();
    dropFood = true;
  }
  // If food is on the board, keep rendering it
  else if(dropFood == true)
    renderFood();
}

// Generate new food location with x and y coordinates
void Food::randomValue() {
  srand(time(NULL));
  foodX = rand() % (SCREEN_WIDTH - 16);
  foodY = rand() % (SCREEN_HEIGHT - 16);
  // Check to make sure the food does not land on the snake
  if (isTouching(foodX, foodY, snake->getX(), snake->getY()))
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

  // If the snake lands on the same coordinates, call eat method in snake to increment size and speed, increment score, generate new food
  if (isTouching(foodX, foodY, snake->getX(), snake->getY())) {
    snake->eat();
    score++;
    cout << "Score: " << score << endl;
    dropFood = false;
    generateFood();
  }
}
