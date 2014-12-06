#include <SDL2/SDL.h>

#ifndef NODE_H
#define NODE_H

struct Node {
  int x;
  int y;
  Node * next;

  Node(int iX, int iY) {
    x = iX;
    y = iY;
  }
  
};

#endif
