#ifndef WIDGET_H
#define WIDGET_H

#include "quadraticWidget.h"
#include <vector>
#include <QLabel>
#include <QPainter>
#include <QThread>

#include "gameOfLife.h"
#include "BlinkerGame.h"
using namespace std;

namespace Ui {
class Widget;
}

class Widget : public QuadraticWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void startGame(const std::vector<std::vector<char>>& pattern, QLabel* outputLabel);
    void startGameWithPattern();
    void disableAllButtons();
    void enableAllButtons();

signals:
    void startGameSignal(const std::vector<std::vector<char>>& pattern, QLabel* outputLabel);


protected:
    void paintEvent(QPaintEvent *event) override;


private:
    Ui::Widget *ui;
    std::unique_ptr<GameOfLife> gameTopLeft;
    std::unique_ptr<BlinkerGame> gameTopRight;
    std::unique_ptr<GameOfLife> gameBottomLeft;
    std::unique_ptr<GameOfLife> gameBottomRight;

    QThread *threadTopRight;


    void initializeGames();
    void updateGames();
    void drawGrid(QPainter& painter, const std::vector<std::vector<char> > &grid) ;
};

#endif // WIDGET_H
