#include "widget.h"
#include "ui_widget.h"
#include "BlinkerGame.h"
#include "pattern.h"
#include "gamefactory.h"
#include <unistd.h>  // for sleep function
#include <QTimer>


using namespace std;

Widget::Widget(QWidget *parent) :
    QuadraticWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    resize(800, 800);
    //initializeGames();
    //gameTopRight = std::make_unique<BlinkerGame>(Patterns::patternByName("gliderButton"), 10);

    // Create threads for each quadrant
    threadTopRight = new QThread(this);
    threadTopRight->start();
    //gameTopRight->moveToThread(threadTopRight);
    //connect(threadTopRight, &QThread::finished, threadTopRight, &QThread::deleteLater);
    // Delay the creation of gameTopRight until after the thread is started
    //TODO: fix threads such that gameTopRight can be moved.
        QTimer::singleShot(0, this, [=]() {
            gameTopRight = std::make_unique<BlinkerGame>(Patterns::patternByName(ui->gliderButton->objectName()), 10);
            gameTopRight->moveToThread(threadTopRight);
            connect(threadTopRight, &QThread::finished, threadTopRight, &QThread::deleteLater);
        });

    // Connect button signals to start games
    // Connect button signals to start games
    connect(ui->beaconButton, &QPushButton::clicked, this, [=]() {
        emit startGameSignal(Patterns::patternByName(ui->beaconButton->objectName()), ui->gridLabel);
    });

    connect(ui->gliderButton, &QPushButton::clicked, this, [=]() {
        emit startGameSignal(Patterns::patternByName(ui->gliderButton->objectName()), ui->gridLabel);
    });
    connect(this, &Widget::startGameSignal, this, &Widget::startGame);  // Updated line

    //    connect(ui->beaconButton, &QPushButton::clicked, this, [=]() {
    //        startGameWithPattern();
    //    });

    //    connect(ui->gliderButton, &QPushButton::clicked, this, [=]() {
    //        startGameWithPattern();
    //    });
}

Widget::~Widget()
{
    threadTopRight->quit();
    threadTopRight->wait();
    delete ui;

}

void Widget::startGameWithPattern() {
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    if (clickedButton) {
        disableAllButtons();

        QLabel* outputLabel = ui->gridLabel;
        startGame(Patterns::patternByName(clickedButton->objectName()), outputLabel);

        enableAllButtons();
    }
}

void Widget::startGame(const std::vector<std::vector<char>>& pattern, QLabel* outputLabel){
    // Use either the default constructor for a random initial state
    //GameOfLife game(pattern,10);
    //TODO: move loop to process function in gameOFLife class. move class intialization to startGame and only pass button label
    unique_ptr<GameFactory> gameFactory = unique_ptr<GameFactory>(new GameFactory());
    //gameTopRight = unique_ptr<GameOfLife>(gameFactory->getGame(pattern, "gliderButton"));


    gameTopRight = std::make_unique<BlinkerGame>(pattern, 10);

    // Or use the constructor with a filename to load a pattern from a text file
    //GameOfLife game("beacon.txt", 10);

    const int maxGenerations = 50;

    //    while (!game.isGridEmpty() && game.generation < maxGenerations) {
    //        game.printGrid();
    //        game.updateGrid();
    //        usleep(100000); // Sleep for 100 milliseconds (adjust as needed)
    //    }
    //TODO: move to gameoflife instances. use signals to update widget.
   // TODO: make signal listen and update accordingly. thread finished, show buttons, update to paint
    while ( gameTopRight->generation < maxGenerations && !gameTopRight->isGridEmpty()) {
        // Update the QLabel with the current grid state
        //            QString gridText;
        //            for (const auto& row : game->getGrid()) {
        //                for (char cell : row) {
        //                    gridText += QString(cell);
        //                }
        //                gridText += "\n";
        //            }
        //            outputLabel->setText(gridText);

        this->update();
        QApplication::processEvents();  // Allow processing of events to update the UI
        //usleep(100000);  // Sleep for 100 milliseconds (adjust as needed)
        QThread::msleep(100);
        gameTopRight->updateGrid();
    }
    gameTopRight->clear();
    this->update();

}
void Widget::disableAllButtons() {
    ui->beaconButton->setVisible(false);
    ui->gliderButton->setVisible(false);
}

void Widget::enableAllButtons() {
    ui->beaconButton->setVisible(true);
    ui->gliderButton->setVisible(true);
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
    //    painter.setViewport(0, 0, width, height);
    //    gameTopLeft->drawGrid(painter);

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
