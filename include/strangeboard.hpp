#include "gameboard.hpp"
#include <vector>
#pragma once
using namespace std;

class strangeboard : public gameboard {
public:
  using gameboard::gameboard;
  void generatemonster() override;
  void generategold() override;
  bool checkwin() override;
};