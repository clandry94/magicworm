#include <iostream>
#include "../artifact/artifact.h"
#include "../gameboard/gameboard.h"
#include "../food/food.h"
#include "../snake/snake.h"
#include "../powerup/powerup.h"

using namespace std;

public class gameboard {
	bool startGame;
	int score;
	snake snake;
	food food;
	powerup powerup;

	gameboard(){}
	bool checkStart(){}
	void checkPosition(){}
	void startGame(){}
	void stopGame(){}
	int getScore(){}
	void setScore(int newscore){}
	void printScore(){}

	gameboard(){
		startGame = false;
		score = 0;
		snake = new snake();
		food = new food();
		powerup = new powerup();
	}

	void startGame(){
		startGame = true;
	}
	void stopGame(){
		startGame = false;
	}
	bool checkStart(){
		if(startGame == true){
			return true;
		}
		else if(startGame == false){
			return false;
		}
	}
	void checkPosition(){
		if(snake.getX() == food.getX() && snake.getY() == food.getY()){
			score += 1;
			snake.incrementSize();
			food.generateFood();
			food.eraseFood();
		}
		if(snake.getX() == powerup.getX() && snake.getY() == snake.getY()){
			powerup.erasePowerup();
		}
	}
	int getScore(){
		return score;
	}
	void setScore(int newscore){
		score = newscore;
	}
	void printScore(){
		//to be implemented
	}
}