#ifndef SPRITE_HPP

#include <vector>
#include <string>

const int spriteHeight = 4; // character height is roughly 1.5x its width so need to account for this in ascii sprites 
const int spriteWidth = 8;

class Sprite {
    public:
        //
        // CONSTRUCTORS
        //

        Sprite();

        Sprite(char identity);

        //
        // SETTER FUNCTIONS
        //
        void setSpriteData(std::vector<std::string> &spriteData_in);

        //
        // GETTER FUNCTIONS
        //
        std::vector<std::string> getSpriteData();

        //
        // ESSENTIAL FUNCTIONS
        //

        void createWallSprite();
        
        void createPacmanSprite();

        void createFloorSprite();
    private:
        std::vector<std::string> spriteData; // each index is a row of the sprite and each string is the characters of that row of 'pixels' (chars)
};

#endif