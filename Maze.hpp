// This class is going to the principal datastructure holding
// all of the necessary data that goes into drawing the maze
// 
// Positions of any game object are determined by their relative
// positions in the maze, the output of the program will be the maze
// when a player inputs to move it must verify collisions with other
// adjacent elements in the maze

#ifndef MAZE_HPP
#include "GameObject.hpp"

class Maze {

    private:
        std::vector<std::vector<GameObject>> contents; // vector storing objects in the game by row and column
        int sideLength; // length of the maze

        friend std::ostream & operator<<(std::ostream &os, Maze &maze);
        friend std::istream & operator>>(std::istream &is, Maze &maze);
};

#endif