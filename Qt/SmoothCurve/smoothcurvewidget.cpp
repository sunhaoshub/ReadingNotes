#include "smoothcurvewidget.h"
#include "ui_smoothcurvewidget.h"

SmoothCurveWidget::SmoothCurveWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SmoothCurveWidget)
{
    ui->setupUi(this);
}

SmoothCurveWidget::~SmoothCurveWidget()
{
    delete ui;
}

void SmoothCurveWidget::paintEvent(QPaintEvent *event)
{

}

void SmoothCurveWidget::generateCurve()
{

}
