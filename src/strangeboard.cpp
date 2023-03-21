#include "strangeboard.hpp"
#include "player.hpp"
#include <iostream>
#include <random>
#include <string>
#include <unistd.h>
#include <vector>

using namespace std;

void strangeboard::generatemonster() {
  int v1;
  int v;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib_row(0, height - 1);
  std::uniform_int_distribution<> distrib_column(0, width - 1);
  int i = 0;
  while (i < 1) {
    v1 = distrib_row(gen);
    v = distrib_column(gen);
    if (getField(v1, v).ismonster == false) {
      getField(v1, v).ismonster = true;
      i++;
    }
  }
}
void strangeboard::generategold() {
  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
      getField(col, row).isgold = true;
    }
  }
}
bool strangeboard::checkwin() {
  if (player1.win == 1) {
    gameon = false;
    return true;
  }
  return false;
}