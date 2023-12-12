#ifndef STATICGAME_H
#define STATICGAME_H

#include "gameOfLife.h"
#include <QPainter>

class StaticGame : public GameOfLife
{
    Q_OBJECT
public:
    StaticGame(IGameOfLife *parent,const std::vector<std::vector<char>>& initialPattern, int size);

    void drawGrid(QPainter& painter, int quadrantWidth, int quadrantHeight) const override;

private:
    std::vector<int> rgb;


};

#endif // STATICGAME_H
