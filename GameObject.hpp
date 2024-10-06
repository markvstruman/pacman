#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP
#include <iostream>
#include "Sprite.hpp"

class GameObject {
    public:
        //
        // CONSTRUCTORS
        //

        GameObject();

        GameObject(char identity_in);

        GameObject(int xCoordinate_in, int yCoordinate_in, char identity_in);

        //
        // GETTER FUNCTIONS
        //

        Sprite & getSprite();

        virtual char getIdentity();

        int &getXCoordinate();

        int &getYCoordinate();

    protected:
        Sprite sprite;
        char identity; // can be determined as...
                        // 'p' ~ player
                        // 'w' ~ wall
                        // 'g' ~ ghost
                        // 'f' ~ fruit (when score added)
        int xCoordinate;
        int yCoordinate;
};

#endif