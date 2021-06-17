# perceptron


Visualization of trained percepron. It divined space into two parts so that two points be on one side and other two points on other side

```
{ QPointF(0, 600), [](double v, double p){ return v > p; } },
{ QPointF(100, 500), [](double v, double p){ return v > p; } },
{ QPointF(300, 300), [](double v, double p){ return v < p; } },
{ QPointF(200, 400), [](double v, double p){ return v < p; } }
```

![alt text](https://github.com/burbokop/perceptron/blob/master/result.png)
