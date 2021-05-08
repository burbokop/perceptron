#ifndef LINEVIEW_H
#define LINEVIEW_H

#include <QQuickPaintedItem>
#include <klibcore/src/kmacro.h>
#include <QImage>
#include <QLineF>
#include "perceptron.h"

class PerceptronView : public QQuickPaintedItem {
    Q_OBJECT
    K_QML_TYPE(PerceptronView)

    K_AUTO_PROPERTY(Perceptron<double>, perceptron, perceptron, setPerceptron, perceptronChanged, Perceptron<double>())
    K_AUTO_PROPERTY(double, p, p, setP, pChanged, 0)

public:
    PerceptronView();

signals:


    // QQuickPaintedItem interface
public:
    void paint(QPainter *painter);
};

#endif // LINEVIEW_H
