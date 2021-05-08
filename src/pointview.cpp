#include "pointview.h"

#include <QPainter>

PointView::PointView(QQuickItem *parent) : QQuickPaintedItem(parent) {
    connect(this, &PointView::pointChanged, this, [this](QPointF){
        update();
    });
}

void PointView::paint(QPainter *painter) {  painter->drawEllipse(point(), 2, 2); }
