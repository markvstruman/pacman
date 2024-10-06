#ifndef GHOST_HPP
#define GHOST_HPP

#include "GameObject.hpp"
#include <queue>

class Ghost : public GameObject {
    public:
        Ghost();

        Ghost(int xCoordinate_in, int yCoordinate_in);

        void chase(int &pacManXCoord, int &pacManYCoord, std::vector<std::vector<std::vector<GameObject>>> &maze);

        std::vector<char> getMoves();

        void moveGhost(std::vector<std::vector<std::vector<GameObject>>> &contents);

    private:
        std::vector<char> moves;
        std::vector<uint> discovered;
        int behaviorMode;
};

#endif