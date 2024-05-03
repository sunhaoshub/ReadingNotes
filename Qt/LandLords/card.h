#ifndef CARD_H
#define CARD_H

#include<QVector>

//卡牌数据类
class Card
{
public:


    //花色
    enum CardSuit
    {
        Suit_Begin,
        Diamond,
        Heart,
        Spade,
        Club,
        Suit_End
    };
    //点数
    enum CardPoint
    {
        Point_Begin,
        Card_3,
        Card_4,
        Card_5,
        Card_6,
        Card_7,
        Card_8,
        Card_9,
        Card_10,
        Card_J,
        Card_Q,
        Card_K,
        Card_A,
        Card_2,
        Card_SJ,
        Card_BJ,
        Point_End
    };
    Card();
    Card(CardPoint point1,CardSuit suit1);
    void setPoint(CardPoint point);
    void setSuit(CardSuit suit);
    CardSuit suit() const;
    CardPoint point() const;

    //std::sort比较函数

private:
    CardSuit m_suit;
    CardPoint m_point;
};

//定义别名
using CardList = QVector<Card>;

bool lessSort(const Card& A,const Card& B);
bool greaterSort(const Card& A,const Card& B);

//操作符重载
bool operator ==(const Card&A,const Card& B);
//重写qHash
uint qHash(const Card& card);
#endif // CARD_H
