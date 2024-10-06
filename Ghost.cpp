#include "Ghost.hpp"

Ghost::Ghost() 
: GameObject(), moves(), behaviorMode() {}

Ghost::Ghost(int xCoordinate_in, int yCoordinate_in)
: GameObject(xCoordinate_in, yCoordinate_in, 'g') {}

void Ghost::moveGhost(std::vector<std::vector<std::vector<GameObject>>> &contents) {
    if (moves.empty()) {
        return;
    }
    char direction = moves.back();
    moves.pop_back();
    if (direction == 'n') {
        // if its going out of bounds (i.e. across portal to other end of map)
        if (yCoordinate-1 < 0) {
            contents[(int) contents.size()-1][xCoordinate].push_back(contents[yCoordinate][xCoordinate][1]);
            contents[yCoordinate][xCoordinate].pop_back();
            yCoordinate = (int) contents.size()-1;
        }

        // else
        else {
            // if its a wall
            if (contents[yCoordinate-1][xCoordinate][0].getIdentity() == 'w') {
                direction = ' ';
                return;
            }

            // anything but a wall
            contents[yCoordinate-1][xCoordinate].push_back(contents[yCoordinate][xCoordinate][1]);
            contents[yCoordinate][xCoordinate].pop_back();
            yCoordinate--;
            }
    }

    // south
    else if (direction == 's') {
        // if its going out of bounds (i.e. across portal to other end of map)
        if (yCoordinate+1 > (int) contents.size()-1) {
            contents[0][xCoordinate].push_back(contents[yCoordinate][xCoordinate][1]);
            contents[yCoordinate][xCoordinate].pop_back();
            yCoordinate = 0;
        }
        
        // else
        else {
            // if its a wall
            if (contents[yCoordinate+1][xCoordinate][0].getIdentity() == 'w') {
                direction = ' ';
                return;
            }

            // anything but a wall
            contents[yCoordinate+1][xCoordinate].push_back(contents[yCoordinate][xCoordinate][1]);
            contents[yCoordinate][xCoordinate].pop_back();
            yCoordinate++;
        }
    }

    // if east
    else if (direction == 'e') {
        if (xCoordinate+1 > (int) contents[0].size()-1) {
            contents[yCoordinate][0].push_back(contents[yCoordinate][xCoordinate][1]);
            contents[yCoordinate][xCoordinate].pop_back();
            xCoordinate = 0;
        }
        else {
            // if its a wall
            if (contents[yCoordinate][xCoordinate+1][0].getIdentity() == 'w') {
                direction = ' ';
                return;
            }

            // anything but a wall
            contents[yCoordinate][xCoordinate+1].push_back(contents[yCoordinate][xCoordinate][1]);
            contents[yCoordinate][xCoordinate].pop_back();
            xCoordinate++;
            }
    }

    // if west
    else if (direction == 'w') {
        if (xCoordinate-1 < 0) {
            contents[yCoordinate][(int) contents[0].size()-1].push_back(contents[yCoordinate][xCoordinate][1]);
            contents[yCoordinate][xCoordinate].pop_back();
            xCoordinate = (int) contents[0].size()-1;
        }
        // if its a wall
        else {
            if (contents[yCoordinate][xCoordinate-1][0].getIdentity() == 'w') {
                direction = ' ';
                return;
            }

            // anything but a wall
            contents[yCoordinate][xCoordinate-1].push_back(contents[yCoordinate][xCoordinate][1]);
            contents[yCoordinate][xCoordinate].pop_back();
            xCoordinate--;
        }
    }
}

std::vector<char> Ghost::getMoves() {
    return moves;
}

void Ghost::chase(int &pacManXCoord, int &pacManYCoord, std::vector<std::vector<std::vector<GameObject>>> &maze) {
    if (moves.empty()) {
        std::queue<int> discovered;
        int r,c,id;
        int length = (int) maze.size();
        int height = (int) maze[0].size();

        std::vector<uint> investigated(length*height+1, length*height+1);
        investigated[yCoordinate*length + xCoordinate] = length*height+1;
        uint defaultId = length*height+1;

        discovered.push((xCoordinate + yCoordinate*length));

        while (!discovered.empty()) {
            int startingLocation = discovered.front();
            r = startingLocation/length;
            c = startingLocation%length;
            id = r*length + c;

            if (r == pacManYCoord && c == pacManXCoord) {
                break;
            }
            discovered.pop();

            //
            // NORTH
            //

            // check if its within bounds
            if (r - 1 > -1) {
                // check if its a wall
                if (maze[r-1][c][0].getIdentity() != 'w' && (investigated[((r-1)*length) + c] == defaultId)) {
                    discovered.push((r-1)*length+c);
                    investigated[((r-1)*length) + c] = id;
                }
            }

            //
            // EAST
            //

            if (c + 1 < length) {
                // check if its a wall
                if (maze[r][c+1][0].getIdentity() != 'w' && (investigated[(r*length) + (c+1)] == defaultId)) {
                    discovered.push((r*length) + (c+1));
                    investigated[(r*length) + (c+1)] = id;
                }
            }

            //
            // SOUTH
            //

            if (r + 1 < length) {
                // check if its a wall
                if (maze[r+1][c][0].getIdentity() != 'w' && (investigated[((r+1)*length) + (c)] == defaultId)) {
                    discovered.push(((r+1)*length) + (c));
                    investigated[((r+1)*length) + (c)] = id;
                }
            }

            //
            // WEST
            //

            if (c - 1 > -1) {
                // check if its a wall
                if (maze[r][c-1][0].getIdentity() != 'w' && (investigated[(r*length) + (c-1)] == defaultId)) {
                    discovered.push((r*length) + (c-1));
                    investigated[(r*length) + (c-1)] = id;
                }
            }
        }

        int startId = (yCoordinate*length) + xCoordinate;

        while (id != startId) {
            if (id - (int) investigated[id] == 1) {
                moves.push_back('e');
            }
            else if (id - (int) investigated[id] == -1) {
                moves.push_back('w');
            }
            else if (id - (int) investigated[id] == length) {
                moves.push_back('s');
            }
            else if (id - (int) investigated[id] == (length*-1)) {
                moves.push_back('n');
            }
            id = investigated[id];
        }
    }
}