#include "gameOfLife.h"
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <algorithm>
#include <QDebug>


GameOfLife::GameOfLife(IGameOfLife *parent,int size) : rows(size), cols(size), generation(0), m_widget(parent)  {
    // Initialize the grid with random values
    grid.resize(rows, std::vector<char>(cols, '.'));
    randomizeGrid();
    qDebug() << "thread" << QObject::thread();

    this->moveToThread(&workerThread);
    // Connect the thread's started signal to the process method
    qDebug() << "thread after"<< QObject::thread();

    connect(&workerThread, &QThread::started, this, &GameOfLife::process);
    connect(&workerThread, &QThread::finished, this, &GameOfLife::clear);

    workerThread.start();
}


GameOfLife::GameOfLife(IGameOfLife *parent,const std::vector<std::vector<char>>& initialPattern, int size)
        : rows(size), cols(size), generation(0), grid(rows, std::vector<char>(cols, ' ')), m_widget(parent) {

        // Place the initial pattern in the middle of the grid
        int startRow = (rows - initialPattern.size()) / 2;
        int startCol = (cols - initialPattern[0].size()) / 2;

        for (int i = 0; i < initialPattern.size(); ++i) {
            for (int j = 0; j < initialPattern[i].size(); ++j) {
                grid[startRow + i][startCol + j] = initialPattern[i][j];
            }
        }
        qDebug() << "thread" << QObject::thread();

        this->moveToThread(&workerThread);
        // Connect the thread's started signal to the process method
        qDebug() << "thread after"<< QObject::thread();

        connect(&workerThread, &QThread::started, this, &GameOfLife::process);
        connect(&workerThread, &QThread::finished, this, &GameOfLife::clear);

        workerThread.start();
    }
GameOfLife::~GameOfLife()
{
    // Clean up when the object is destroyed
    workerThread.quit();
    workerThread.wait();
}

void GameOfLife::setData(std::vector<std::vector<char>> grid, int quadrant){
    m_widget->setData(grid, quadrant);
}

void GameOfLife::enableButtons(int quadrant){
    m_widget->enableButtons(quadrant);
}

void GameOfLife::randomizeGrid() {
    // Fill the grid with random live ('X') and dead ('.') cells
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            grid[i][j] = (rand() % 2 == 0) ? '.' : 'X';
        }
    }
}


void GameOfLife::printGrid() const {
    // Print the current state of the grid
    std::cout << "Generation: " << generation << std::endl;
    for (const auto &row : grid) {
        for (char cell : row) {
            std::cout << cell;
        }
        std::cout << std::endl;
    }
}

void GameOfLife::updateGrid() {
    // Update the grid based on the rules of the Game of Life
    std::vector<std::vector<char>> newGrid(rows, std::vector<char>(cols, '.'));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int liveNeighbors = countLiveNeighbors(i, j);

            if (grid[i][j] == 'X') {
                // Any live cell with fewer than two live neighbors dies
                // Any live cell with two or three live neighbors lives on
                // Any live cell with more than three live neighbors dies
                newGrid[i][j] = (liveNeighbors == 2 || liveNeighbors == 3) ? 'X' : '.';
            } else {
                // Any dead cell with exactly three live neighbors becomes a live cell
                newGrid[i][j] = (liveNeighbors == 3) ? 'X' : '.';
            }
        }
    }

    grid = newGrid;
    ++generation;
}

int GameOfLife::countLiveNeighbors(int row, int col) const {
    // Count the number of live neighbors around a cell
    int liveNeighbors = 0;

    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue; // Skip the current cell

            int neighborRow = (row + i + rows) % rows;
            int neighborCol = (col + j + cols) % cols;

            if (grid[neighborRow][neighborCol] == 'X') {
                ++liveNeighbors;
            }
        }
    }

    return liveNeighbors;
}

bool GameOfLife::isGridEmpty() const {
    // Check if the grid contains no live cells
    return std::none_of(grid.begin(), grid.end(), [](const auto &row) {
            return std::any_of(row.begin(), row.end(), [](char cell) {
                return cell == 'X';
            });
        });
}

const std::vector<std::vector<char>>& GameOfLife::getGrid() const {
       return grid;
   }

void GameOfLife::clear(){
    for_each(grid.begin(), grid.end(), [](std::vector<char>& row) {
        std::fill(row.begin(), row.end(), '.');
    });
}
void GameOfLife::setQuadrant(int quadrant){
    this->quadrant=quadrant;
}

void GameOfLife::process(){
    while ( this->generation < 50 && !this->isGridEmpty()) {

        this->updateGrid();
        m_widget->setData(this->grid, this->quadrant);
        //QThread::usleep(100000);// Sleep for 100 milliseconds
    }
    this->clear();
    //m_widget->enableButtons(this->quadrant);

}

void GameOfLife::drawGrid(QPainter& painter, int quadrantWidth, int quadrantHeight, std::vector<std::vector<char>> grid) const{

    //QColor color(rgb[0], rgb[1], rgb[2]);

    QPen cellPen(Qt::white);
    cellPen.setWidth(2);
    QBrush cellBrush(Qt::white, Qt::SolidPattern);


    painter.setPen(cellPen);
    painter.setBrush(cellBrush);

    // Calculate cell size based on the dimensions of the quadrant and the grid size
    int cellSize = std::min(quadrantWidth / cols, quadrantHeight / rows);
    //if(!isGridEmpty()){
        // Set up the pen for grid lines
        QPen gridPen(Qt::gray);
        gridPen.setStyle(Qt::DashLine);
        painter.setPen(gridPen);

        // Draw grid lines
        for (int x = 0; x < quadrantWidth; x += cellSize) {
            painter.drawLine(x, 0, x, quadrantHeight);
        }
        for (int y = 0; y < quadrantHeight; y += cellSize) {
            painter.drawLine(0, y, quadrantWidth, y);
        }
    //}

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


