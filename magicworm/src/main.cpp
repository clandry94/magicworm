#include "Snake/Snake.cpp"
#include <SDL2/SDL.h>
#include <vector>
#include "Artifact/Artifact.h"

using namespace std;

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480


/*
  Logs error created from the SDL graphics
*/
void logSDLError(ostream &os, const string &msg) {
  os << msg << " error: " << SDL_GetError() << endl;
}

SDL_Texture * loadTexture(const string &file, SDL_Renderer *ren) {
  //init to nullptr for no pointer crashes
  SDL_Texture *texture = nullptr;

  //Load background image
  SDL_Surface *loadedImage = SDL_LoadBMP(file.c_str());

  //If the loading went ok, convert to texture and return
  if(loadedImage != nullptr) {
    texture = SDL_CreateTextureFromSurface(ren, loadedImage);
		SDL_FreeSurface(loadedImage);
		//Make sure converting went ok
		if (texture == nullptr){
			logSDLError(std::cout, "CreateTextureFromSurface");
		}
	} else {
    logSDLError(cout, "LoadBMP");
  }

  return texture;
}

/*
  * Draw an SDL_Texture to an SDL_Renderer at position x, y, preserving
  * the texture's width and height
  * @param tex The source texture we want to draw
  * @param ren The renderer we want to draw to
  * @param x The x coordinate to draw to
  * @param y The y coordinate to draw to
*/
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y){
	//Setup the destination rectangle to be at the position we want
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	//Query the texture to get its width and height to use
	SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
	SDL_RenderCopy(ren, tex, NULL, &dst);
}


int main() {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
  	logSDLError(std::cout, "SDL_Init");
  	return 1;
  }

  SDL_Window *window = SDL_CreateWindow("MagicWorm", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if (window == nullptr){
  	logSDLError(std::cout, "CreateWindow");
  	SDL_Quit();
  	return 1;
  }

  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  if (renderer == nullptr){
  	logSDLError(std::cout, "CreateRenderer");
  	//cleanup(window);
  	SDL_Quit();
  	return 1;
  }

  const string backgroundPath = "/Users/landry/Documents/cop3503/magicworm/res/magicworm/background.bmp";
  const string snakePath = "/Users/landry/Documents/cop3503/magicworm/res/magicworm/square.bmp";
  SDL_Texture *background = loadTexture(backgroundPath, renderer);
  SDL_Texture *image = loadTexture(snakePath, renderer);
  if (background == nullptr || image == nullptr){
  	//cleanup(background, image, render, window);
  	SDL_Quit();
  	return 1;
  }

  SDL_RenderClear(renderer);

  int iW, iH;
  SDL_QueryTexture(image, NULL, NULL, &iW, &iH);
  int x = SCREEN_WIDTH / 2 - iW / 2;
  int y = SCREEN_HEIGHT / 2 - iH / 2;
  //int x = 0;
  //int y = 0;
  //int x_vel = 0;
  //int y_vel = 0;

  //renderTexture(image, renderer, x, y);
  //renderTexture(image, renderer, 50, 50);
  Snake * snake = new Snake(1, "red", 0, 0);
  //Our event structure
  SDL_Event e;
  vector<artifact> snakeCoords;
  bool quit = false;
  while (!quit){

    //snakeCoords = snake->getCoordinates();

  	while (SDL_PollEvent(&e)){
      switch(e.type){
              /* Look for a keypress */
            case SDL_KEYDOWN:
                  /* Check the SDLKey values and move change the coords */
                  switch(e.key.keysym.sym){
                      case SDLK_LEFT:
                          x -= 5;
                          break;
                      case SDLK_RIGHT:
                          x += 5;
                          break;
                      case SDLK_UP:
                          y -= 5;
                          break;
                      case SDLK_DOWN:
                          y += 5;
                          break;
                      case SDLK_ESCAPE:
                          SDL_Quit();
                          break;
                      case SDLK_k:

                      default:
                          break;
                  }
                  default:
                    break;
          }
          break;

          renderTexture(image, renderer, x, y);

  }
	//Render the scene
	SDL_RenderClear(renderer);
	renderTexture(image, renderer, x, y);
	SDL_RenderPresent(renderer);
}
  //cleanup(background, image, render, window);
  SDL_Quit();
}
