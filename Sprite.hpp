#ifndef SPRITE_HPP
#define SPRITE_HPP
#include <vector>
#include <string>

const int spriteHeight = 3; // character height is roughly 1.5x its width so need to account for this in ascii sprites 
const int spriteWidth = 6;

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
        
        void createGhostSprite();
    private:
        std::vector<std::string> spriteData; // each index is a row of the sprite and each string is the characters of that row of 'pixels' (chars)
};

#endif