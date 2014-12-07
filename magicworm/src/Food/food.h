// Food header file

#ifndef FOOD_H
#define FOOD_H

using namespace std;

class Food {

  private:
    int foodX;             // Food x-coordinate
    int foodY;             // Food y-coordinate

    bool isTouching(int x1, int y1, int x2, int y2);

    SDL_Renderer * renderer;
    Snake * snake;

    void randomValue();     // Generates random x and y coordinates

  public:
    int score = 0;          // Current score
    int getX();             // Returns x-coordinate
    int getY();             // Returns y-coordinate
    bool dropFood = false;

    void raiseScore(int val);
    int getScore();
    Food(SDL_Renderer * irenderer, Snake * isnake);

    void generateFood();    // Starts loop that continuously generates more food
    void renderFood();     // Draws food on the gameboard

};

#endif
