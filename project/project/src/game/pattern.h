#ifndef PATTERN_H
#define PATTERN_H

#include <vector>
#include <QString>
using namespace std;

class Patterns {
public:
    static std::vector<std::vector<char>> patternByName(const QString& name) {
        if( name== "blockButton"){
            return block();
        }
        else if (name == "beehiveButton") {
            return beehive();
        } else if (name == "loafButton") {
            return loaf();
        } else if (name == "boatButton") {
            return boat();
        } else if (name == "tubButton") {
            return tub();
        }
        else if (name == "beaconButton") {
            return beacon();
        } else if (name == "blinkerButton") {
            return blinker();

        } else if (name == "toadButton") {
            return toad();
        } else if (name == "gliderButton") {
            return glider();

        } else if (name == "gliderButton") {
            return glider();

        } else if (name == "lwssButton") {
            return lwss();

        } else if (name == "mwssButton") {
            return mwss();
        }else if (name == "pipentominoButton") {
            return piPentomino();
        } else if (name == "wingButton") {
            return wing();
        } else if (name == "acornButton") {
            return acorn();
        }else {
            // return toad as default

            return toad();
        }
    }
    //static patterns (still lives)
    static std::vector<std::vector<char>> block() {
        return {
            {'X', 'X' },
            {'X', 'X'},
        };
    }
    static std::vector<std::vector<char>> beehive() {
        return {
            {' ', 'X', 'X', ' '},
            {'X', ' ', ' ', 'X'},
            {' ', 'X', 'X', ' '},
        };
    }

    static std::vector<std::vector<char>> loaf() {
        return {
            {' ', 'X', 'X', ' '},
            {'X', ' ', ' ', 'X'},
            {' ', 'X', ' ', 'X'},
            {' ', ' ', 'X', ' '},
        };
    }

    static std::vector<std::vector<char>> boat() {
        return {
            {'X', 'X', ' ',},
            {'X', ' ', 'X',},
            {' ', 'X', ' ',},
        };
    }

    static std::vector<std::vector<char>> tub() {
        return {
            {' ', 'X', ' ',},
            {'X', ' ', 'X',},
            {' ', 'X', ' ',},
        };
    }
    //oscillators
    static std::vector<std::vector<char>> beacon() {
        return {
            {'X', 'X', ' ',' '},
            {'X', 'X', ' ',' '},
            {' ', ' ', 'X', 'X'},
            {' ', ' ', 'X', 'X'},
        };
    }
    static std::vector<std::vector<char>> blinker() {
        return {
            {'X', 'X', 'X'},
        };
    }
    static std::vector<std::vector<char>> toad() {
        return {
            {' ', 'X', 'X','X'},
            {'X', 'X', 'X',' '},
        };
    }
    //gliders
    static std::vector<std::vector<char>> glider() {
        return {
            {' ', 'X', ' '},
            {' ', ' ', 'X'},
            {'X', 'X', 'X'}
        };
    }

    static std::vector<std::vector<char>> lwss() {
        return {
            {' ', 'X', 'X',' ', ' '},
            {'X', 'X', 'X','X', ' '},
            {'X', 'X', ' ', 'X','X'},
            {' ', ' ', 'X', 'X', ' '},
        };
    }
    static std::vector<std::vector<char>> mwss() {
        return {
            {' ', 'X', 'X', 'X', ' ', ' '},
            {'X', 'X', 'X', 'X', 'X', ' '},
            {'X', 'X', 'X', ' ', 'X', 'X'},
            {' ', ' ', ' ', 'X', 'X', ' '},
        };
    }

    //methuselas
    static std::vector<std::vector<char>> piPentomino() {
        return {
            {'X', 'X', 'X'},
            {'X', ' ', 'X'},
            {'X', ' ', 'X'},
        };
    }

    static std::vector<std::vector<char>> wing() {
        return {
            {' ', 'X', 'X', ' '},
            {'X', ' ', ' ', 'X'},
            {' ', 'X', ' ', 'X'},
            {' ', ' ', 'X', 'X'},
        };
    }

    static std::vector<std::vector<char>> acorn() {
        return {
            {' ', 'X', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', 'X', ' ', ' ', ' ', ' '},
            {'X', 'X', ' ', ' ', 'X', 'X', 'X', ' '},
        };
    }

};

#endif // PATTERN_H
