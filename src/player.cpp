#include "player.hpp"
#include <iostream>
#include <string>
#include <vector>

player::player(int x_max, int y_max)
    :

      playerx(0), playery(0), x(x_max), y(y_max), level(0), win(0){

                                                            };

void player::moveup() {
  if (playery > 0) {

    playery = playery - 1;
  }
}

void player::movedown() {
  if (playery + 1 < y) {

    playery = playery + 1;
  }
}

void player::moveleft() {
  if (playerx > 0) {
    playerx = playerx - 1;
  }
}

void player::moveright() {
  if (playerx + 1 < x) {
    playerx = playerx + 1;
  }
}
