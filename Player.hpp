#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "GameObject.hpp"

class Player : public GameObject {
    public:

        Player();

        Player(int xCoordinate_in, int yCoordinate_in);

        //
        // GETTER FUNCTIONS
        //

    private:
        int score;
};

#endif