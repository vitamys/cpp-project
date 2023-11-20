#include <iostream>
#include <QApplication>
#include "widget.h"
#include <math.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <unistd.h>  // for sleep function

#include <gameOfLife.h>
#include <pattern.h>

using namespace std;





//int main() {
//    // Use either the default constructor for a random initial state
//    GameOfLife game(Patterns::beacon(),10);

//    // Or use the constructor with a filename to load a pattern from a text file
//    //GameOfLife game("beacon.txt", 10);

//    const int maxGenerations = 50;

//    while (!game.isGridEmpty() && game.generation < maxGenerations) {
//        game.printGrid();
//        game.updateGrid();
//        usleep(100000); // Sleep for 100 milliseconds (adjust as needed)
//    }

//    return 0;
//}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();

}
