// Main Menu

#include "../artifact/artifact.h"
#include "../gameboard/gameboard.h"
#include "../food/food.h"
#include "../snake/snake.h"
#include "../powerup/powerup.h"

#include <iostream>
#include <string>

#include <GL/glew.h>
#include <glfw3.h>

using namespace std;

void startGame() {
  string begin;
  while (startgame == false) {
    cin >> begin;
    // Welcome screen
    // On first launch, no games played yet
    if (isDead == false) {
      // Display "Press 'Space Bar' to start new game" and "Press 'esc' to quit" using OpenGL

    }
    // Game over screen
    // When a game has already been played
    else if (isDead == true) {
      // Display "Game Over", "Final Score: ", "Press 'Space Bar' to start new game" and "Press 'esc' to quit" using OpenGL

    }
    // Start new game when spacebar is pressed
    if (begin == " ")
      startgame = true;
  }
}
