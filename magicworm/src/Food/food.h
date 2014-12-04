// Food header file

#ifndef FOOD_H
#define FOOD_H

#include "../Snake/Snake.h"
#include "../PowerUp/PowerUp.h"
#include "../respath.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <SDL2/SDL.h>

using namespace std;

class Food {

  private:
    int foodX;
    int foodY;
    int totalFood = 0;

    void generateFood();
    void randomValue();
    void renderFood(int x, int y);
    void eraseFood(int x, int y);
    void getX();
    void getY();
};

#endif
