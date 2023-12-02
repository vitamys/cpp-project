
#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include <vector>
#include <QPainter>
#include <QThread>
#include "iGameOfLife.h"

class GameOfLife : public QObject, public IGameOfLife {
    Q_OBJECT
public:
    explicit GameOfLife(IGameOfLife *parent, int size);
    explicit GameOfLife(IGameOfLife *parent, const std::vector<std::vector<char>>& initialPattern, int size);
    virtual ~GameOfLife();

    void printGrid() const;
    void updateGrid();
    bool isGridEmpty() const;
    const std::vector<std::vector<char>>& getGrid() const;
    void clear();
    void setQuadrant(int quadrant);
    virtual void drawGrid(QPainter& painter, int quadrantWidth, int quadrantHeight) const =0;
    void setData(std::vector<std::vector<char>> grid, int quadrant) override;
    void enableButtons(int quadrant) override;
    void drawGrid(QPainter& painter, int quadrantWidth, int quadrantHeight, std::vector<std::vector<char>> grid) const ;




protected:
    int countLiveNeighbors(int row, int col) const;
    void randomizeGrid();
    void process();

public:
    int generation;
protected:
    int rows;
    int cols;
    std::vector<std::vector<char>> grid;
    int quadrant;

    IGameOfLife* m_widget;
    QThread workerThread;


};

#endif // GAMEOFLIFE_H
