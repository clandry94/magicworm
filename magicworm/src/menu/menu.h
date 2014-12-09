// Menu header file
#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include "../respath.h"

#include <SDL2/SDL.h>

#include "../commonSDL.h"

using namespace std;

class Menu {
public:
	Menu(SDL_Window *sentWindow);
	void printMenu();
 	void mainMenu();

	SDL_Renderer *ren;
	SDL_Texture *menTex;
	SDL_Window *window;
};

#endif
