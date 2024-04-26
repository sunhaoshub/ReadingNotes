#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include"card.h"
#include"cards.h"

class Player : public QObject
{
    Q_OBJECT
public:
    explicit Player(QObject *parent = nullptr);
    explicit Player(QString name,QObject *parent = nullptr);

    enum Role{Lord,Farmer};
    enum Sex{Man,Woman};
    enum Direction{Left,Right};//头像方位
    enum Type{Robot,UsermUnknown};

    //名字
    void setName(QString name);
    QString getNmae();

    //角色
    void setRole(Role role);
    Role getRole();

    //性别
    void setSex(Sex sex);
    Sex getSex();

    //头像方向
    void setDirection(Direction direction);
    Direction getDirection();

    //玩家类型
    void setType(Type type);
    Type getType();

    //分数
    void setScore(int socre);
    int getScore();

    void setWin(bool flag);
    bool getWin();

    //设置当前玩家的上家/下家
    void setPrevPlayer(Player* prev);
    void setNextPlayer(Player* next);

    Player* getPrevPlayer();
    Player* getNextPlayer();

    //叫地主/抢地主
    void grabLordBet(int point);

    //存储发出的牌
    void storeDispatchCard(Card& card);
    void storeDispatchCard(Cards& cards);

    //获取玩家手里的牌
    Cards getCards();

    //清空玩家手里的牌
    void clearCards();

    //出牌后清空手里对应的牌
    void playHand(Cards& cards);

    //设置和获取出牌信息
    void setPendingInfo(Cards pendCards,Player* pendPlayer);
    Cards getPendCards();
    Player* getPendPlayer();

    //虚函数
    virtual void prepareLord();
    virtual void preparePlayHand();
signals:

public slots:

protected:
    QString m_name;
    Role m_role;
    Sex m_sex;
    Direction m_direction;
    Type m_type;
    int m_score;
    bool m_flag;
    Player* m_prev;
    Player* m_next;
    Cards m_cards;
    Cards m_pendCards;//记录打出去的牌
    Player* m_pendPlayer;//记录打出牌的玩家
};

#endif // PLAYER_H
