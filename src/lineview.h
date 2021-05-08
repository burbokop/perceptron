#ifndef LINEVIEW_H
#define LINEVIEW_H

#include <QQuickPaintedItem>

class LineView : public QQuickPaintedItem {
    Q_OBJECT

public:
    LineView();

signals:


    // QQuickPaintedItem interface
public:
    void paint(QPainter *painter);
};

#endif // LINEVIEW_H
