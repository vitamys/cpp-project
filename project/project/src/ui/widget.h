#ifndef WIDGET_H
#define WIDGET_H

#include "quadraticWidget.h"
#include <vector>
#include <QLabel>
#include <QPainter>
#include <QThread>

#include "gameOfLife.h"
#include "BlinkerGame.h"
#include "iGameOfLife.h"
using namespace std;

namespace Ui {
class Widget;
}

class Widget : public QuadraticWidget, public IGameOfLife
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void startGame(int quadrant, QString patternname);
    void startGameWithPattern();
    void disableAllButtons(int quadrant);


protected:
    void paintEvent(QPaintEvent *event) override;


private:
    Ui::Widget *ui;
    std::unique_ptr<GameOfLife> gameTopLeft;
    std::unique_ptr<GameOfLife> gameTopRight;
    std::unique_ptr<GameOfLife> gameBottomLeft;
    std::unique_ptr<GameOfLife> gameBottomRight;

    void setData(std::vector<std::vector<char>> grid, int quadrant) override;
    void enableButtons(int qudrant) override;

    void updateGames(std::vector<std::vector<char>> grid);
    void drawGrid(QPainter& painter, const std::vector<std::vector<char> > &grid) ;
};

#endif // WIDGET_H
