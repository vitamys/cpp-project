#include "widget.h"
#include "ui_widget.h"
#include <iostream>
#include <fstream>

using namespace std;


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()),this, SLOT(plotData()));
    //connect(ui->pushButton, SIGNAL(clicked()),this, SLOT(plotECG()));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::plotECG()
{
    connect(ui->widget,SIGNAL(mouseDoubleClick(QMouseEvent*)),
    ui->widget, SLOT(rescaleAxes()) );
    // Add Graph and set some properties
    ui->widget->addGraph();
    ui->widget->xAxis->setLabel("Time [s]");
    ui->widget->yAxis->setLabel("Signal [au]");
    ui->widget->xAxis->grid()->setSubGridVisible(true);

    //read data from txt file
    std::ifstream stream("ecg.txt");
       if(!stream){
           cout << "WARNING: File not found!" << endl;
       }

    std::istream_iterator<double> start(stream), end;
    std::vector<double> X(start,end);
    std::vector<double> Y(X.size());

    // Plot data
    ui->widget->graph(0)->setData(QVector<double>(X.begin(),X.end()),
    QVector<double>(Y.begin(),Y.end()));
    //
    ui->widget->rescaleAxes();
    ui->widget->replot();


}

void Widget::plotData()
{
    // Set userinteraction : zoom and drag
    //ui->widget->setInteraction(QCP::iRangeDrag,true);
    //ui->widget->setInteraction(QCP::iRangeZoom,true);
    connect(ui->widget,SIGNAL(mouseDoubleClick(QMouseEvent*)),
    ui->widget, SLOT(rescaleAxes()) );
    // Add Graph and set some properties
    ui->widget->addGraph();
    ui->widget->xAxis->setLabel("X");
    ui->widget->yAxis->setLabel("Y");
    ui->widget->xAxis->grid()->setSubGridVisible(true);
    // Create data : f (x) = x^2
    std::vector<double> X(101);
    std::iota(X.begin(),X.end(),-50);
    std::vector<double> Y(101);
    std::transform(X.begin(),X.end(),
    Y.begin(),
    [](double x){return x*x;});
    // Plot data
    ui->widget->graph(0)->setData(QVector<double>::fromStdVector(X), QVector<double>::fromStdVector(Y));
    //
    ui->widget->rescaleAxes();
    ui->widget->replot();
}
