
#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include <vector>
#include <QPainter>

class GameOfLife {
public:
    GameOfLife(int size);
    GameOfLife(const std::vector<std::vector<char>>& initialPattern, int size);

    void printGrid() const;
    void updateGrid();
    bool isGridEmpty() const;
    const std::vector<std::vector<char>>& getGrid() const;
    void clear();
    virtual void drawGrid(QPainter& painter) const =0;


protected:
    int countLiveNeighbors(int row, int col) const;
    void randomizeGrid();

public:
    int generation;
protected:
    int rows;
    int cols;
    std::vector<std::vector<char>> grid;

};

#endif // GAMEOFLIFE_H
