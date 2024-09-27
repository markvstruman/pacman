#include "GameObject.hpp"

GameObject::GameObject()
    : sprite(Sprite()), identity('$') {}

GameObject::GameObject(char identity_in) 
    : sprite(Sprite(identity_in)), identity(identity_in) {}

Sprite & GameObject::getSprite() {
    return sprite;
}

char GameObject::getIdentity() {
    return identity;
}