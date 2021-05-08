import QtQuick 2.15
import QtQuick.Window 2.15
import KLib 1.0

Window {
    width: 640
    height: 640
    visible: true
    title: qsTr("perceptron")

    PerceptronTrainer {
        id: trainer
    }
    PerceptronView {
        perceptron: trainer.perceptron
        p: trainer.p
        anchors.fill: parent
    }
    Repeater {
        model: trainer.points
        PointView {
            point: modelData
            anchors.fill: parent
        }
    }
    Text {
        text: "running: " + trainer.running
    }
}
