#include "GameObject.hpp"

GameObject::GameObject()
    : sprite(Sprite()), identity('$') {}

GameObject::GameObject(char identity_in) 
    : sprite(Sprite(identity_in)), identity(identity_in) {}

GameObject::GameObject(int xCoordinate_in, int yCoordinate_in, char identity_in)
    : sprite(Sprite(identity_in)), identity(identity_in), xCoordinate(xCoordinate_in), yCoordinate(yCoordinate_in) {}

Sprite & GameObject::getSprite() {
    return sprite;
}

char GameObject::getIdentity() {
    return identity;
}

int &GameObject::getXCoordinate() {
    return xCoordinate;
}

int &GameObject::getYCoordinate() {
    return yCoordinate;
}