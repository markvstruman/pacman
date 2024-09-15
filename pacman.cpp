// PACMAN.CPP
// Going to be the driver of the program, all primary execution done in main
// Will likely involve multithreading to...
//    1) Get player input,
//    2) Move the ghosts according to their logic
//    3) Redraw the maze

#include <string>
#include <vector>
#include "Maze.hpp"
using namespace std;

// This function is already done.
int main() {
  // This should be in all of your projects, speeds up I/O
  ios_base::sync_with_stdio(false);
  ifstream inMazeFile("Maze.txt");
  Maze maze;
  inMazeFile >> maze;
  
  thread thread_1(&Maze::movePlayer, &maze);
  maze.printMaze();
  thread_1.join();

  return 0;
}