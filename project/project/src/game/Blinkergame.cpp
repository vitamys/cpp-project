#include "BlinkerGame.h"
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <algorithm>
#include <QDebug>


BlinkerGame::BlinkerGame(IGameOfLife *parent, const std::vector<std::vector<char>>& initialPattern, int size):GameOfLife(parent,initialPattern, size){
    rgb.push_back(255); //r value
    rgb.push_back(15); //g value
    rgb.push_back(0); //b value
    qDebug() << "thread" << QObject::thread();

    this->moveToThread(&workerThread);
    // Connect the thread's started signal to the process method
    qDebug() << "thread after"<< QObject::thread();

    connect(&workerThread, &QThread::started, this, &BlinkerGame::process);
    connect(&workerThread, &QThread::finished, this, &BlinkerGame::clear);

    workerThread.start();


}
BlinkerGame::~BlinkerGame()
{
    // Clean up when the object is destroyed
    workerThread.quit();
    workerThread.wait();
}



void BlinkerGame::drawGrid(QPainter& painter, int quadrantWidth, int quadrantHeight) const{
    QPen cellPen(Qt::white);
    cellPen.setWidth(2);
    QBrush cellBrush(Qt::white, Qt::SolidPattern);

    painter.setPen(cellPen);
    painter.setBrush(cellBrush);

    // Calculate cell size based on the dimensions of the quadrant and the grid size
    int cellSize = std::min(quadrantWidth / cols, quadrantHeight / rows);

    // Set up the pen for grid lines
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

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            char cellState = grid[i][j];

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

        this->updateGrid();
        m_widget->setData(this->grid);
        QThread::usleep(100000);// Sleep for 100 milliseconds
    }
    this->clear();
    m_widget->enableButtons(this->quadrant);

}


