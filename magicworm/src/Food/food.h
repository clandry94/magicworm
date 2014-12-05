// Food header file

#ifndef FOOD_H
#define FOOD_H

using namespace std;

class Food {

  private:
    int foodX;
    int foodY;
    int totalFood = 0;

    SDL_Renderer * renderer;
    Snake * snake;

    Food(SDL_Renderer * irenderer);
    void randomValue();
    void renderFood(int x, int y, SDL_Renderer * renderer);
    void eraseFood(int x, int y, SDL_Renderer * renderer);

  public:
    int score;
    int getX();
    int getY();

    void generateFood();
};

#endif
