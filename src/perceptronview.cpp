#include "perceptronview.h"

#include <QPainter>
#include <QTimer>

#include <math.h>

PerceptronView::PerceptronView(){
    connect(this, &PerceptronView::perceptronChanged, this, [this](){
        update();
    });
    connect(this, &PerceptronView::pChanged, this, [this](){
        update();
    });
}


void PerceptronView::paint(QPainter *painter) {
    auto surface = QImage(width(), height(), QImage::Format_ARGB32);
    if(!surface.isNull()) {
        int imageHeight = static_cast<int>(height());
        for (auto y = imageHeight - 1; y >= 0; --y) {
            auto line = reinterpret_cast<uint32_t*>(surface.scanLine(y));
            for (auto x = 0; x < surface.bytesPerLine() / 4; ++x) {
                auto value = perceptron().proceed({ double(x), double(y) });
                if (value > p()) {
                    line[x] = 0xffffff00;
                } else {
                    line[x] = 0xff00ffff;
                }
            }
        }
        painter->setRenderHints(QPainter::Antialiasing, true);
        painter->drawImage(0, 0, surface);
    }
}
