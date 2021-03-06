#include "perceptron.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    qRegisterMetaType<Perceptron<double>>();

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/resources/qml/main.qml"));
    engine.load(url);

    return app.exec();
}
