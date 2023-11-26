#ifndef QUADRATICWIDGET_H
#define QUADRATICWIDGET_H


#include <QWidget>
#include <QResizeEvent>

class QuadraticWidget : public QWidget {
public:
    QuadraticWidget(QWidget* parent = nullptr) : QWidget(parent) {}

protected:
    void resizeEvent(QResizeEvent* event) override {
        // Ensure that the widget is always quadratic
        int size = qMin(event->size().width(), event->size().height());
        resize(size, size);

        // Call the base class implementation
        QWidget::resizeEvent(event);
    }
};

#endif // QUADRATICWIDGET_H
