// Food header file

#ifndef FOOD_H
#define FOOD_H

using namespace std;

class Food {

  private:
    int foodX;             // Food x-coordinate
    int foodY;             // Food y-coordinate

    bool checkCollision(SDL_Rect a, SDL_Rect b);

    SDL_Renderer * renderer;
    Snake * snake;

    void randomValue();     // Generates random x and y coordinates

    SDL_Rect mEat;

  public:
    int score = 0;          // Current score
    static const int foodHeight = 16;
    static const int foodWidth = 16;
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
