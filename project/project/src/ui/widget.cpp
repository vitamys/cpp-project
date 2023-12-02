#include "widget.h"
#include "ui_widget.h"
#include "BlinkerGame.h"
#include "pattern.h"
#include "gamefactory.h"
#include <unistd.h>  // for sleep function
#include <QTimer>
#include <QDebug>
#include <QRegularExpression>

using namespace std;

Widget::Widget(QWidget *parent) :
    QuadraticWidget(parent),
    ui(new Ui::Widget),
    GUI_RATE_MS(150),
    lastData(4)
{
    ui->setupUi(this);

    resize(800, 800);
    QGridLayout* layout =ui->gridLayout;
    this->setLayout(layout);


    // Find all child buttons of the widget
    QList<QPushButton*> allButtons = this->findChildren<QPushButton*>();

    // Connect all buttons to the startGameWithPattern method
    for (QPushButton* button : allButtons) {
        connect(button, &QPushButton::clicked, this, &Widget::startGameWithPattern);
    }


    // Update GUI-timer to update images etc. every 20 ms
    m_guiUpdateTimer.reset( new QTimer(this));
    connect( m_guiUpdateTimer.get(), SIGNAL(timeout()), this, SLOT(updateGui()) );
    m_guiUpdateTimer->start(GUI_RATE_MS);
}

Widget::~Widget()
{

    delete ui;

}

void Widget::setData(std::vector<std::vector<char>> grid, int quadrant){
    //TODO: append Data of grid to some buffer or other data structure
    lastData[quadrant-1].push_back(grid);
//    this->update();
//    QApplication::processEvents();
}
// Called by GUI-timer
void Widget::updateGui()
{
    if( !lastData.empty() ) //check for data in buffer here. move draw function back to here? what about factory method then?
    {
        this-> update(); //this will call the draw function
        QApplication::processEvents();

    }
}



void Widget::startGameWithPattern() {
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    if (clickedButton) {

        QString buttonname= clickedButton->objectName();
        QStringList parts = buttonname.split("_");
        QString patternname= parts[0];
        int quadrant = parts[1].toInt();

        // Output the parts
        for (const QString& part : parts) {
            qDebug() << part;
        }

        disableAllButtons(quadrant);



        startGame(quadrant, patternname);

    }
}

void Widget::startGame(int quadrant, QString patternname){
    unique_ptr<GameFactory> gameFactory = unique_ptr<GameFactory>(new GameFactory());

    //set the quadrant in each game to know where game is later on
    switch(quadrant){
    case 1: gameTopLeft = unique_ptr<GameOfLife>(gameFactory->getGame(this,patternname));
        gameTopLeft->setQuadrant(1);
        break;
    case 2: gameTopRight = unique_ptr<GameOfLife>(gameFactory->getGame(this,patternname));
        gameTopRight->setQuadrant(2);

        break;

    case 3: gameBottomLeft = unique_ptr<GameOfLife>(gameFactory->getGame(this,patternname));
        gameBottomLeft->setQuadrant(3);

        break;
    case 4: gameBottomRight = unique_ptr<GameOfLife>(gameFactory->getGame(this,patternname));
        gameBottomRight->setQuadrant(4);

        break;
    }


}
void Widget::disableAllButtons(int quadrant) {
    qDebug() << "called methods disabelbuttons";
    QString suffix = "_" + QString::number(quadrant);

    QList<QPushButton *> buttons = findChildren<QPushButton *>(QRegularExpression(suffix+"$"));
    std::for_each(buttons.begin(), buttons.end(), [](QPushButton* button) {
        button->setVisible(false);
    });

}


void Widget::enableButtons(int quadrant) {
    qDebug() << "called method enable";
    QString suffix = "_" + QString::number(quadrant);

    QList<QPushButton *> buttons = findChildren<QPushButton *>(QRegularExpression(suffix+"$"));
    std::for_each(buttons.begin(), buttons.end(), [](QPushButton* button) {
        button->setVisible(true);
    });


}
void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    int width = this->width() / 2;
    int height = this->height() / 2;
    painter.fillRect(rect(), Qt::black);

    //check which quadrant has to be drawn:
    //painter.setViewport(0, 0, 2*width, 2*height);
    if (!lastData.empty()) {
        for (size_t i = 0; i < lastData.size(); ++i) {
            if (!lastData[i].empty()) {
                std::vector<std::vector<char>> grid = lastData[i].front();
                // Based on the index, call the appropriate draw function
                switch (i) {
                    case 0:
                        painter.setViewport(0, 0, 2*width, 2*height);
                        gameTopLeft->drawGrid(painter, width, height, grid);
                        break;
                    case 1:
                        painter.setViewport(width, 0, 2*width, 2*height);
                        gameTopRight->drawGrid(painter, width, height, grid);
                        break;
                    case 2:
                        painter.setViewport(0, height, 2*width, 2*height);
                        gameBottomLeft->drawGrid(painter, width, height, grid);
                        break;
                    case 3:
                        painter.setViewport(width, height, 2*width, 2*height);
                        gameBottomRight->drawGrid(painter, width, height, grid);
                        break;
                }
                lastData[i].erase(lastData[i].begin());
            }
            else{
                enableButtons(i+1);
            }
        }
    }


    // Draw each quadrant
//    painter.setViewport(0, 0, 2*width, 2*height);
//    if(gameTopLeft != nullptr){ // this method is called before game is selected, so check first
//        gameTopLeft->drawGrid(painter, width, height);

//    }

//    painter.setViewport(width, 0, 2*width, 2*height);
//    if(gameTopRight != nullptr){ // this method is called before game is selected, so check first
//        gameTopRight->drawGrid(painter, width, height);

//    }

//    painter.setViewport(0, height, 2*width, 2*height);
//    if(gameBottomLeft != nullptr){
//        gameBottomLeft->drawGrid(painter, width, height);
//    }

//    painter.setViewport(width, height, 2*width, 2*height);
//    if (gameBottomRight != nullptr){
//        gameBottomRight->drawGrid(painter, width, height);
//    }
}
