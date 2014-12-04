#ifndef POWERUP_H_
#define POWERUP_H_

class PowerUp {
	private:
		PowerUp(SDL_Renderer * irenderer);
		void placePowerUp();
		void removePowerUp();
		int powerUpX;
		int powerUpY;
		bool isPowerUp;
		SDL_Renderer * renderer;

	public:
		void speedUp(int x, int y, SDL_Renderer * renderer);
		void slowDown(int x, int y, SDL_Renderer * renderer);
		void changeColor(int x, int y, SDL_Renderer * renderer);
		void extraFood(int x, int y, SDL_Renderer * renderer);
		void minusScore(int x, int y, SDL_Renderer * renderer);
		void invertDirections(int x, int y, SDL_Renderer * renderer);
		int getX();
		int getY();
};

#endif
