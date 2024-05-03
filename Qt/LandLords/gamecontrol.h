#ifndef GAMECONTROL_H
#define GAMECONTROL_H

#include <QObject>
#include"robot.h"
#include"userplayer.h"
#include"cards.h"
#include"card.h"

class GameControl : public QObject
{
    Q_OBJECT
public:
    explicit GameControl(QObject *parent = nullptr);
    //游戏状态
    enum GameStatus{
        Dispatched,//发牌状态
        CallingLord,//叫地主状态
        PlayingHand//出牌状态
    };
    //玩家状态
    enum PlayerStatus{
        ThinkingForCallLord,
        ThinkingForPlayHand,
        Winning
    };

    //初始化玩家
    void playerInit();

    //获取玩家实例
    Robot* getLeftRobot();
    Robot* getRightRobot();
    UserPlayer* getUserPlayer();

    //设置和获取当前玩家实例
    void setCurrentPlayer(Player* currPlayer);
    Player* getCurrentPlayer();

    //获取出牌类玩家和牌
   Player* getPendPlayer();
   Cards getPendCards();

    //初始化卡牌
   void InitAllCards();

   //每次发一张牌
   Card takeOneCard();

   //得到最后的三张底牌
   Cards getSurplusCard();

   //重置扑克牌对象
   void resetCardData();

   //准备叫地主
   void startLordCard();

   //处理叫地主

   //成为地主
   void becomeLord(Player* player);

   //处理出牌

   //清空所有玩家的分数
   void clearPlayerSocre();
signals:

public slots:

private:
    Robot* m_RobotLeft;
    Robot* m_RobotRight;
    UserPlayer* m_user;
    Player* m_currPlayer;
    Player* m_pendPlayer;
    Cards m_pendCards;
    Cards m_allCards;
};

#endif // GAMECONTROL_H
