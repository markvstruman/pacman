#ifndef GAMEOBJECT_HPP
#include <iostream>
#include "Sprite.hpp"

class GameObject {
    public:
        GameObject();

    private:
        Sprite sprite;
        int xCoordinate;
        int yCoordinate;
        char identity; // can be determined as...
                        // 'p' ~ player
                        // 'w' ~ wall
                        // 'g' ~ ghost
                        // 'f' ~ fruit (when score added)
        friend std::ostream & operator<<(std::ostream &os, GameObject &object);
};

#endif