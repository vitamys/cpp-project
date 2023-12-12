#ifndef RANDOMGAME_H
#define RANDOMGAME_H
#include "gameOfLife.h"
#include <QPainter>



class RandomGame : public GameOfLife
{
    Q_OBJECT
public:
    RandomGame(IGameOfLife *parent, int size);

    void drawGrid(QPainter& painter, int quadrantWidth, int quadrantHeight) const override;

private:
    std::vector<int> rgb;


};
#endif // RANDOMGAME_H

