// Food header file

#ifndef FOOD_H
#define FOOD_H

using namespace std;

// Food, the point of the game is to collect as much as possible
class Food {

  private:
    int foodX;             // Food x-coordinate
    int foodY;             // Food y-coordinate

    bool isTouching(int x1, int y1, int x2, int y2);      // Detects if the food is in contact with the Snake

    SDL_Renderer * renderer;
    Snake * snake;

    void randomValue();     // Generates random x and y coordinates

  public:
    int score = 0;          // Current score
    int getX();             // Returns x-coordinate
    int getY();             // Returns y-coordinate
    bool dropFood = false;  // Keeps track on if food is on the gameboard

    void raiseScore(int val);                           // Lets other classes (i.e. powerup) change the score
    int getScore();                                     // Returns score
    Food(SDL_Renderer * irenderer, Snake * isnake);     // Constructor

    void generateFood();    // Starts loop that continuously generates more food
    void renderFood();      // Draws food on the gameboard
};

#endif
