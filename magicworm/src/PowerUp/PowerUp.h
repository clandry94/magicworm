#ifndef POWERUP_H_
#define POWERUP_H_

class PowerUp {
	private:
		int powerUpX;
		int powerUpY;
		SDL_Renderer * renderer;
		Snake * snake;
		bool isSpedUp;
		bool isSlowedDown;
		void removePowerUp();
		void speedUp();
		void slowDown();
		void changeColor();
		void extraFood();
		void minusScore();
		void invertDirections();
		void deactivatePowerUp();
		int startTime;
		void randomNumbers();
		int whichPowerUp;
		int counter;

	public:
		PowerUp(SDL_Renderer * irenderer, Snake * isnake);
		void placePowerUp();
		int getX();
		int getY();
		bool isPowerUp;
};

#endif
