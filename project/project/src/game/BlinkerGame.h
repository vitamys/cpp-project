#ifndef BLINKERGAME_H
#define BLINKERGAME_H
#include "gameOfLife.h"
#include <QPainter>
#include <QThread>
#include "iGameOfLife.h"


class BlinkerGame : public GameOfLife
{
    Q_OBJECT
public:
    BlinkerGame(IGameOfLife *parent,const std::vector<std::vector<char>>& initialPattern, int size);

    void drawGrid(QPainter& painter, int quadrantWidth, int quadrantHeight) const override;


private:
    std::vector<int> rgb;



};
#endif // BLINKERGAME_H

