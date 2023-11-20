#include "widget.h"
#include "ui_widget.h"
#include "gameOfLife.h"
#include "pattern.h"
#include <unistd.h>  // for sleep function


using namespace std;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->beaconButton, &QPushButton::clicked, this, [=]() {
        startGameWithPattern();
    });

    connect(ui->gliderButton, &QPushButton::clicked, this, [=]() {
        startGameWithPattern();
    });
}

Widget::~Widget()
{
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
    GameOfLife game(pattern,10);

    // Or use the constructor with a filename to load a pattern from a text file
    //GameOfLife game("beacon.txt", 10);

    const int maxGenerations = 50;

//    while (!game.isGridEmpty() && game.generation < maxGenerations) {
//        game.printGrid();
//        game.updateGrid();
//        usleep(100000); // Sleep for 100 milliseconds (adjust as needed)
//    }
    while ( game.generation < maxGenerations && !game.isGridEmpty()) {
            // Update the QLabel with the current grid state
            QString gridText;
            for (const auto& row : game.getGrid()) {
                for (char cell : row) {
                    gridText += QString(cell);
                }
                gridText += "\n";
            }
            outputLabel->setText(gridText);

            QApplication::processEvents();  // Allow processing of events to update the UI
            usleep(100000);  // Sleep for 100 milliseconds (adjust as needed)
            game.updateGrid();
        }

        // Clear the label once the game finishes
        outputLabel->clear();
}
void Widget::disableAllButtons() {
    ui->beaconButton->setVisible(false);
    ui->gliderButton->setVisible(false);
}

void Widget::enableAllButtons() {
    ui->beaconButton->setVisible(true);
    ui->gliderButton->setVisible(true);
}
