#include "Player.hpp"
#include <iostream>

Player::Player():
    GameObject('p'), xCoordinate(-1), yCoordinate(-1) {}

Player::Player(int x_coord_in, int y_coord_in):
    GameObject('p'), xCoordinate(x_coord_in), yCoordinate(y_coord_in) {}

int Player::getXCoordinate() {
    return xCoordinate;
}

int Player::getYCoordinate() {
    return yCoordinate;
}