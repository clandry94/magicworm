#ifndef POWERUP_H_
#define POWERUP_H_

class PowerUp {
	private:
		PowerUp();
		void placePowerUp();
		void removePowerUp();

	public:
		void speedUp(int x, int y);
		void slowDown(int x, int y);
		void changeColor(int x, int y);
		void extraFood(int x, int y);
		void minusScore(int x, int y);
		void invertDirections(int x, int y);
		bool isPowerUp;
};

#endif
