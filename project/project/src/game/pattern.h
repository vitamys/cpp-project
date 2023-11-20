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
        } else {
            // Handle other patterns or return a default pattern

            return std::vector<std::vector<char>>(); // Returning an empty pattern for simplicity
        }
    }
    static std::vector<std::vector<char>> glider() {
        return {
            {' ', 'X', ' '},
            {' ', ' ', 'X'},
            {'X', 'X', 'X'}
        };
    }
    static std::vector<std::vector<char>> beacon() {
        return {
            {'X', 'X', ' ',' '},
            {'X', 'X', ' ',' '},
            {' ', ' ', 'X', 'X'},
            {' ', ' ', 'X', 'X'},
        };
    }
};

#endif // PATTERN_H
