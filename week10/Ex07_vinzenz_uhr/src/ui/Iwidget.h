#ifndef IWIDGET_H
#define IWIDGET_H
#include "dataBuffer.h"
#include <QWidget>
class Iwidget : public QWidget
{
    Q_OBJECT

public:
    explicit Iwidget(QWidget *parent = nullptr): QWidget(parent){};
    virtual ~Iwidget(){};

    virtual void displayMsg(std::string tag, std::string msg) = 0;
    virtual void setData(DataBufferPtr data) = 0;
};
#endif // IWIDGET_H
