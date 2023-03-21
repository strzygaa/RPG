#include "Turntaker.hpp"
#include "gameboard.hpp"
#include "strangeboard.hpp"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int x = 0;
int y = 0;
void read(string c) {
  fstream jajco;
  jajco.open(c.c_str());

  if (jajco.is_open()) {
    jajco >> x;
    jajco >> y;
  }
  jajco.close();
}
int main() {
  read("//home//paro//game//jajco.txt");
  int wybor = 0;
  cout << "Wybierz planszę: 1 - plansza normalna, 2 - plansza specjalna"
       << endl;
  cin >> wybor;
  gameboard board1{x, y};
  strangeboard board2{x, y};
  Turntaker turns{board1, board2};
  turns.turn(wybor);

  return 0;
}