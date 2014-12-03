
#ifndef ARTIFACT_H
#define ARTIFACT_H
struct artifact {

  artifact(int x, int y, int type, std::string color);
  int x;
  int y;
  int type; //1 = snake, 2 = food, 3 = powerup
  std::string color;

};

#endif
