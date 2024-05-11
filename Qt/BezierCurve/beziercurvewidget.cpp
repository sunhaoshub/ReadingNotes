#include "beziercurvewidget.h"
#include "ui_beziercurvewidget.h"

#include <QPainter>

BezierCurveWidget::BezierCurveWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BezierCurveWidget)
{
    ui->setupUi(this);
    // 贝塞尔曲线的端点
    breakPoints.append(new QPointF(0, 0));
    breakPoints.append(new QPointF(100, 100));
    breakPoints.append(new QPointF(200, 0));
    breakPoints.append(new QPointF(300, 100));

    // 第一段贝塞尔曲线控制点
    controlPoints.append(new QPointF(50, 0));
    controlPoints.append(new QPointF(50, 100));

    // 第二段贝塞尔曲线控制点
    controlPoints.append(new QPointF(150, 100));
    controlPoints.append(new QPointF(150, 0));

    // 第三段贝塞尔曲线控制点
    controlPoints.append(new QPointF(250, 0));
    controlPoints.append(new QPointF(250, 100));

    bezierCurve = createBezierCurve();
    flags = Qt::AlignHCenter | Qt::AlignVCenter;
    controlPointRadius = 8;
    translatedX = 50;
    translatedY = 50;
}

BezierCurveWidget::~BezierCurveWidget()
{
    delete ui;
    qDeleteAll(breakPoints);
    qDeleteAll(controlPoints);
}

QPainterPath BezierCurveWidget::createBezierCurve()
{
    QPainterPath path;
    path.moveTo(*breakPoints.at(0));
    path.cubicTo(*controlPoints[0],*controlPoints[1],*breakPoints[1]);
    path.cubicTo(*controlPoints[2],*controlPoints[3],*breakPoints[2]);
    path.cubicTo(*controlPoints[4],*controlPoints[5],*breakPoints[3]);
    return path;
}

QPointF BezierCurveWidget::translatedPoint(const QPointF &point) const
{
    return point-QPointF(translatedX,translatedY);
}

QRect BezierCurveWidget::createControlPointBundingRect(int index)
{
    int x = controlPoints.at(index)->x()-controlPointRadius;
    int y = controlPoints.at(index)->y()-controlPointRadius;

    return QRect(x,y,controlPointRadius*2,controlPointRadius*2);
}

void BezierCurveWidget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);
    p.translate(translatedX,translatedY);

    //绘制贝塞尔曲线
    p.drawPath(bezierCurve);

    //绘制控制点及序号
    p.setBrush(Qt::gray);
    for(int i = 0;i < controlPoints.size();i++)
    {
        QRect rect = createControlPointBundingRect(i);
        p.drawEllipse(rect);
        p.drawText(rect,flags,QString("%1").arg(i));
    }
}

void BezierCurveWidget::mousePressEvent(QMouseEvent *event)
{
    PressedControlPointIndex = -1;

        // 绘制贝塞尔曲线和控制点的坐标系做了偏移，鼠标按下的坐标也要相应的偏移
        QPointF p = translatedPoint(event->pos());

        // 鼠标按下时，选择被按住的控制点
        for (int i = 0; i < controlPoints.size(); ++i) {
            QPainterPath path;
            path.addEllipse(*controlPoints.at(i), controlPointRadius, controlPointRadius);

            if (path.contains(p)) {
                PressedControlPointIndex = i;
                break;
            }
        }
}

void BezierCurveWidget::mouseMoveEvent(QMouseEvent *event)
{
    // 移动选中的控制点
        if (PressedControlPointIndex != -1) {
            QPointF p = translatedPoint(event->pos());
            controlPoints.at(PressedControlPointIndex)->setX(p.x());
            controlPoints.at(PressedControlPointIndex)->setY(p.y());
            bezierCurve = createBezierCurve(); // 坐标发生变化后重新生成贝塞尔曲线
            update(); // 刷新界面
        }
}
