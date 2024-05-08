#ifndef BUTTONGROUP_H
#define BUTTONGROUP_H

#include <QWidget>

namespace Ui {
class ButtonGroup;
}

class ButtonGroup : public QWidget
{
    Q_OBJECT

public:
    explicit ButtonGroup(QWidget *parent = 0);
    enum Panel{Start,PlayCard,PlayorPass,CallLord,Empty};
    ~ButtonGroup();
    //初始化栈widget按钮
    void initButtons();

    //实现 stacked widget的page页切换
    void selectPanel(Panel type);

private:
    Ui::ButtonGroup *ui;
signals:
    void startGame();
    void playHand();
    void pass();
    void betPoint(int bet);//抢地主分数
};

#endif // BUTTONGROUP_H
