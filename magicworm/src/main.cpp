#include "Snake/Snake.cpp"
#include <SDL2/SDL.h>
#include <vector>
#include "respath.h"
#include "PowerUp/PowerUp.cpp"
#include "commonSDL.h"

using namespace std;



/*
 * Checks the velocity of the snake and updates accordingly
 */
void checkVelocity(int &x_vel, int &y_vel, int &speed) {
  if(x_vel != 0) {
    if(x_vel > 0) {
      x_vel = speed;
    } else {
      x_vel = speed * -1;
    }
  }

  if(y_vel != 0) {
    if(y_vel > 0) {
      y_vel = speed;
    } else {
      y_vel = speed * -1;
    }
  }

}

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

  //Path to the snake resource
  const string snakePath = getResourcePath("magicworm") + "snake.bmp";

  SDL_Texture * image = loadTexture(snakePath, renderer);
  if (image == nullptr){
  	//cleanup(background, image, render, window);
  	SDL_Quit();
  	return 1;
  }

  SDL_RenderClear(renderer);

  int iW, iH;
  SDL_QueryTexture(image, NULL, NULL, &iW, &iH);

  int initX = SCREEN_WIDTH / 2 - iW / 2;
  int initY = SCREEN_HEIGHT / 2 - iH / 2;

  Snake * snake = new Snake(1, "red", initX, initY);
  PowerUp * powerup = new PowerUp(renderer, snake);


  int x_vel = 0;
  int y_vel = 0;
  int speed = snake->getSpeed();
  int lastKeyPress = 0;

  //renderTexture(image, renderer, x, y);
  //renderTexture(image, renderer, 50, 50);

  //Our event structure
  SDL_Event e;
  bool quit = false;
  while (!quit){
  	while (SDL_PollEvent(&e)){
      switch(e.type){
              /* Look for a keypress */
            case SDL_KEYDOWN:
                  /* Check the SDLKey values and move change the coords */
                  switch(e.key.keysym.sym){
                      case SDLK_LEFT:
                          x_vel = speed * -1;
                          y_vel = 0;
                          lastKeyPress = 1;
                          break;
                      case SDLK_RIGHT:
                          x_vel = speed;
                          y_vel = 0;
                          lastKeyPress = 2;
                          break;
                      case SDLK_UP:
                          x_vel = 0;
                          y_vel = speed * -1;
                          lastKeyPress = 3;
                          break;
                      case SDLK_DOWN:
                          x_vel = 0;
                          y_vel = speed;
                          lastKeyPress = 4;
                          break;
                      case SDLK_ESCAPE:
                          SDL_Quit();
                          break;
                      case SDLK_k:
                          snake->incrementSpeed();
                          cout << "SNAKE SPEED: " << snake->getSpeed() << endl;
                      case SDLK_j:
                          //snake->incrementSize(lastKeyPress);
                      default:
                          break;
                  }
                  default:
                    break;
          }
          break;

          //render snake
          //renderTexture(image, renderer, snake->getX(), snake->getY());

    }
    if(!powerup->isPowerUp) {
      powerup->placePowerUp();
    } else {
      powerup->speedUp(powerup->getX(), powerup->getY());
    }

    checkVelocity(x_vel, y_vel, speed);
    speed = snake->getSpeed();
    snake->setX(snake->getX() + x_vel);
    snake->setY(snake->getY() + y_vel);

    //cout << initX << "," << snake->getX() << endl;
    //cout << initY << "," << snake->getY() << endl;

    if(hitBoundary(snake->getX(), snake->getY())) {
      SDL_Quit();
    }
  	//Render the scene
  	SDL_RenderClear(renderer);
  	renderTexture(image, renderer, snake->getX(), snake->getY());
  	SDL_RenderPresent(renderer);
  }
  //cleanup(background, image, render, window);
  SDL_Quit();
}
