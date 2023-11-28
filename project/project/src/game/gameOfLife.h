
#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include <vector>
#include <QPainter>
#include <QThread>
#include "iGameOfLife.h"

class GameOfLife : public QObject, public IGameOfLife {
    Q_OBJECT
public:
    explicit GameOfLife(int size);
    explicit GameOfLife(IGameOfLife *parent, const std::vector<std::vector<char>>& initialPattern, int size);


    void printGrid() const;
    void updateGrid();
    bool isGridEmpty() const;
    const std::vector<std::vector<char>>& getGrid() const;
    void clear();
    void setQuadrant(int quadrant);
    virtual void drawGrid(QPainter& painter, int quadrantWidth, int quadrantHeight) const =0;
    void setData(std::vector<std::vector<char>> grid) override;
    void enableButtons(int quadrant) override;


protected:
    int countLiveNeighbors(int row, int col) const;
    void randomizeGrid();

public:
    int generation;
protected:
    int rows;
    int cols;
    std::vector<std::vector<char>> grid;
    int quadrant;

    IGameOfLife* m_widget;


};

#endif // GAMEOFLIFE_H
