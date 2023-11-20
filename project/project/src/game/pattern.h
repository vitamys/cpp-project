#ifndef PATTERN_H
#define PATTERN_H

#include <vector>

class Patterns {
public:
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
