#include "gameboard.hpp"
#include "strangeboard.hpp"
#pragma once
#include <vector>
using namespace std;

class Turntaker {
public:
  gameboard &board1;
  strangeboard &board2;
  Turntaker(gameboard &board1, strangeboard &board2);
  void turn(int wybor);
};