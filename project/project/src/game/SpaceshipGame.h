#ifndef SPACESHIPGAME_H
#define SPACESHIPGAME_H
#include "gameOfLife.h"
#include <QPainter>



class SpaceshipGame : public GameOfLife
{
    Q_OBJECT
public:
    SpaceshipGame(IGameOfLife *parent,const std::vector<std::vector<char>>& initialPattern, int size);

    void drawGrid(QPainter& painter, int quadrantWidth, int quadrantHeight, std::vector<std::vector<char>> grid) const override;

private:
    std::vector<int> rgb;


};
#endif // SPACESHIPGAME_H

