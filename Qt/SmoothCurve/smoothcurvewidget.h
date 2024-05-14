#ifndef SMOOTHCURVEWIDGET_H
#define SMOOTHCURVEWIDGET_H

#include <QWidget>

namespace Ui {
class SmoothCurveWidget;
}

class SmoothCurveWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SmoothCurveWidget(QWidget *parent = 0);
    ~SmoothCurveWidget();

private:
    Ui::SmoothCurveWidget *ui;
    QList<QPointF> knots;        // 曲线上的点
    QPainterPath smoothCurve1;   // 平滑曲线
    QPainterPath smoothCurve2;   // 平滑曲线
    QPainterPath nonSmoothCurve; // 直接连接点的非平滑曲线
protected:
    void paintEvent(QPaintEvent* event) override;
private slots:
    void generateCurve();
};

#endif // SMOOTHCURVEWIDGET_H
