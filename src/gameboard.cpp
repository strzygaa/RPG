#include "gameboard.hpp"
#include "player.hpp"
#include <iostream>
#include <random>
#include <string>
#include <unistd.h>
#include <vector>

using namespace std;

gameboard::gameboard(int width, int height)
    : height(height), width(width), gameon(true), player1(width, height),
      board((height * width), Field{false, false, false, false}){

      };

char gameboard::whichMark(int row, int col) const {
  if (getField(row, col).isplayer) {
    return 'X';
  } else if (getField(row, col).ismonster) {
    return 'M';
  } else if (getField(row, col).isgold) {
    return 'G';
  } else if (getField(row, col).isboss) {
    return 'B';
  } else {
    return ' ';
  }
}

void gameboard::display() {
  system("clear");
  cout << "In order to win the game you have to kill all monsters" << endl;
  cout << "To kill regular monster you have to be on 3rd level" << endl;
  cout << "To kill the boss you have to be on 5th level" << endl;
  cout << "To level up collect gold" << endl;
  cout << "Goodluck!" << endl;
  cout << "Your level: " << player1.level << endl;
  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
      cout << whichMark(col, row);
    }

    cout << endl;
  }
}
void gameboard::generatemonster() {
  int v1;
  int v;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib_row(0, height - 1);
  std::uniform_int_distribution<> distrib_column(0, width - 1);
  int i = 0;
  while (i < 10) {
    v1 = distrib_row(gen);
    v = distrib_column(gen);
    if (getField(v1, v).ismonster == false) {
      getField(v1, v).ismonster = true;
      i++;
    }
  }
}
void gameboard::generategold() {
  int v1;
  int v;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib_row(0, height - 1);
  std::uniform_int_distribution<> distrib_column(0, width - 1);
  int i = 0;
  while (i < 6) {
    v1 = distrib_row(gen);
    v = distrib_column(gen);
    if (getField(v1, v).isgold == false) {
      getField(v1, v).isgold = true;
      i++;
    }
  }
}
void gameboard::generateboss() {
  int v1;
  int v;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib_row(0, height - 1);
  std::uniform_int_distribution<> distrib_column(0, width - 1);
  int i = 0;
  while (i < 2) {
    v1 = distrib_row(gen);
    v = distrib_column(gen);
    if (getField(v1, v).isboss == false) {
      getField(v1, v).isboss = true;
      i++;
    }
  }
}

Field &gameboard::getField(int row, int col) {
  return board[col + row * height];
}

const Field &gameboard::getField(int row, int col) const {
  return board[col + row * height];
}
int gameboard::getBoardHeight() { return height; }

int gameboard::getBoardWidth() { return width; }
void gameboard::generateplayer() {

  getField(player1.playerx, player1.playery).isplayer = true;
}
void gameboard::player_movement(char key) {
  int old_x = player1.playerx;
  int old_y = player1.playery;
  goldup();

  switch (key) {
  case 'w':
    player1.moveup();
    break;
  case 'a':
    player1.moveleft();
    break;
  case 's':
    player1.movedown();
    break;
  case 'd':
    player1.moveright();
    break;
  default:
system("clear");
    cout << "Please use WASD keys to move player" << endl;
    break;
  }
  killmonster();
  killboss();
  getField(old_x, old_y).isplayer = false;
  getField(player1.playerx, player1.playery).isplayer = true;
}

void gameboard::goldup() {
  if (getField(player1.playerx, player1.playery).isgold == true) {
    getField(player1.playerx, player1.playery).isgold = false;
    player1.level++;

  } else {
    return;
  }
}

void gameboard::killmonster() {
  if (getField(player1.playerx, player1.playery).ismonster == true) {
    if (player1.level > 2) {
      getField(player1.playerx, player1.playery).ismonster = false;
      player1.win++;
    }

    else {
      gameon = false;
    }
  }

  else {
    return;
  }
}
void gameboard::killboss() {
  if (getField(player1.playerx, player1.playery).isboss == true) {
    if (player1.level > 4) {
      getField(player1.playerx, player1.playery).isboss = false;
      player1.win++;
    } else {
      gameon = false;
    }
  }

  else {
    return;
  }
}
bool gameboard::checkwin() {
  if (player1.win == 12) {
    gameon = false;
    return true;
  }
  return false;
}
void gameboard::generateboard() {
  generatemonster();
  generategold();
  generateboss();
  generateplayer();
}
