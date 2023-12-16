#include "gameOfLife.h"
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <algorithm>
#include <QDebug>


GameOfLife::GameOfLife(IGameOfLife *parent,int maxGeneration) : generation(0),rows(10), cols(10),  maxGeneration(maxGeneration), m_widget(parent)  {
    // Initialize the grid with random values
    grid.resize(rows, std::vector<char>(cols, '.'));
    randomizeGrid();

    this->moveToThread(&workerThread);

    connect(&workerThread, &QThread::started, this, &GameOfLife::process);
    connect(&workerThread, &QThread::finished, this, &GameOfLife::clear);

    workerThread.start();
}


GameOfLife::GameOfLife(IGameOfLife *parent,const std::vector<std::vector<char>>& initialPattern, int maxGeneration)
        : generation(0),rows(10), cols(10),   grid(rows, std::vector<char>(cols, ' ')),maxGeneration(maxGeneration), m_widget(parent) {

        // Place the initial pattern in the middle of the grid
        int startRow = (rows - initialPattern.size()) / 2;
        int startCol = (cols - initialPattern[0].size()) / 2;

        for (size_t i = 0; i < initialPattern.size(); ++i) {
            for (size_t j = 0; j < initialPattern[i].size(); ++j) {
                grid[startRow + i][startCol + j] = initialPattern[i][j];
            }
        }
        qDebug()<< "this will run for"<< this->maxGeneration << "generations";


        this->moveToThread(&workerThread);

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
    auto randomChar = []() {
            return (std::rand() % 2 == 0) ? '.' : 'X';
        };
    for (auto& row : grid) {
            std::generate(row.begin(), row.end(), randomChar);
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

    std::swap(grid, newGrid);
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


void GameOfLife::clear(){
    std::fill(grid.begin(), grid.end(), std::vector<char>(cols, '.'));

}
void GameOfLife::setQuadrant(int quadrant){
    this->quadrant=quadrant;
}

void GameOfLife::process(){
    while ( this->generation < this->maxGeneration && !this->isGridEmpty()) {

        this->updateGrid();
        m_widget->setData(this->grid, this->quadrant);
        QThread::usleep(100000);
    }
    this->clear();
    m_widget->setData(this->grid, this->quadrant);
    m_widget->enableButtons(this->quadrant);

}



