#include "Maze.hpp"

//
void Clear()
{
#if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
#elif defined (__APPLE__)
    system("clear");
#endif
}
//

Maze::Maze()
    : running(true) {}

bool Maze::isRunning() {
    return running;
}

void Maze::getInput() {
    while(running) {
        char input = (char) EventHander::key_press();
        if (input == 'w') 
            direction = 'w';
        else if (input == 's') {
            direction = 's';
        }
        else if (input == 'd') {
            direction = 'd';
        }
        else if (input == 'a') {
            direction = 'a';
        }
        else if (input == 'x') {
            running = false;
        }
    }
}

void Maze::moveObject(int &xCoordinate, int &yCoordinate) {
    // north
    if (direction == 'w') {
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
    else if (direction == 'd') {
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
    else if (direction == 'a') {
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


void Maze::printMaze() {
    while(running) {
        Clear();
        moveObject(player->getYCoordinate(), player->getXCoordinate());
        if (blinkyGhostType.getMoves().empty()) {
            blinkyGhostType.chase(player->getXCoordinate(), player->getYCoordinate(), contents);
        }
        blinkyGhostType.moveGhost(contents);
        cout << *(this);
        this_thread::sleep_for(chrono::milliseconds((int)(1E2*+tickRate)));
    }
}

std::ostream & operator<<(std::ostream &os, Maze &maze) {
    for (std::vector<std::vector<GameObject>> &row: maze.contents) {
        for (int spriteRow = 0; spriteRow < spriteHeight; spriteRow++) {
            for (std::vector<GameObject> &obj: row) {
                if (obj.size() == 2) {
                    os << obj[1].getSprite().getSpriteData()[spriteRow];
                }
                else {
                    os << obj[0].getSprite().getSpriteData()[spriteRow];
                }
            }
            os << '\n';
            os.flush();
        }
    }
    return os;
}

std::ifstream & operator>>(std::ifstream &is, Maze &maze) {
    std::string objectIdentifier;
    int row = 0;
    while (getline(is, objectIdentifier)) {
        maze.contents.push_back({});
        int column = 0;
        for (size_t i = 0; i < objectIdentifier.length(); i++) {
            maze.contents[row].push_back({});
            if (objectIdentifier[i] == '#') {
                maze.contents[row][column].push_back({GameObject('w')});
            }
            else if (objectIdentifier[i] == ' ') {
                maze.contents[row][column].push_back({GameObject(' ')});
            }
            else if (objectIdentifier[i] == 'S') {
                maze.contents[row][column].push_back({GameObject(' ')});
                maze.contents[row][column].push_back({Player(row, column)});
                maze.player = &maze.contents[row][column][1];
            }
            else if (objectIdentifier[i] == 'G') {
                maze.contents[row][column].push_back({GameObject(' ')});
                maze.contents[row][column].push_back({Ghost(row, column)});
                maze.blinky = &maze.contents[row][column][1];
                maze.blinkyGhostType = Ghost(column, row);
            }
            column++;
        }
        row++;
    }

    return is;
}