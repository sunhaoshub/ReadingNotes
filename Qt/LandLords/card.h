#ifndef CARD_H
#define CARD_H

//卡牌数据类
class Card
{
public:
    Card();
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

    void setPoint(CardPoint point);
    void setSuit(CardSuit suit);
    CardSuit suit();
    CardPoint point();
private:
    CardSuit m_suit;
    CardPoint m_point;
};

#endif // CARD_H
