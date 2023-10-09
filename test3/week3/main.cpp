#include <iostream>
#include <QApplication>
#include "widget.h"
#include <math.h>

using namespace std;

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
