
#ifndef ARTIFACT_H
#define ARTIFACT_H
struct artifact {

  artifact(int startX, int startY, int startType, std::string startColor) {
    x = startX;
    y = startY;
    type = startType;
    color = startColor;
  }
  
  int x;
  int y;
  int type; //1 = snake, 2 = food, 3 = powerup
  std::string color;

};

#endif
