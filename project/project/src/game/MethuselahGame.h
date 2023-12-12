#ifndef METHUSELAHGAME_H
#define METHUSELAHGAME_H
#include "gameOfLife.h"
#include <QPainter>

class MethuselahGame : public GameOfLife
{
    Q_OBJECT
public:
    MethuselahGame(IGameOfLife *parent,const std::vector<std::vector<char>>& initialPattern, int size);

    void drawGrid(QPainter& painter, int quadrantWidth, int quadrantHeight, std::vector<std::vector<char>> grid) const override;

private:
    std::vector<int> rgb;


};

#endif // METHUSELAHGAME_H
