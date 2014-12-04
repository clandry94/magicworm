// Main Menu

#include <menu.h>

void Menu::mainMenu() {
  cin >> begin;
  // Welcome screen
  // On first launch, no games played yet
  if (isDead == false) {
    // Display "Press 'Space Bar' to start new game" and "Press 'esc' to quit" using SDL

  }
  // Game over screen
  // When a game has already been played
  else if (isDead == true) {
    // Display "Game Over", "Final Score: ", "Press 'Space Bar' to start new game" and "Press 'esc' to quit" using SDL

  }
  // Start new game when spacebar is pressed
  if (begin == " ")
    startgame = true;
}
