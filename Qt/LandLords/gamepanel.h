#ifndef GAMEPANE_H
#define GAMEPANE_H

#include <QLabel>
#include <QMainWindow>
#include<QPixmap>
#include"gamecontrol.h"
#include"cardpanel.h"

namespace Ui {
class GamePane;
}

class GamePane : public QMainWindow
{
    Q_OBJECT

public:
    explicit GamePane(QWidget *parent = 0);
    ~GamePane();
    //初始化游戏控制类
    void GameControlInit();

    //更新分数面板的分数
    void updatePlayerScore();

    //切割并存储扑克牌
    void initCardMap();

    //裁剪图片
    void copyImage(QPixmap& pix,int x,int y,Card& c);

    //初始化按钮
    void initButtonGroup();

    //初始化玩家上下文
    void initPlayerContext();

private:
    Ui::GamePane *ui;
    QPixmap m_bkImage;
    GameControl* m_gameCtl;
    QVector<Player*> m_playerList;
    QMap<Card,CardPanel*> m_cardMap;
    QSize m_cardSize;
    QPixmap m_cardBackImg;
    enum CardAlign{Horizontal,Vertical};
    struct PlayerContext{
        //1. 玩家扑克牌显示区域
        QRect cardRect;
        //2.出牌区域
        QRect playHandRect;
        //3.扑克牌对齐方式
        CardAlign align;
        //4.扑克牌显示正面还是反面
        bool isFrontSide;
        //5.游戏过程提示信息
        QLabel* info;
        //6.玩家头像
        QLabel* roleImg;
        //7.玩家刚打出的牌
        Cards lastCards;
    };
    QMap<Player*,PlayerContext> m_contextMap;
protected:
    void paintEvent(QPaintEvent* ev);
};

#endif // GAMEPANE_H
