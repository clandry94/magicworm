// Food
#include "food.h"

using namespace std;

// Generate random X and Y coordinates for food to appear on
void Food::generateFood() {
  // Create random values
  if (totalFood < 1) {
    if(gameboard.score > 0)
      eraseFood();
    srand(time(NULL));
    randomValue();

    drawFood();

    totalFood++;

    return 0;
  }
  else
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

  SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (ren == nullptr) {
    SDL_DestroyWindow(win);
    cout << "CreateRenderer Error: " << SDL_GetError() << endl;
    SDL_Quit();
    return 1;
  }

  string imagepath = respath.getResourcePath("magicworm") + "cupcake.bmp";
  if (bmp == nullptr) {
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    cout << "LoadBMP Error: " << SDL_GetError() << endl;
    SDL_Quit();
    return 1;
  }

  SDL_Texture *tex = SDL_CreateTextureFromSurface(ren,bmp);
  SDL_FreeSurface(bmp);
  if (tex == nullptr) {
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    cout << "CreateTextureFromSurface Error: " << SDL_GetError() << endl;
    SDL_Quit();
    return 1;
  }

  /*
  SD_Surface *screen;
  SDL_Surface *image;
  SDL_Surface *temp;
  SDL_Rect src, dest;

  temp = respath.getResourcePath("magicworm") + "cupcake";
  if (temp == NULL) {
    cout << "Unable to render cupcake: " << SDL_GetError() <<endl;
    return 1;

    src.x = 0;
    src.y = 0;
    src.w = image->w;
    src.h = image->h;

    dest.x = foodX;
    dest.y = foodY;
    dest.w = image->w;
    dest.h = image->h;

    SDL_BlitSurface(image, &src, screen, &dest);
  }
  */
}

void Food::eraseFood(foodX, foodY) {
  // Remove food

  totalFood--;
  generateFood();
}

void Food::getX() {
  return foodX;
}

void Food::getY() {
  return foodY;
}
