// This class is going to the principal datastructure holding
// all of the necessary data that goes into drawing the maze
// 
// Positions of any game object are determined by their relative
// positions in the maze, the output of the program will be the maze
// when a player inputs to move it must verify collisions with other
// adjacent elements in the maze

#ifndef MAZE_HPP
#define MAZE_HPP

#include "Player.hpp"
#include "GameObject.hpp"
#include "EventHander.hpp"
#include "Ghost.hpp"
#include <atomic>
#include <iostream>
#include <cstdlib>
#include <fstream>

class Maze {
    public:
        //
        // CONSTRUCTORS
        //

        Maze();

        //
        // MOVE PLAYER
        //
        void getInput();

        void moveObject(int &xCoordinate, int &yCoordinate);

        void printMaze();

        //
        //
        //

        bool isRunning();

    private:
        std::vector<std::vector<std::vector<GameObject>>> contents; // vector storing objects in the game by row and column
        friend std::ostream & operator<<(std::ostream &os, Maze &maze);
        friend std::ifstream & operator>>(std::ifstream &is, Maze &maze);
        GameObject *player;
        GameObject *blinky;
        Ghost blinkyGhostType;
        std::atomic<bool> running;
        char direction;
        int tickRate = 2;
};

#endif