// Food header file

#ifndef FOOD_H
#define FOOD_H

using namespace std;

class Food {

  private:
    int foodX;             // Food x-coordinate
    int foodY;             // Food y-coordinate
    int totalFood = 0;     // Total food currently on the gameboard, used in case extra food powerup is used

    SDL_Renderer * renderer;
    Snake * snake;
    PowerUp * powerup;

    void randomValue();                                         // Generates random x and y coordinates
    void renderFood(int x, int y);     // Draws food on the gameboard
    void eraseFood(int x, int y);      // Erases food from the gameboard

  public:
    int score = 0;          // Current score
    int getX();             // Returns x-coordinate
    int getY();             // Returns y-coordinate

    Food(SDL_Renderer * irenderer, Snake * isnake, PowerUp * ipowerup);
    void generateFood();    // Starts loop that continuously generates more food
};

#endif
