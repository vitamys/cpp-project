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
        startGame(Patterns::beacon());
    });

    connect(ui->gliderButton, &QPushButton::clicked, this, [=]() {
        startGame(Patterns::glider());
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::startGame(const std::vector<std::vector<char>>& pattern){
    // Use either the default constructor for a random initial state
    GameOfLife game(pattern,10);

    // Or use the constructor with a filename to load a pattern from a text file
    //GameOfLife game("beacon.txt", 10);

    const int maxGenerations = 50;

    while (!game.isGridEmpty() && game.generation < maxGenerations) {
        game.printGrid();
        game.updateGrid();
        usleep(100000); // Sleep for 100 milliseconds (adjust as needed)
    }
}
