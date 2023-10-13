#include "widget.h"
#include "ui_widget.h"
#include <iostream>
#include <fstream>
#include <tuple>


using namespace std;


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()),this, SLOT(plotECG()));
}

Widget::~Widget()
{
    delete ui;
}

// Function to detect R-peaks in ECG signal
auto detectRPeaks(const vector<double>& Y, double samplingRate)
{
    struct result {std::vector<double> peaks; std::vector<double> positions;};
    std::vector<double> rPeaks;
    std::vector<double> positions;

    for (std::size_t i = 0; i < Y.size(); ++i) {

        if (Y[i] > 1150) {
            //check if it is actually a peak
            if(Y[i]> Y[i-1] && Y[i]> Y[i+1]){
                rPeaks.push_back(Y[i]);
                positions.push_back(static_cast<double>(i) / samplingRate);
            }
        }
    }

    return result{rPeaks, positions};
}
double avgHeartRate(const vector<double>& rPeaks, const vector<double>& positions){
    double heartRate;

    double totalTime = positions.back()-positions.front();

    double totalBeats = rPeaks.size();
    heartRate= totalBeats/totalTime*60.0;

    return heartRate;
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
    std::ifstream stream("../ekg.txt");
    assert(stream.is_open());
       if(!stream){
           cout << "WARNING: File not found!" << endl;
           return;
       }

    std::istream_iterator<double> start(stream), end;
    std::vector<double> Y(start,end);
    // Check if any data was read
        if (Y.empty())
        {
            cout << "ERROR: No data found in the file!" << endl;
            return;
        }

    // Create X values based on the sampling rate (360 Hz)
    vector<double> X(Y.size());
    for (int i = 0; i < X.size(); ++i)
    {
       X[i] = static_cast<double>(i) / samplingRate; // Time in seconds
       }

    // Detect R-peaks
     auto[peaks, positions]  = detectRPeaks(Y, samplingRate);

    //calculate heart rate
    double heartRate = avgHeartRate(peaks, positions);

    // Plot ECG data
    ui->widget->graph(0)->setData(QVector<double>::fromStdVector(X), QVector<double>::fromStdVector(Y));

    //plot peaks
    QCPGraph *peakPoints = ui->widget->addGraph();
    peakPoints->setPen(QPen(Qt::red));
    peakPoints->setLineStyle(QCPGraph::lsNone);
    peakPoints->setScatterStyle(QCPScatterStyle::ssCircle);

    peakPoints->setData(QVector<double>::fromStdVector(positions), QVector<double>::fromStdVector(peaks));

     //display heart rate in label
     QString text ="Average Heart Rate: " + QString::number(heartRate, 'f', 2) + " bpm";
     QLabel *label = new QLabel(this);
     label->setText(text);
     label->setFixedHeight(35);

     ui->verticalLayout->addWidget(label);


    // Rescale axes and replot
    ui->widget->rescaleAxes();
    ui->widget->replot();



}


