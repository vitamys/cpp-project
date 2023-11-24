#ifndef BLINKERGAME_H
#define BLINKERGAME_H
#include "gameOfLife.h"
#include <QPainter>

class BlinkerGame : public GameOfLife
{
public:
    BlinkerGame(const std::vector<std::vector<char>>& initialPattern, int size);
    void drawGrid(QPainter& painter) const override;

private:
    std::vector<int> rgb;
};
#endif // BLINKERGAME_H
