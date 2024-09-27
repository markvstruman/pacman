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

void Maze::movePlayer() {
    if (direction == 'w') {
        if (playerYCoordinate-1 < 0) {
            GameObject tempObject = contents[(int) contents.size()-1][playerXCoordinate];
            contents[(int) contents.size()-1][playerXCoordinate] = contents[playerYCoordinate][playerXCoordinate];
            contents[playerYCoordinate][playerXCoordinate] = tempObject;
            playerYCoordinate = (int) contents.size()-1;
        }
        else {
            GameObject tempObject = contents[playerYCoordinate-1][playerXCoordinate];

            if (tempObject.getIdentity() == 'w') {
                direction = ' ';
                return;
            }

            contents[playerYCoordinate-1][playerXCoordinate] = contents[playerYCoordinate][playerXCoordinate];
            contents[playerYCoordinate][playerXCoordinate] = tempObject;
            playerYCoordinate--;
            }
    }
    else if (direction == 's') {
        if (playerYCoordinate+1 > (int) contents.size()-1) {
            GameObject tempObject = contents[0][playerXCoordinate];
            contents[0][playerXCoordinate] = contents[playerYCoordinate][playerXCoordinate];
            contents[playerYCoordinate][playerXCoordinate] = tempObject;
            playerYCoordinate = 0;
        }
        else {    
            GameObject tempObject = contents[playerYCoordinate+1][playerXCoordinate];

            if (tempObject.getIdentity() == 'w') {
                direction = ' ';
                return;
            }

            contents[playerYCoordinate+1][playerXCoordinate] = contents[playerYCoordinate][playerXCoordinate];
            contents[playerYCoordinate][playerXCoordinate] = tempObject;
            playerYCoordinate++;}
    }
    else if (direction == 'd') {
        if (playerXCoordinate+1 > (int) contents[0].size()-1) {
            GameObject tempObject = contents[playerYCoordinate][0];
            contents[playerYCoordinate][0] = contents[playerYCoordinate][playerXCoordinate];
            contents[playerYCoordinate][playerXCoordinate] = tempObject;
            playerXCoordinate = 0;
        }
        else {
            GameObject tempObject = contents[playerYCoordinate][playerXCoordinate+1];

            if (tempObject.getIdentity() == 'w') {
                direction = ' ';
                return;
            }
                
            contents[playerYCoordinate][playerXCoordinate+1] = contents[playerYCoordinate][playerXCoordinate];
            contents[playerYCoordinate][playerXCoordinate] = tempObject;
            playerXCoordinate++;
            }
    }
    else if (direction == 'a') {
        if (playerXCoordinate-1 < 0) {
            GameObject tempObject = contents[playerYCoordinate][(int) contents[0].size()-1];
            contents[playerYCoordinate][(int) contents[0].size()-1] = contents[playerYCoordinate][playerXCoordinate];
            contents[playerYCoordinate][playerXCoordinate] = tempObject;
            playerXCoordinate = (int) contents[0].size()-1;
        }
        else {
            GameObject tempObject = contents[playerYCoordinate][playerXCoordinate-1];

            if (tempObject.getIdentity() == 'w') {
                direction = ' ';
                return;
            }

            contents[playerYCoordinate][playerXCoordinate-1] = contents[playerYCoordinate][playerXCoordinate];
            contents[playerYCoordinate][playerXCoordinate] = tempObject;
            playerXCoordinate--;
        }
    }
}


void Maze::printMaze() {
    while(running) {
        Clear();
        movePlayer();
        cout << *(this);
        this_thread::sleep_for(chrono::milliseconds((int)(1E2*+tickRate)));
    }
}

std::ostream & operator<<(std::ostream &os, Maze &maze) {
    for (std::vector<GameObject> &row: maze.contents) {
        for (int spriteRow = 0; spriteRow < spriteHeight; spriteRow++) {
            for (GameObject &obj: row) {
                os << obj.getSprite().getSpriteData()[spriteRow];
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
            if (objectIdentifier[i] == '#') {
                maze.contents[row].push_back(GameObject('w'));
            }
            else if (objectIdentifier[i] == ' ') {
                maze.contents[row].push_back(GameObject(' '));
            }
            else if (objectIdentifier[i] == 'S') {
                maze.contents[row].push_back(Player(row, column));
                maze.playerXCoordinate = column;
                maze.playerYCoordinate = row;
            }
            else if (objectIdentifier[i] == 'G') {
                maze.contents[row].push_back(GameObject('g'));
            }
            column++;
        }
        row++;
    }

    return is;
}