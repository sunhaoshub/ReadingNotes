#include "mouseselectionrectwidget.h"
#include "ui_mouseselectionrectwidget.h"

#include <QPainter>

MouseSelectionRectWidget::MouseSelectionRectWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MouseSelectionRectWidget)
{
    ui->setupUi(this);
}

MouseSelectionRectWidget::~MouseSelectionRectWidget()
{
    delete ui;
}

void MouseSelectionRectWidget::mousePressEvent(QMouseEvent *event)
{
    modifyMode = true;
    rect.setTopLeft(event->pos());
}

void MouseSelectionRectWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(modifyMode)
    {
        rect.setBottomRight(event->pos());
        update();
    }
}

void MouseSelectionRectWidget::mouseReleaseEvent(QMouseEvent *event)
{
    modifyMode = false;
}

void MouseSelectionRectWidget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.drawRect(rect);
}
