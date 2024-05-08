#include "mybutton.h"
#include<QMouseEvent>
#include<QPainter>
#include<QDebug>
MyButton::MyButton(QWidget *parent) : QPushButton(parent)
{

}

void MyButton::setImage(QString normal, QString hover, QString press)
{
    m_normal = normal;
    m_hover = hover;
    m_press = press;
    m_pixmap.load(m_normal);
    update();//触发paintEvent
    qDebug()<<"22222222222";
}

void MyButton::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton)
    {
        m_pixmap.load(m_press);
        update();
    }
    QPushButton::mousePressEvent(ev);
}

void MyButton::mouseReleaseEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton)
    {
        m_pixmap.load(m_normal);
        update();
    }
    QPushButton::mouseReleaseEvent(ev);
}

void MyButton::enterEvent(QEvent *ev)
{
    Q_UNUSED(ev)
    m_pixmap.load(m_hover);
    update();
}

void MyButton::leaveEvent(QEvent *ev)
{
    Q_UNUSED(ev)
    m_pixmap.load(m_normal);
    update();
}

void MyButton::paintEvent(QPaintEvent *ev)
{
    Q_UNUSED(ev)
    QPainter p(this);
    p.drawPixmap(rect(),m_pixmap);
    qDebug()<<"1111111111111111";

}
