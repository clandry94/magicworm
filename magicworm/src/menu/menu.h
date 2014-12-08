// Menu header file
#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <fstream>
#include <string>
#include "../respath.h"

#include "..SDL2/SDL.h"
#include <SDL_ttf.h>

using namespace std;

class Menu {
private:
	Menu::Menu();
	void printMenu();
 	void showHighScore();
 	bool mainMenu();
};

#endif