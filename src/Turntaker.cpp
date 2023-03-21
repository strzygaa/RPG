#include "Turntaker.hpp"
#include "gameboard.hpp"
#include "player.hpp"
#include "strangeboard.hpp"
#include <iostream>
#include <unistd.h>
#include <vector>
using namespace std;

Turntaker::Turntaker(gameboard &board1, strangeboard &board2)
    : board1(board1), board2(board2) {
  board1.generateboard();
  board2.generateboard();
};

void Turntaker::turn(int wybor) {
  if (wybor == 1) {

    while ((board1.checkwin() == false) && (board1.gameon == true)) {
      char key;
      board1.display();
      cin >> key;
      board1.player_movement(key);
      system("clear");
    }

    if (board1.checkwin() == true) {
      cout << "You've won" << endl;
    } else if (board1.gameon == false) {
      cout << "gameover" << endl;
    }
  }

  if (wybor == 2) {

    while ((board2.checkwin() == false) && (board2.gameon == true)) {
      char key;
      board2.display();
      cin >> key;
      board2.player_movement(key);
      system("clear");
    }

    if (board2.checkwin() == true) {
      cout << "You've won" << endl;
    } else if (board2.gameon == false) {
      cout << "gameover" << endl;
    }
  }
}