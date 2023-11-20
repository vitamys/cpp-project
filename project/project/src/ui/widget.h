#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <vector>
#include <QLabel>
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

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
