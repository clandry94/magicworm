#include "Snake/Snake.cpp"
#include <SDL2/SDL.h>
using namespace std;

int main() {
  if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
  }
  SDL_Quit();
  return 0;
}
