#ifndef PLAYER_HPP
#include "GameObject.hpp"

class Player : public GameObject {
    public:
        Player();

        Player(int xCoord_in, int yCoord_in);

        //
        // GETTER FUNCTIONS
        //

        int getXCoordinate();

        int getYCoordinate();

    private:
        int score;
        int xCoordinate;
        int yCoordinate;
};

#endif