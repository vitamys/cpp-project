#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void plotData();
    void plotECG();
    void plotMarta();

private:
    Ui::Widget *ui;
    double samplingRate = 360.0;
};

#endif // WIDGET_H
