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

    //connect(ui->pushButton, SIGNAL(clicked()),this, SLOT(plotData()));
    connect(ui->pushButton, SIGNAL(clicked()),this, SLOT(plotECG()));
    //connect(ui->pushButton, SIGNAL(clicked()),this, SLOT(plotMarta()));
}

Widget::~Widget()
{
    delete ui;
}

// Function to detect R-peaks in ECG signal
vector<double> detectRPeaks(const vector<double>& ecgSignal, double samplingRate)
{
    vector<double> rPeaks;

    // Constants for the Pan-Tompkins algorithm (you may need to adjust these)
    const double WINDOW_MS = 200.0; // Window size for QRS detection in milliseconds
    const double MIN_RR_MS = 300.0;  // Minimum expected distance between R-peaks in milliseconds

    // Convert window size to number of samples
    int windowSize = static_cast<int>((WINDOW_MS / 1000.0) * samplingRate);

    // Differentiation filter coefficients
const double a[] = {-2.0, -1.0, 0.0, 1.0, 2.0};
    const double b[] = {1.0 / 32, 1.0 / 16, 0.0, -1.0 / 16, -1.0 / 32};

    // Apply differentiation filter
    vector<double> diffSignal;
    for (int i = 2; i < ecgSignal.size() - 2; ++i)
    {
        double result = 0.0;
        for (int j = 0; j < 5; ++j)
        {
            result += b[j] * ecgSignal[i - j];
            result -= a[j] * ecgSignal[i - j - 1];
        }
        diffSignal.push_back(result);
    }

    // Square the differentiated signal
    vector<double> squaredSignal(diffSignal.size());
    transform(diffSignal.begin(), diffSignal.end(), squaredSignal.begin(), [](double x) { return x * x; });

    // Moving average to smooth the squared signal
    vector<double> movingAvgSignal;
    for (int i = 0; i < squaredSignal.size(); ++i)
    {
        int start = max(0, i - windowSize / 2);
        int end = min(static_cast<int>(squaredSignal.size()), i + windowSize / 2 + 1);
        double sum = accumulate(squaredSignal.begin() + start, squaredSignal.begin() + end, 0.0);
        movingAvgSignal.push_back(sum / (end - start));
    }

    // Find peaks in the moving average signal (thresholding)
    double threshold = 0.6 * (*max_element(movingAvgSignal.begin(), movingAvgSignal.end()));
    bool inPeak = false;
    for (int i = 0; i < movingAvgSignal.size(); ++i)
    {
        if (movingAvgSignal[i] > threshold)
        {
            if (!inPeak)
            {
                rPeaks.push_back(i);
                // Skip the next MIN_RR_MS milliseconds to avoid detecting multiple peaks for the same beat
                int skipSamples = static_cast<int>((MIN_RR_MS / 1000.0) * samplingRate);
                i += skipSamples;
                inPeak = true;
            }
        }
        else
        {
            inPeak = false;
        }
    }

    return rPeaks;
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
        vector<double> rPeaks = detectRPeaks(Y, samplingRate);

        // Print the detected R-peaks
        cout << "Detected R-peaks: ";
        for (int peak : rPeaks)
        {
            cout << peak << " ";
        }
        cout << endl;


    // Plot data
    ui->widget->graph(0)->setData(QVector<double>::fromStdVector(X), QVector<double>::fromStdVector(Y));
    // Rescale axes and replot
    ui->widget->rescaleAxes();
    ui->widget->replot();


}

double avgHeartRate(){
    return 0.0;
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
void Widget::plotMarta(){
    QFile file("../ekg.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug() << "Failed to open EEG data file.";
            return;
        }

        // Create vectors to store X and Y values
        std::vector<double> X;
        std::vector<double> Y;

        // Read the entire line from the file
        QString line = file.readLine();

        // Close the file
        file.close();

        // Split the line into individual values
        QStringList values = line.split(" ", QString::SkipEmptyParts);

        // Convert and store values in the Y vector
        for (const QString& value : values)
        {
            double num = value.toDouble();
            Y.push_back(num);
            X.push_back(X.size());
        }

        if (X.empty() || Y.empty())
            {
                qDebug() << "X and/or Y vectors are empty. Cannot plot empty data.";
                return;
            }


        // Add a graph and set properties
        connect(ui->widget,SIGNAL(mouseDoubleClick(QMouseEvent*)),
        ui->widget, SLOT(rescaleAxes()) );
        ui->widget->addGraph();
        ui->widget->xAxis->setLabel("Time");
        ui->widget->yAxis->setLabel("EKG Value");
        ui->widget->xAxis->grid()->setSubGridVisible(true);

        // Plot data
        ui->widget->graph(0)->setData(QVector<double>::fromStdVector(X),
                                      QVector<double>::fromStdVector(Y));

        // Rescale and replot
        ui->widget->rescaleAxes();
        ui->widget->replot();
}
