# QChart

以曲线图为例：

1. 确定好配置（Series）

```C++
QSplineSeries *series = new QSplineSeries();
```

2. 添加点
3. 通过QChart类作为容器来存储配置（addSeries函数）、
4. 通过QChartView展示图表

```C++
#include <QApplication>
#include<QSplineSeries>
#include<QChart>
#include<QtCharts/qchartview.h>
#include<QMainWindow>

QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplineSeries* series = new QSplineSeries();

    //series->append(1,1);
    series->append(0, 6);
    series->append(2, 4);
    series->append(3, 8);
    series->append(7, 4);
    series->append(10, 5);
    *series<<QPointF(11,4)<<QPointF(12,8)<<QPointF(14,6)<<QPointF(16,2)<<QPointF(19,9);


    QChart* chart = new QChart();
    chart->setTitle("test curve");
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->axisY()->setRange(0,10);
    chart->legend()->hide();

    QChartView* view = new QChartView(chart);
    view->setRenderHint(QPainter::Antialiasing);

    QMainWindow window;
    window.setCentralWidget(view);
    window.resize(500,500);
    window.show();
    return a.exec();
}

```

