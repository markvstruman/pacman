#ifndef TERRAIN_HPP

#include "GameObject.hpp"

class Terrain : public GameObject {
    public:
        Terrain();

        void generateTerrain();

    private:
        Sprite sprite;
        bool passable; // determines whether collision stops the player or they can pass through it
        friend std::ostream & operator<<(std::ostream &os, GameObject &object);
};

#endif