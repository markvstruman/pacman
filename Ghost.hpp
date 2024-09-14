#ifndef GHOST_HPP

#include "GameObject.hpp"

class Ghost : public GameObject {
    public:
        Ghost();

        void inputLeft();

        void inputRight();

        void inputUp();

        void inputDown();
    private:
        int behaviorMode;
        int xCoordinate;
        int yCoordinate;
};

#endif