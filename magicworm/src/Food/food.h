// Food header file

#ifndef FOOD_H
#define FOOD_H

using namespace std;

class Food {

  private:
    int foodX;             // Food x-coordinate
    int foodY;             // Food y-coordinate

    SDL_Renderer * renderer;
    Snake * snake;
    PowerUp * powerup;

    void randomValue();                                         // Generates random x and y coordinates

  public:
    int score = 0;          // Current score
    int totalFood = 0;      // Total food currently on the gameboard, used in case extra food powerup is used
    int getX();             // Returns x-coordinate
    int getY();             // Returns y-coordinate
    bool dropFood = false;
    void raiseScore(int val);
    int getScore();
    Food(SDL_Renderer * irenderer, Snake * isnake, PowerUp * ipowerup);
    void generateFood();    // Starts loop that continuously generates more food
    void renderFood();     // Draws food on the gameboard

};

#endif
