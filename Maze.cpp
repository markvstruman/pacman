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

void Maze::movePlayer() {
    while(running) {
        char direction = (char) EventHander::key_press();
        if (direction == 'w') {
            GameObject tempObject = contents[playerYCoordinate-1][playerXCoordinate];
            contents[playerYCoordinate-1][playerXCoordinate] = contents[playerYCoordinate][playerXCoordinate];
            contents[playerYCoordinate][playerXCoordinate] = tempObject;
            playerYCoordinate--;
        }
        else if (direction == 's') {
            GameObject tempObject = contents[playerYCoordinate+1][playerXCoordinate];
            contents[playerYCoordinate+1][playerXCoordinate] = contents[playerYCoordinate][playerXCoordinate];
            contents[playerYCoordinate][playerXCoordinate] = tempObject;
            playerYCoordinate++;
        }
        else if (direction == 'd') {
            GameObject tempObject = contents[playerYCoordinate][playerXCoordinate+1];
            contents[playerYCoordinate][playerXCoordinate+1] = contents[playerYCoordinate][playerXCoordinate];
            contents[playerYCoordinate][playerXCoordinate] = tempObject;
            playerXCoordinate++;
        }
        else if (direction == 'a') {
            GameObject tempObject = contents[playerYCoordinate][playerXCoordinate-1];
            contents[playerYCoordinate][playerXCoordinate-1] = contents[playerYCoordinate][playerXCoordinate];
            contents[playerYCoordinate][playerXCoordinate] = tempObject;
            playerXCoordinate--;
        }
        else if (direction == 'x') {
            running = false;
        }
    }
}

void Maze::printMaze() {
    while(running) {
        Clear();
        cout << *(this);
        this_thread::sleep_for(chrono::milliseconds((int)(1E2*+0.5)));
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