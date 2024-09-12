#include "Sprite.hpp"

Sprite::Sprite()
    : spriteData(4, "$$$$") {}

void Sprite::setSpriteData(std::vector<std::string> &spriteDataIn) {
    spriteData = spriteDataIn;
}

std::vector<std::string> Sprite::getSpriteData() {
    return spriteData;
}