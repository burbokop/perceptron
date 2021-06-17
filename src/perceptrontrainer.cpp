#include "perceptrontrainer.h"

#include <QTimer>
#include <random>

#include <src/math/kmath.h>

void PerceptronTrainer::update() {
    if (m_maxIterationCount > 0 && m_running) {
        if(m_iteration > 20) {
            //якщо пошук відповіді виконується більше ніж 0.1 секунду, тоді "сігма" випадково збільшується або зменшується на 10% і спроба повторюється
            //я зробив залежність від кількості ітерацій а не від часу, тому, що рахування наступного набору вагів робиться з інтервалом 50 мілісекунд,
            //щоб частину процесопрного часу віддати на малювання графіки
            if(KMath::instance()->random() > 0.5) {
                m_sigma = m_sigma * 1.1;
            } else {
                m_sigma = m_sigma * 0.9;
            }
            qDebug() << "new sigma:" << m_sigma;
            m_iteration = 0;
        }

        auto currentReceipt = m_receipts[m_maxIterationCount % m_receipts.size()];
        auto next = m_perceptron.next(QList<double>{ currentReceipt.first.x(), currentReceipt.first.y() }, p(), m_sigma);
        m_iteration++;
        bool allTrue = true;
        for(auto& receipt : m_receipts) {
            if (!receipt.second(next.second.proceed({ receipt.first.x(), receipt.first.y() }), p())) {
                allTrue = false;
                break;
            }
        }
        if (allTrue) {
            setRunning(false);
        }
        setPerceptron(next.second);
        m_maxIterationCount--;
    } else {
        setRunning(false);
    }
}

PerceptronTrainer::PerceptronTrainer(QObject *parent) : QObject(parent) {
    auto timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &PerceptronTrainer::update);
    timer->start(50);

    QTimer::singleShot(2000, this, [this](){
        const auto r = QVector<Receipt> {
        { QPointF(0, 600), [](double v, double p){ return v > p; } },
        { QPointF(100, 500), [](double v, double p){ return v > p; } },
        { QPointF(300, 300), [](double v, double p){ return v < p; } },
        { QPointF(200, 400), [](double v, double p){ return v < p; } }
    };

        run(r,
            400,
            Perceptron<double>({0, 0}),
            0.000005,
            1000
            );
    });
}


void PerceptronTrainer::run(QVector<Receipt> receipts, double p, Perceptron<double> perceptron, double sigma, int maxIterationCount) {
    if (receipts.size() > 1) {
        m_iteration = 0;
        setPerceptron(perceptron);
        m_receipts = receipts;
        setP(p);
        m_sigma = sigma;
        m_maxIterationCount = maxIterationCount;

        QList<QPointF> points;
        for(const auto& receipt : m_receipts) {
            points.append(receipt.first);
        }
        setPoints(points);
        setRunning(true);
    }
}
