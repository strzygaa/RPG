#include "player.hpp"

#pragma once
#include <vector>

using namespace std;

struct Field {
  bool ismonster;
  bool isboss;
  bool isgold;
  bool isplayer;
};

class gameboard {
public:
  int height;
  int width;
  bool gameon;
  player player1;
  vector<Field> board;

  Field &getField(int row, int col);
  const Field &getField(int row, int col) const;

  gameboard(int width, int height);
  virtual void display();
  char whichMark(int row, int col) const;
  void generateboard();
  virtual void generatemonster();
  virtual void generategold();

  void generateplayer();
  void generateboss();

  int getBoardWidth();
  int getBoardHeight();

  void player_movement(char key);

  void goldup();
  void killmonster();
  void killboss();
  void gameover();
  virtual bool checkwin();
};
