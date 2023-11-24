#include "widget.h"
#include "ui_widget.h"
#include "BlinkerGame.h"
#include "pattern.h"
#include <unistd.h>  // for sleep function


using namespace std;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //initializeGames();

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
    //GameOfLife game(pattern,10);
    gameTopRight = std::make_unique<BlinkerGame>(pattern, 20);

    // Or use the constructor with a filename to load a pattern from a text file
    //GameOfLife game("beacon.txt", 10);

    const int maxGenerations = 50;

//    while (!game.isGridEmpty() && game.generation < maxGenerations) {
//        game.printGrid();
//        game.updateGrid();
//        usleep(100000); // Sleep for 100 milliseconds (adjust as needed)
//    }
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
            usleep(100000);  // Sleep for 100 milliseconds (adjust as needed)
            gameTopRight->updateGrid();
        }
        gameTopRight->clear();
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
void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    int width = this->width() / 2;
    int height = this->height() / 2;

    // Draw each quadrant
    painter.setViewport(0, 0, width, height);
    gameTopLeft->drawGrid(painter);

    painter.setViewport(width, 0, width, height);
    gameTopRight->drawGrid(painter);

    painter.setViewport(0, height, width, height);
    gameBottomLeft->drawGrid(painter);

    painter.setViewport(width, height, width, height);
    gameBottomRight->drawGrid(painter);
}

//void Widget::paintEvent(QPaintEvent *event) {
//    // Create a QPainter and set up the pen and brush for drawing
//    QPainter painter(this);
//    painter.setRenderHint(QPainter::Antialiasing);

//    // Set background color
//    painter.fillRect(rect(), Qt::black);

//    // Set up the pen for grid lines (optional)
//    QPen gridPen(Qt::gray);
//    gridPen.setStyle(Qt::DashLine);
//    painter.setPen(gridPen);

//    // Draw grid lines (optional)
//    int cellSize = 20; // Adjust the size of each cell
////    for (int x = 0; x < width(); x += cellSize) {
////        painter.drawLine(x, 0, x, height());
////    }
////    for (int y = 0; y < height(); y += cellSize) {
////        painter.drawLine(0, y, width(), y);
////    }

//    // Set up the pen and brush for drawing cells
//    QPen cellPen(Qt::white);
//    cellPen.setWidth(10);
//    QBrush cellBrush(Qt::white, Qt::SolidPattern);

//    painter.setPen(cellPen);
//    painter.setBrush(cellBrush);

//    // Access your Game of Life data and draw the cells
//    if (game) {
//        const auto& grid = game->getGrid();
//                for (size_t row = 0; row < grid.size(); ++row) {
//                    for (size_t col = 0; col < grid[row].size(); ++col) {
//                        // Check the state of the cell
//                        char cellState = grid[row][col];  // Assuming '0' for dead and '1' for alive

//                        // If the cell is alive, draw it
//                        if (cellState == 'X') {
//                            painter.drawRect(col * cellSize, row * cellSize, cellSize, cellSize);
//                        }
//                    }
//                }
//    }
//}
