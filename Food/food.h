// Food header file

#ifndef FOOD_H
#define FOOD_H

#include <SDL/SDL.h>

using namespace std;

class Food {

  private:
    int foodX;
    int foodY;
    void generateFood();
    void randomValue();
    void drawFood();

};

#endif
