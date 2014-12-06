// Menu header file
#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <iostream>
#include <fstream>
#include <string>

#include <SDL/SDL.h>

using namespace std;

class Menu {
private:

	void printMenu();
 	void showHighScore();
 	bool mainMenu();
};

#endif
