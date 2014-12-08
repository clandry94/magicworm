// Menu header file
#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <fstream>
#include <string>
#include "../respath.h"

#include <SDL2/SDL.h>
#include "SDL_ttf.h"

using namespace std;

class Menu {
private:
	Menu::Menu();
	void printMenu();
 	void showHighScore();
 	bool mainMenu();

	SDL_Renderer *ren = NULL;
	SDL_Texture *menTex = NULL;
	SDL_Window *window = NULL;
  TTF_Font *font = NULL;
	SDL_Surface *message = NULL;
	SDL_Texture *messageTex = NULL;
	SDL_Surface *background = NULL;
  SDL_Texture *backgroundTex = NULL;
	SDL_Color *textColor = NULL;

};

#endif
