// Menu header file
#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <fstream>
#include <string>
#include "../respath.h"
#include <SDL/SDL_ttf.h>

#include <SDL2/SDL.h>

#include "../commonSDL.h"

using namespace std;

class Menu {
public:
	Menu(SDL_Window *sentWindow);
	void printMenu();
 	void showHighScore();
 	bool mainMenu();

	SDL_Renderer *ren;
	SDL_Texture *menTex;
	SDL_Texture *tex;
	SDL_Window *window;
	TTF_Font *font;
	SDL_Surface *message;
	SDL_Texture *messageTex;

};

#endif
