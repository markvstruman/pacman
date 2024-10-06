#include "Player.hpp"
#include <iostream>

Player::Player():
    GameObject(-1, -1, 'p') {}

Player::Player(int x_coord_in, int y_coord_in):
    GameObject(x_coord_in, y_coord_in, 'p') {}