#ifndef PATTERN_H
#define PATTERN_H

#include <vector>
#include <QString>
using namespace std;

class Patterns {
public:
    static std::vector<std::vector<char>> patternByName(const QString& name) {
        if (name == "beaconButton") {
            return beacon();
        } else if (name == "gliderButton") {
            return glider();

        } else if (name == "gliderButton") {
            return glider();

        } else if (name == "lwssButton") {
            return lwss();

        } else if (name == "blinkerButton") {
            return blinker();

        } else if (name == "toadButton") {
            return toad();
        } else {
            // Handle other patterns or return a default pattern

            return std::vector<std::vector<char>>(); // Returning an empty pattern for simplicity
        }
    }
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
};

#endif // PATTERN_H
