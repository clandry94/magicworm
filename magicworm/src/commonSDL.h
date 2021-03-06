#ifndef COMMONSDL_H
#define COMMONSDL_H

#include <SDL2/SDL.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

using namespace std;

//Error logger for SDL
void logSDLError(ostream &os, const string &msg) {
  os << msg << " error: " << SDL_GetError() << endl;
}

SDL_Renderer * createRenderer(SDL_Window * window) {

  SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  if (renderer == nullptr){
    logSDLError(std::cout, "CreateRenderer");
    //cleanup(window);
    SDL_Quit();
    return NULL;
  }

  return renderer;
}

SDL_Window * createWindow() {
  SDL_Window * window = SDL_CreateWindow("MagicWorm", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if (window == nullptr){
    logSDLError(std::cout, "CreateWindow");
    SDL_Quit();
    return NULL;
  }

  return window;
}

//Draw SDL texture
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y){
  //Setup the destination rectangle to be at the position we want
  SDL_Rect dst;
  dst.x = x;
  dst.y = y;
  //Query the texture to get its width and height to use
  SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
  SDL_RenderCopy(ren, tex, NULL, &dst);
}

SDL_Texture * loadTexture(const string &file, SDL_Renderer *ren) {
  //init to nullptr for no pointer crashes
  SDL_Texture *texture = nullptr;

  //Load background image
  SDL_Surface *loadedImage = SDL_LoadBMP(file.c_str());

  //if loading was okay then create the texture
  if(loadedImage != nullptr) {
    texture = SDL_CreateTextureFromSurface(ren, loadedImage);
    SDL_FreeSurface(loadedImage);
    //Make sure converting went ok
    if (texture == nullptr){
      logSDLError(std::cout, "CreateTextureFromSurface");
    }
  } else {
    logSDLError(std::cout, "LoadBMP");
  }

  return texture;
}

#endif
