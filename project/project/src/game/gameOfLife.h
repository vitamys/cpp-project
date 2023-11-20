
#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include <vector>

class GameOfLife {
public:
    GameOfLife(int size);
    GameOfLife(const std::vector<std::vector<char>>& initialPattern, int size);

    void printGrid() const;
    void updateGrid();
    bool isGridEmpty() const;

private:
    int countLiveNeighbors(int row, int col) const;
    void randomizeGrid();

public:
    int generation;
private:
    int rows;
    int cols;
    std::vector<std::vector<char>> grid;
};

#endif // GAMEOFLIFE_H
