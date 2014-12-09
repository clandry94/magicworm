#define SUPPRESSED(expr) do { (void)(expr); } while (0)


#include "Snake/Snake.cpp"
#include <SDL2/SDL.h>
#include <vector>
#include "respath.h"
#include "PowerUp/PowerUp.cpp"
#include "Food/food.cpp"
#include "commonSDL.h"
#include "Snake/Node.h"
#include <fstream>
#include "menu/menu.cpp"
#include <sstream>
#include <iostream>
#include <ctime>

using namespace std;


void gameOver(SDL_Renderer * renderer, SDL_Window * window){
  //displays the gameover screen
  const string gameOverPath = getResourcePath("magicworm") + "gameOver.bmp";
  SDL_Surface *bmp = SDL_LoadBMP(gameOverPath.c_str());
  if (bmp == nullptr){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    std::cout << "SDL_LoadMenuBMP Error: " << SDL_GetError() << std::endl;
    SDL_Quit();
  }

  SDL_Texture * gameOver = SDL_CreateTextureFromSurface(renderer, bmp);
  SDL_FreeSurface(bmp);
  if (gameOver == nullptr){
      SDL_DestroyRenderer(renderer);
      SDL_DestroyWindow(window);
      std::cout << "SDL_CreateMenuTextureFromSurface Error: " << SDL_GetError() << std::endl;
      SDL_Quit();
  }

  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, gameOver, NULL, NULL);
  SDL_RenderPresent(renderer);
}

/*
* Checks if the snake has hit one of the boundaries of the window
*
*/
bool hitBoundary(int x, int y) {
  if(x < 0 || (x + 16) > SCREEN_WIDTH) {
    return true;
  }
  if(y < 0 || (y + 16) > SCREEN_HEIGHT) {
    return true;
  }
  return false;
}


int main() {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
    logSDLError(std::cout, "SDL_Init");
    return 1;
  }


  SDL_Window * window = createWindow(); //Creates the window used on the screen

  Menu * menu = new Menu(window); //Instantiate menu class
  SUPPRESSED(menu); //Suppresses unneeded menu warning message on compile

  //Creates renderer which draws gamepieces
  SDL_Renderer * renderer = createRenderer(window);


  Snake * snake = new Snake(renderer, 2, 50, 50);
  Food * food = new Food(renderer, snake);
  PowerUp * powerup = new PowerUp(renderer, snake, food);

  int vel = 0;

  //Our event structure
  SDL_Event e;
  bool quit = false;
  while (!quit){
    while (SDL_PollEvent(&e)){
      vel = snake->getSpeed();
      switch(e.type){
              /* Look for a keypress */
            case SDL_KEYDOWN:
                  /* Check the SDLKey values and move change the coords */
                  switch(e.key.keysym.sym){
                      case SDLK_LEFT:
                          snake->setX_Vel(vel * -1);
                          snake->setY_Vel(0);
                          break;
                      case SDLK_RIGHT:
                          snake->setX_Vel(vel);
                          snake->setY_Vel(0);
                          break;
                      case SDLK_UP:
                          snake->setX_Vel(0);
                          snake->setY_Vel(vel * -1);
                          break;
                      case SDLK_DOWN:
                          snake->setX_Vel(0);
                          snake->setY_Vel(vel);
                          break;
                      case SDLK_ESCAPE:
                          SDL_Quit();
                          break;
                      default:
                          break;
                  }
                  default:
                    break;
          }
          break;

    }

    powerup->placePowerUp();
    food->generateFood();
    snake->checkVelocity();

    snake->setX(snake->getX() + snake->getX_Vel());
    snake->setY(snake->getY() + snake->getY_Vel());

    if(hitBoundary(snake->getX(), snake->getY())) {
      quit = true;
    }

    if(!snake->draw()) {
      quit = true;
    }

    //Render the scene
    SDL_RenderClear(renderer);
  }

  quit = false;
  while(!quit) {
    gameOver(renderer, window);
    while(SDL_PollEvent(&e)) {
      switch(e.type) {
        case SDL_KEYDOWN:
          switch(e.key.keysym.sym) {
            case SDLK_ESCAPE:
              SDL_Quit();
              std::exit(0);
              break;
            default:
              break;
          }
        default:
          break;
        }
      }
    }
  }
