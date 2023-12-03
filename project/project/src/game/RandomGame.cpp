#include "RandomGame.h"
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <algorithm>
#include <QDebug>


RandomGame::RandomGame(IGameOfLife *parent, int size):GameOfLife(parent, size){
    rgb.push_back(255); //r value
    rgb.push_back(255); //g value
    rgb.push_back(15); //b value


}


void RandomGame::drawGrid(QPainter& painter, int quadrantWidth, int quadrantHeight) const{

    QColor color(rgb[0], rgb[1], rgb[2]);

    QPen cellPen(color);
    cellPen.setWidth(2);
    QBrush cellBrush(color, Qt::SolidPattern);


    painter.setPen(cellPen);
    painter.setBrush(cellBrush);

    // Calculate cell size based on the dimensions of the quadrant and the grid size
    int cellSize = std::min(quadrantWidth / cols, quadrantHeight / rows);

    if(!isGridEmpty()){
    QPen gridPen(Qt::gray);
    gridPen.setStyle(Qt::DashLine);
    painter.setPen(gridPen);

    for (int x = 0; x < quadrantWidth; x += cellSize) {
        painter.drawLine(x, 0, x, quadrantHeight);
    }
    for (int y = 0; y < quadrantHeight; y += cellSize) {
        painter.drawLine(0, y, quadrantWidth, y);
    }
    }

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            char cellState = grid[i][j];

            if (cellState == 'X')
            {
                painter.drawRect(j * cellSize, i * cellSize, cellSize, cellSize);
            }
        }
    }

}

