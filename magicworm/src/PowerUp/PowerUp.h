#ifndef POWERUP_H_
#define POWERUP_H_

class PowerUp {
	private:

		int powerUpX;
		int powerUpY;
		SDL_Renderer * renderer;
		Snake * snake;

	public:
		PowerUp(SDL_Renderer * irenderer, Snake * isnake);
		void placePowerUp();
		void removePowerUp();
		void speedUp(int x, int y);
		void slowDown(int x, int y);
		void changeColor(int x, int y);
		void extraFood(int x, int y);
		void minusScore(int x, int y);
		void invertDirections(int x, int y);
		int getX();
		int getY();
		bool isPowerUp;
};

#endif
