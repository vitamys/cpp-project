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
    std::unique_ptr<GameOfLife> game;
};

#endif // WIDGET_H
