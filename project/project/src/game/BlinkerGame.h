#ifndef BLINKERGAME_H
#define BLINKERGAME_H
#include "gameOfLife.h"
#include <QPainter>
#include <QThread>


class BlinkerGame : public GameOfLife
{
    Q_OBJECT
public:
    BlinkerGame(const std::vector<std::vector<char>>& initialPattern, int size);
    virtual ~BlinkerGame();

    void drawGrid(QPainter& painter, int quadrantWidth, int quadrantHeight) const override;

public slots:
    void process();
private:
    std::vector<int> rgb;
    QThread workerThread;
};
#endif // BLINKERGAME_H
