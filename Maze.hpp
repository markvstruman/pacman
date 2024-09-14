// This class is going to the principal datastructure holding
// all of the necessary data that goes into drawing the maze
// 
// Positions of any game object are determined by their relative
// positions in the maze, the output of the program will be the maze
// when a player inputs to move it must verify collisions with other
// adjacent elements in the maze

#ifndef MAZE_HPP
#include "GameObject.hpp"
#include <fstream>

class Maze {
    public:
        //
        // CONSTRUCTORS
        //

        Maze();

    private:
        std::vector<std::vector<GameObject>> contents; // vector storing objects in the game by row and column
        friend std::ostream & operator<<(std::ostream &os, Maze &maze);
        friend std::ifstream & operator>>(std::ifstream &is, Maze &maze);
};

#endif