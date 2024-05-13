#include "widget.h"
#include "ui_widget.h"

#include <QMouseEvent>
#include<QDebug>
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
    update();
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    lastPos = event->pos();
    update();
    qDebug()<<lastPos;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);

    //绘制纵向线
    p.drawLine(lastPos.x(),0,lastPos.x(),height());
    //绘制横向线
    p.drawLine(0,lastPos.y(),width(),lastPos.y());
}
