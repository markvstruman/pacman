#ifndef GAMEOBJECT_HPP
#include <iostream>
#include "Sprite.hpp"

class GameObject {
    public:
        //
        // CONSTRUCTORS
        //

        GameObject();

        GameObject(char identity_in);

        //
        // GETTER FUNCTIONS
        //

        Sprite & getSprite();

    private:
        Sprite sprite;
        char identity; // can be determined as...
                        // 'p' ~ player
                        // 'w' ~ wall
                        // 'g' ~ ghost
                        // 'f' ~ fruit (when score added)
};

#endif