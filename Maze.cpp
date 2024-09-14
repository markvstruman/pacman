#include "Maze.hpp"

Maze::Maze()
    : contents(30) {}

std::ostream & operator<<(std::ostream &os, Maze &maze) {
    for (int row = 0; row < 30; row++) {
        for (int spriteRow = 0; spriteRow < spriteHeight; spriteRow++) {
            for (GameObject &obj: maze.contents[row]) {
                os << obj.getSprite().getSpriteData()[spriteRow];
            }
            os << '\n';
        }
    }

    return os;
}

std::ifstream & operator>>(std::ifstream &is, Maze &maze) {
    std::string objectIdentifier;
    int index = 0;
    while (getline(is, objectIdentifier)) {
        for (size_t i = 0; i < objectIdentifier.length(); i++) {
            if (objectIdentifier[i] == '#') {
                maze.contents[index].push_back(GameObject('w'));
            }
            else if (objectIdentifier[i] == ' ') {
                maze.contents[index].push_back(GameObject(' '));
            }
            else if (objectIdentifier[i] == 'p') {
                maze.contents[index].push_back(GameObject('p'));
            }
        }
        index++;
    }

    return is;
}