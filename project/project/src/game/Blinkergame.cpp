#include "BlinkerGame.h"
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <algorithm>


BlinkerGame::BlinkerGame(const std::vector<std::vector<char>>& initialPattern, int size):GameOfLife(initialPattern, size){
    rgb.push_back(255); //r value
    rgb.push_back(15); //g value
    rgb.push_back(0); //b value

    this->moveToThread(&workerThread);
    // Connect the thread's started signal to the process method
    connect(&workerThread, &QThread::started, this, &BlinkerGame::process);

    // Start the thread
    workerThread.start();


}
BlinkerGame::~BlinkerGame()
{
    // Clean up when the object is destroyed
    workerThread.quit();
    workerThread.wait();
}

void BlinkerGame::drawGrid(QPainter& painter, int quadrantWidth, int quadrantHeight) const{
    // Set up the pen and brush for drawing cells
        QPen cellPen(Qt::white);
        cellPen.setWidth(2);
        QBrush cellBrush(Qt::white, Qt::SolidPattern);

        painter.setPen(cellPen);
        painter.setBrush(cellBrush);

        // Calculate cell size based on the dimensions of the quadrant and the grid size
        int cellSize = std::min(quadrantWidth / cols, quadrantHeight / rows);

            // Set up the pen for grid lines (optional)
            QPen gridPen(Qt::gray);
            gridPen.setStyle(Qt::DashLine);
            painter.setPen(gridPen);

            // Draw grid lines (optional)
            for (int x = 0; x < quadrantWidth; x += cellSize) {
                painter.drawLine(x, 0, x, quadrantHeight);
            }
            for (int y = 0; y < quadrantHeight; y += cellSize) {
                painter.drawLine(0, y, quadrantWidth, y);
            }

        // Draw each cell in the grid
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                // Check the state of the cell
                char cellState = grid[i][j];  // Assuming '0' for dead and '1' for alive

                // If the cell is alive, draw it
                if (cellState == 'X')
                {
                    painter.drawRect(j * cellSize, i * cellSize, cellSize, cellSize);
                }
            }
        }

}
void BlinkerGame::process(){
    while ( this->generation < 50 && !this->isGridEmpty()) {
        // Update the QLabel with the current grid state
        //            QString gridText;
        //            for (const auto& row : game->getGrid()) {
        //                for (char cell : row) {
        //                    gridText += QString(cell);
        //                }
        //                gridText += "\n";
        //            }
        //            outputLabel->setText(gridText);

        //usleep(100000);  // Sleep for 100 milliseconds (adjust as needed)
        QThread::msleep(10);
        this->updateGrid();
    }
    this->clear();

}


