#include "gameOfLife.h"
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <algorithm>

GameOfLife::GameOfLife(int size) : rows(size), cols(size), generation(0) {
    // Initialize the grid with random values
    grid.resize(rows, std::vector<char>(cols, '.'));
    randomizeGrid();
}


GameOfLife::GameOfLife(const std::vector<std::vector<char>>& initialPattern, int size)
        : rows(size), cols(size), generation(0), grid(rows, std::vector<char>(cols, ' ')) {

        // Place the initial pattern in the middle of the grid
        int startRow = (rows - initialPattern.size()) / 2;
        int startCol = (cols - initialPattern[0].size()) / 2;

        for (int i = 0; i < initialPattern.size(); ++i) {
            for (int j = 0; j < initialPattern[i].size(); ++j) {
                grid[startRow + i][startCol + j] = initialPattern[i][j];
            }
        }
    }

void GameOfLife::randomizeGrid() {
    // Fill the grid with random live ('X') and dead (' ') cells
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
    //TODO: replace with stl
    for (const auto &row : grid) {
        for (char cell : row) {
            if (cell == 'X') {
                return false;
            }
        }
    }

    return true;
}

const std::vector<std::vector<char>>& GameOfLife::getGrid() const {
       return grid;
   }

void GameOfLife::clear(){
    for_each(grid.begin(), grid.end(), [](std::vector<char>& row) {
        std::fill(row.begin(), row.end(), '.');
    });
}


