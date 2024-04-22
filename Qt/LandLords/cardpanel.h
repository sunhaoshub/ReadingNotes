#ifndef CARDPANEL_H
#define CARDPANEL_H

#include <QWidget>
#include<QPixmap>
#include"card.h"
#include"player.h"

class CardPanel : public QWidget
{
    Q_OBJECT
public:
    explicit CardPanel(QWidget *parent = nullptr);
    //设置图片   显示图片用QPixmap，传输或者修改使用QImage
    void setImage(QPixmap& front,QPixmap &back);
    //获取图片 背面都一样，所以只看前面
    QPixmap getImage();

    //获取扑克牌哪一面
    void setFrontSide(bool flag);
    bool isFrontSide();

    //窗口是否被选中
    void setSelected(bool flag);
    bool isSelected();

    //扑克牌数据信息
    void setCard(Card& card);
    Card getCard();

    //扑克牌所有者 Card不用指针类型Player用指针类型？？？
    void setOwner(Player* player);
    Player* getOwner();

protected:
    //绘制扑克牌，使用绘图事件QPainter
    void paintEvent(QPaintEvent* event);
    //鼠标点击时间
    void mousePressEvent(QMouseEvent* event);

signals:

public slots:

private:
    QPixmap m_front;
    QPixmap m_back;
    bool m_isfront;
    bool m_isSelect;
    Card m_card;
    Player* m_owner;
};

#endif // CARDPANEL_H
