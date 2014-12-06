// Main Menu
#include "menu/menu.h"
//#include <iostream>
//#include <fstream> these are unecessary I believe
//#include <string>

//prints the main menu
void printMenu(SDL_Window window){
  SDL_Renderer *ren = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (ren == nullptr){
    SDL_DestroyWindow(win);
    std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
    SDL_Quit();
    return 1;
  }
  //SDL_Delay(2000); //I'm not sure this is necessary

  const std::string menuPath = getResourcePath("magicworm") + "menu.bmp";
  SDL_Surface *bmp = SDL_LoadBMP(menuPath.c_str());
  if (bmp == nullptr){
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(winsow);
    std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
    SDL_Quit();
    return 1;
  }

  SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, bfmp);
  SDL_FreeSurface(bmp);
  if (tex == nullptr){
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(window);
    std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
    SDL_Quit();
    return 1;
  }

  SDL_RenderClear(ren);
  SDL_RenderCopy(ren, tex, NULL, NULL);
  SDL_RenderPresent(ren);
}

//prints the High score screen and contains High Score functionality
void showHighScores(SDL_Window window){

  //reads the high score and stores it in a string
  //I don't know how to put that score on the high score screen
  string text;
  fstream textfile;
  textfile.open("highscore.txt");
  textfile >> text;

  textfile.close();

  SDL_Renderer *ren = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (ren == nullptr){
    SDL_DestroyWindow(win);
    std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
    SDL_Quit();
    return 1;
  }

  const std::string menuPath = getResourcePath("magicworm") + "highscore.bmp";
  SDL_Surface *bmp = SDL_LoadBMP(menuPath.c_str());
  if (bmp == nullptr){
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(window);
    std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
    SDL_Quit();
    return 1;
  }

  SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, bmp);
  SDL_FreeSurface(bmp);
  if (tex == nullptr){
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(window);
    std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
    SDL_Quit();
    return 1;
  }

  SDL_RenderClear(ren);
  SDL_RenderCopy(ren, tex, NULL, NULL);
  SDL_RenderPresent(ren);

  bool quit = false;
  while (!quit){
    while (SDL_PollEvent(&e)){
      switch(e.type){
          /* Look for a keypress */
        case SDL_KEYDOWN:
          /* Check the SDLKey values and move change the coords */
          switch(e.key.keysym.sym){
            case SDLK_ESCAPE:
                quit = true;
                break;
          }
          default:
            break;
      }
      break;
    }
  }
  SDL_DestroyTexture(tex);
  SDL_DestroyRenderer(ren);
}

//main menu functionality
bool mainMenu(SDL_Window window) {
  //cin >> begin; //this was in the code already, I don't know what it's for

  printMenu(SDL_Window window){
  bool quitProgram = false;
  bool quit = false;
  while (!quit){
    while (SDL_PollEvent(&e)){
      switch(e.type){
          /* Look for a keypress */
        case SDL_KEYDOWN:
          /* Check the SDLKey values */
          switch(e.key.keysym.sym){
            case SDLK_ESCAPE:
                quit = true;
                quitProgram = true;
                break;
            case SDLK_s:
                quit = true;
            case SDLK_h:
                showHighScores(window);
                printMenu(window);
                break;
            default:
                break;
          }
          default:
            break;
      }
      break;
    }
  }
  SDL_DestroyTexture(tex);
  SDL_DestroyRenderer(ren);
  return quitProgram;
}

