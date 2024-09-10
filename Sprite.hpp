#ifndef SPRITE_HPP

#include <vector>
#include <string>

class Sprite {
    public:
        //
        // CONSTRUCTORS
        //

        Sprite();

        //
        // SETTER FUNCTIONS
        //
        void setSpriteData(std::vector<std::string> &spriteData_in);

        //
        // GETTER FUNCTIONS
        //
        std::vector<std::string> getSpriteData();
        
    private:
        std::vector<std::string> spriteData; // each index is a row of the sprite and each string is the characters of that row of 'pixels' (chars)        
};

#endif