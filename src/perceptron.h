#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <QList>
#include <klibcore/src/kmacro.h>

template<typename T>
class Perceptron {
    //K_META_TYPE_ALIAS(Perceptron<T>, Perceptron)
    QList<T> m_w;
    size_t m_iteration = 0;
public:
    typedef T value_type;
    typedef typename QList<T>::const_iterator const_iterator;
    auto begin() const { return m_w.begin(); }
    auto begin() { return m_w.begin(); }
    auto end() const { return m_w.begin(); }
    auto end() { return m_w.begin(); }

    Perceptron(const QList<T> &w): m_w(w) {}
    Perceptron() {}

    T proceed(const QList<T> &x) const {
        T result = {};
        for (auto i = 0; i < std::min(m_w.size(), x.size()); ++i) {
            result += m_w[i] * x[i];
        }
        return result;
    }

    std::pair<T, Perceptron<T>> next(const QList<T> &x, const T &p, double sigma) {
        auto proceedResult = proceed(x);
        auto delta = p - proceedResult;
        auto result = QList<T>();
        for (auto i = 0; i < std::min(m_w.size(), x.size()); ++i) {
            result.push_back(x[i] * delta * sigma + m_w[i]);
        }
        qDebug() << "it:" << m_iteration << "res:" << result << "<-" << proceedResult << "<-" << x << p << "sigma:" << sigma;

        auto nextPerceptron = Perceptron(result);
        nextPerceptron.m_iteration = m_iteration + 1;
        return { proceedResult, nextPerceptron };
    }
    QList<T> w() const { return m_w; }
    size_t iteration() const { return m_iteration; }
};

template <typename T>
bool operator==(const Perceptron<T> &p0, const Perceptron<T> &p1) {
    return p0.w() == p1.w();
}

//Q_DECLARE_METATYPE_TEMPLATE_1ARG(Perceptron)
Q_DECLARE_METATYPE(Perceptron<double>)

#endif // PERCEPTRON_H
