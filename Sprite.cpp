#include "Sprite.hpp"

Sprite::Sprite()
    : spriteData(spriteHeight, " ") {}

Sprite::Sprite(char identity) {
    if (identity == 'w') {
        createWallSprite();
    }
    else if (identity == ' ') {
        createFloorSprite();
    }
    else if (identity == 'p') {
        createPacmanSprite();
    }
}

void Sprite::setSpriteData(std::vector<std::string> &spriteDataIn) {
    spriteData = spriteDataIn;
}

std::vector<std::string> Sprite::getSpriteData() {
    return spriteData;
}

void Sprite::createWallSprite() {
    for (int r = 0; r < spriteHeight; r++) {
        spriteData.push_back("");
        for (int c = 0; c < spriteWidth; c++) {
            spriteData[r].push_back('#');
        }
    }
}

void Sprite::createPacmanSprite() {
    createFloorSprite();
    for (int i = 1; i < spriteWidth-1; i++) {
        spriteData[0][i] = '#';
        spriteData[spriteHeight-1][i] = '#';
    }
    for (int i = 1; i < spriteHeight-1; i++) {
        spriteData[i][0] = '#';
        spriteData[i][spriteWidth-1] = '#';
    }
}

void Sprite::createFloorSprite() {
    for (int r = 0; r < spriteHeight; r++) {
        spriteData.push_back("");
        for (int c = 0; c < spriteWidth; c++) {
            spriteData[r].push_back(' ');
        }
    }
}