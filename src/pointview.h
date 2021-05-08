#ifndef POINTVIEW_H
#define POINTVIEW_H

#include <QQuickPaintedItem>
#include <QPointF>
#include <klibcore/src/kmacro.h>

class PointView : public QQuickPaintedItem {
    Q_OBJECT
    K_QML_TYPE(PointView)
    K_AUTO_PROPERTY(QPointF, point, point, setPoint, pointChanged, QPointF())
public:
        explicit PointView(QQuickItem *parent = nullptr);

signals:


    // QQuickPaintedItem interface
public:
    void paint(QPainter *painter);
};

#endif // POINTVIEW_H
