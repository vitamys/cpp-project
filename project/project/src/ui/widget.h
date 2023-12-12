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

private slots:
    void updateGui();

private:
    Ui::Widget *ui;
    std::unique_ptr<GameOfLife> gameTopLeft;
    std::unique_ptr<GameOfLife> gameTopRight;
    std::unique_ptr<GameOfLife> gameBottomLeft;
    std::unique_ptr<GameOfLife> gameBottomRight;

    std::unique_ptr<QTimer> m_guiUpdateTimer;

    const size_t GUI_RATE_MS;


    //std::shared_ptr<DataBuffer> m_lastData;
    std::vector<std::vector<std::vector<std::vector<char>>>> lastData;
    //TODO: implement observer pattern. save data in this buffer then display at frame rate ie paint
    void setData(std::vector<std::vector<char>> grid, int quadrant) override;
    void enableButtons(int qudrant) override;


    void initializeGames();
    void updateGames(std::vector<std::vector<char>> grid);
    void drawGrid(QPainter& painter, int quadrantWidth, int quadrantHeight, std::vector<std::vector<char>> grid) const ;
};

#endif // WIDGET_H
