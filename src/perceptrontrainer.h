#ifndef APPCORE_H
#define APPCORE_H

#include "perceptron.h"

#include <QObject>
#include <klibcore/src/kmacro.h>
#include <QLineF>
#include <functional>

class PerceptronTrainer: public QObject {
    Q_OBJECT
    K_QML_TYPE(PerceptronTrainer)

    K_READONLY_PROPERTY(Perceptron<double>, perceptron, perceptron, setPerceptron, perceptronChanged, Perceptron<double>())
    K_READONLY_PROPERTY(double, p, p, setP, pChanged, 0)
    K_READONLY_PROPERTY(QList<QPointF>, points, points, setPoints, pointsChanged, QList<QPointF>())
    K_READONLY_PROPERTY(bool, running, running, setRunning, runningChanged, false)

    void update();

public:
    typedef QPair<QPointF, std::function<bool(double, double)>> Receipt;
private:

    QVector<Receipt> m_receipts;
    double m_sigma;
    int m_maxIterationCount;
    size_t m_iteration = 0;

public:
    explicit PerceptronTrainer(QObject *parent = nullptr);

    void run(QVector<Receipt> receipts,
             double p,
             Perceptron<double> perceptron,
             double sigma,
             int maxIterationCount
             );

signals:

};

#endif // APPCORE_H
