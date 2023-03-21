
#pragma once
#include <vector>
using namespace std;

class player {
public:
  int playerx;
  int playery;
  int x;
  int y;
  int level;
  int win;
  player(int x, int y);

  void moveup();
  void movedown();
  void moveleft();
  void moveright();
};