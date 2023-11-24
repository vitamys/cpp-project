#include "BlinkerGame.h"
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <algorithm>


BlinkerGame::BlinkerGame(const std::vector<std::vector<char>>& initialPattern, int size):GameOfLife(initialPattern, size){
    rgb.push_back(255); //r value
    rgb.push_back(15); //g value
    rgb.push_back(0); //b value


}

void BlinkerGame::drawGrid(QPainter& painter) const{
    // Set up the pen and brush for drawing cells
        QPen cellPen(Qt::white);
        cellPen.setWidth(2);
        QBrush cellBrush(Qt::white, Qt::SolidPattern);

        painter.setPen(cellPen);
        painter.setBrush(cellBrush);

        // Calculate cell size based on the dimensions of the quadrant and the grid size
        int cellSize = std::min(painter.viewport().width() / cols, painter.viewport().height() / rows);

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



