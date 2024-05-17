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

# QCustomPlot

* 需要将widget提升为QCustomplot类

* replot函数相当于重新绘制图形
* 绘制单条曲线

```C++
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<qcustomplot.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QVector<double>x(101),y(101);
    for(int i = 0;i <101;i++)
    {
        x[i] = i/50.0 -1;
        y[i] = x[i]*x[i];
    }
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x,y);
    ui->customPlot->xAxis->setRange(-1,1);
    ui->customPlot->yAxis->setRange(0,1);
    ui->customPlot->xAxis->ticker()->setTickCount(6);
    //设置点之间的连接方式
    //ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsImpulse);
    //设置线的形态：虚线、连线、线段...
    //ui->customPlot->graph(0)->setPen(Qt::DotLine);
    //散点形态
    //ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    //ui->customPlot->graph(0)->setBrush(Qt::gray);
    ui->customPlot->replot();
}

MainWindow::~MainWindow()
{
    delete ui;
}

```

* 绘制多条曲线

```C++
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<qcustomplot.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->customPlot->addGraph();
    ui->customPlot->addGraph();

    QVector<double>x(251),y0(251),y1(251);
    for(int i  = 0;i < x.size();i++)
    {
         x[i] = i;
        y0[i] = qExp(-i/150.0)*qCos(i/10.0);
        y1[i] = qExp(-i/150.0);
    }
    ui->customPlot->graph(0)->setData(x,y0);
    ui->customPlot->graph(1)->setData(x,y1);
    ui->customPlot->graph(0)->setBrush(QColor(0,0,255,20));
    ui->customPlot->graph(0)->setPen(QPen(Qt::blue));
    ui->customPlot->graph(1)->setPen(QPen(Qt::red));

    ui->customPlot->xAxis2->setVisible(true);
    ui->customPlot->xAxis2->setTickLabels(false);
    ui->customPlot->yAxis2->setVisible(true);
    ui->customPlot->yAxis2->setTickLabels(false);

    connect(ui->customPlot->xAxis,SIGNAL(rangeChanged(QCPRange)),ui->customPlot->xAxis2,SLOT(setRange(QCPRange)));
    connect(ui->customPlot->yAxis,SIGNAL(rangeChanged(QCPRange)),ui->customPlot->yAxis2,SLOT(setRange(QCPRange)));

    // let the ranges scale themselves so graph 0 fits perfectly in the visible area:
    ui->customPlot->graph(0)->rescaleAxes();
    // same thing for graph 1, but only enlarge ranges (in case graph 1 is smaller than graph 0):
    ui->customPlot->graph(1)->rescaleAxes(true);
    // Note: we could have also just called customPlot->rescaleAxes(); instead
    // Allow user to drag axis ranges with mouse, zoom with mouse wheel and select graphs by clicking:
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

}

MainWindow::~MainWindow()
{
    delete ui;
}

```

