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
		void speedUp();
		void slowDown();
		void changeColor();
		void extraFood();
		void minusScore();
		void invertDirections();
		int getX();
		int getY();
		bool isPowerUp;
};

#endif
