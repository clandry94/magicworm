#include "Snake/Snake.cpp"
#include <SDL2/SDL.h>
#include <vector>
#include "respath.h"
#include "PowerUp/PowerUp.cpp"
#include "Food/food.cpp"
#include "commonSDL.h"
#include "Snake/Node.h"
#include <ctime>

using namespace std;



bool hitBoundary(int x, int y) {
  if(x < 0 || (x + 16) > 640) {
    return true;
  }
  if(y < 0 || (y+16) > 640) {
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
  SDL_Renderer * renderer = createRenderer(window);


  SDL_RenderClear(renderer);


  Snake * snake = new Snake(renderer, 1, 50, 50);
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
                      case SDLK_k:
                          snake->incrementSpeed();
                          cout << "SNAKE SPEED: " << snake->getSpeed() << endl;
                          break;
                      case SDLK_j:
                          for(int i = 0; i < 8; i++) {
                            snake->incrementSize(snake->getX(), snake->getY());
                          }
                          cout << "SNAKE SIZE: " << snake->getSize() << endl;
                          break;
                      case SDLK_h:
                          snake->eat();
                          cout << "Ate food!" << endl;
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
    snake->draw();

    //Render the scene
    SDL_RenderClear(renderer);
  }

  //cleanup(background, image, render, window);
  SDL_Quit();
}
