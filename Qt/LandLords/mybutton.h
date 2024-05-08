#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>
#include<QString>
#include<QPixmap>

class MyButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyButton(QWidget *parent = nullptr);
    void setImage(QString normal,QString hover,QString press);
signals:

public slots:


protected:
    //鼠标按下
    void mousePressEvent(QMouseEvent* ev);
    //鼠标释放
    void mouseReleaseEvent(QMouseEvent* ev);
    //鼠标进入 但没有按下
    void enterEvent(QEvent* ev);
    //鼠标离开
    void leaveEvent(QEvent* ev);
    //绘图
    void paintEvent(QPaintEvent* ev);
private:
    QString m_normal;
    QString m_hover;
    QString m_press;
    QPixmap m_pixmap;
};

#endif // MYBUTTON_H
