#ifndef BEZIERCURVEWIDGET_H
#define BEZIERCURVEWIDGET_H

#include <QWidget>
#include<QList>
#include<QPointF>
#include<QPainterPath>
#include<QPointF>

namespace Ui {
class BezierCurveWidget;
}

class BezierCurveWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BezierCurveWidget(QWidget *parent = 0);
    ~BezierCurveWidget();
    QPainterPath createBezierCurve();//创建贝塞尔曲线
    QPointF translatedPoint(const QPointF& point) const;//
    QRect createControlPointBundingRect(int index);//绘制坐标的外接矩形

private:
    Ui::BezierCurveWidget *ui;
    QPainterPath bezierCurve;
    QList<QPointF*> breakPoints;
    QList<QPointF*> controlPoints;
    int flags;
    int PressedControlPointIndex;//按下的按钮下标
    int controlPointRadius;//按钮半径

    int translatedX; // 坐标系 X 轴的偏移量
    int translatedY; // 坐标系 Y 轴的偏移量

protected:
    void paintEvent(QPaintEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
};

#endif // BEZIERCURVEWIDGET_H
