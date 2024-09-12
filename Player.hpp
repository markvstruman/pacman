#ifndef PLAYER_HPP

#include "GameObject.hpp"

class Player : public GameObject {
    public:
        Player();

        void inputLeft();

        void inputRight();

        void inputUp();

        void inputDown();
    private:
        int score;
};

#endif