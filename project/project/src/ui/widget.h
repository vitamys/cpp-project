#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <vector>
#include <QLabel>
#include <QPainter>
#include "gameOfLife.h"
using namespace std;

namespace Ui {
class Widget;
}

class Widget : public QWidget
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

protected:
    void paintEvent(QPaintEvent *event) override;


private:
    Ui::Widget *ui;
    std::unique_ptr<GameOfLife> gameTopLeft;
    std::unique_ptr<GameOfLife> gameTopRight;
    std::unique_ptr<GameOfLife> gameBottomLeft;
    std::unique_ptr<GameOfLife> gameBottomRight;

    void initializeGames();
    void updateGames();
};

#endif // WIDGET_H
