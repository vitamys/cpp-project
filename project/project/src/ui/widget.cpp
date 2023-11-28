#include "widget.h"
#include "ui_widget.h"
#include "BlinkerGame.h"
#include "pattern.h"
#include "gamefactory.h"
#include <unistd.h>  // for sleep function
#include <QTimer>
#include <QDebug>

using namespace std;

Widget::Widget(QWidget *parent) :
    QuadraticWidget(parent),
    ui(new Ui::Widget),
    GUI_RATE_MS(50)
{
    ui->setupUi(this);
    resize(800, 800);

    connect(ui->beaconButton_1, &QPushButton::clicked, this, [=]() {
        startGameWithPattern();
    });

    connect(ui->gliderButton_1, &QPushButton::clicked, this, [=]() {
        startGameWithPattern();
    });

    connect(ui->beaconButton_2, &QPushButton::clicked, this, [=]() {
        startGameWithPattern();
    });

    connect(ui->gliderButton_2, &QPushButton::clicked, this, [=]() {
        startGameWithPattern();
    });

    // Update GUI-timer to update images etc. every 20 ms
    m_guiUpdateTimer.reset( new QTimer(this));
    connect( m_guiUpdateTimer.get(), SIGNAL(timeout()), this, SLOT(updateGui()) );
    m_guiUpdateTimer->start(GUI_RATE_MS);
}

Widget::~Widget()
{

    delete ui;

}

void Widget::setData(std::vector<std::vector<char>> grid){
    //TODO: append Data of grid to some buffer
    this->update();
    QApplication::processEvents();
}
// Called by GUI-timer
void Widget::updateGui()
{
    if( true )
    {
        this-> update(); //this will call the draw function
        QApplication::processEvents();

    }
}

void Widget::updateGames(std::vector<std::vector<char>> grid){
    this->update();
    QApplication::processEvents();
}

void Widget::startGameWithPattern() {
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    if (clickedButton) {

        QLabel* outputLabel = ui->gridLabel;
        QString buttonname= clickedButton->objectName();
        QStringList parts = buttonname.split("_");
        QString patternname= parts[0];
        int quadrant = parts[1].toInt();

        // Output the parts
            for (const QString& part : parts) {
                qDebug() << part;
            }

        disableAllButtons(quadrant);



        startGame(quadrant,Patterns::patternByName(patternname), outputLabel);

    }
}

void Widget::startGame(int quadrant,const std::vector<std::vector<char>>& pattern, QLabel* outputLabel){
    // Use either the default constructor for a random initial state
    //GameOfLife game(pattern,10);
    //TODO: move loop to process function in gameOFLife class. move class intialization to startGame and only pass button label
    unique_ptr<GameFactory> gameFactory = unique_ptr<GameFactory>(new GameFactory());
    //gameTopRight = unique_ptr<GameOfLife>(gameFactory->getGame(this,pattern, "gliderButton"));

    switch(quadrant){
    case 1: gameTopLeft = std::make_unique<BlinkerGame>(this,pattern, 10);
        gameTopLeft->setQuadrant(1);
        break;
    case 2:gameTopRight = std::make_unique<BlinkerGame>(this,pattern, 10);
        gameTopLeft->setQuadrant(2);

        break;
    }

    const int maxGenerations = 50;

    //    while (!game.isGridEmpty() && game.generation < maxGenerations) {
    //        game.printGrid();
    //        game.updateGrid();
    //        usleep(100000); // Sleep for 100 milliseconds (adjust as needed)
    //    }
    //TODO: move to gameoflife instances. use signals to update widget.
    // TODO: make signal listen and update accordingly. thread finished, show buttons, update to paint
    //    while ( gameTopRight->generation < maxGenerations && !gameTopRight->isGridEmpty()) {
    //        // Update the QLabel with the current grid state
    //        //            QString gridText;
    //        //            for (const auto& row : game->getGrid()) {
    //        //                for (char cell : row) {
    //        //                    gridText += QString(cell);
    //        //                }
    //        //                gridText += "\n";
    //        //            }
    //        //            outputLabel->setText(gridText);

    //        this->update();
    //        QApplication::processEvents();  // Allow processing of events to update the UI
    //        //usleep(100000);  // Sleep for 100 milliseconds (adjust as needed)
    //        QThread::msleep(100);
    //        gameTopRight->updateGrid();
    //    }
    //    gameTopRight->clear();
    //    this->update();

}
void Widget::disableAllButtons(int quadrant) {
    qDebug() << "called methods disabelbuttons";

    switch (quadrant){
    case 1:
        ui->beaconButton_1->setVisible(false);
        ui->gliderButton_1->setVisible(false);
        break;
    case 2:
        ui->beaconButton_2->setVisible(false);
        ui->gliderButton_2->setVisible(false);
    };
}


void Widget::enableButtons(int quadrant) {
    qDebug() << "called method enable";
    switch (quadrant){
    case 1:
        ui->beaconButton_1->setVisible(true);
        ui->gliderButton_1->setVisible(true);
        break;
    case 2:
        ui->beaconButton_2->setVisible(true);
        ui->gliderButton_2->setVisible(true);
    }

}
void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    int width = this->width() / 2;
    int height = this->height() / 2;
    painter.fillRect(rect(), Qt::black);


    // Draw each quadrant
        painter.setViewport(0, 0, 2*width, 2*height);
        if(gameTopLeft != nullptr){ // this method is called before game is selected, so check first
            gameTopLeft->drawGrid(painter, width, height);

        }

    painter.setViewport(width, 0, 2*width, 2*height);
    if(gameTopRight != nullptr){ // this method is called before game is selected, so check first
        gameTopRight->drawGrid(painter, width, height);

    }
    //

    //    painter.setViewport(0, height, width, height);
    //    gameBottomLeft->drawGrid(painter);

    //    painter.setViewport(width, height, width, height);
    //    gameBottomRight->drawGrid(painter);
}
