#ifndef CARDS_H
#define CARDS_H

#include<QSet>//底层用哈希表实现，纯C++set用红黑树实现
#include"card.h"
class Cards
{
public:
    enum SortType{
        Asc,Desc,NoSort
    };
    Cards();

    //添加卡牌
    void add(const Card& card);
    void add(const Cards& cards);

    //重载<<运算符，使得能够一次插入多张卡牌
    Cards& operator << (const Card& card);
    Cards& operator << (const Cards& cards);

    //删除卡牌
    void remove(Card& card);
    void remove(Cards& cards);

    //获取卡牌数量
    int cardCount();

    //判断是否为空
    bool isEmpty();

    //清空卡牌
    void clear();

    //最大点数
    Card::CardPoint maxPoint();

    //最小点数
    Card::CardPoint minPoint();

    //指定点数牌的数量
    int pointCount(Card::CardPoint point);

    //是否包含某一/几张牌
    bool contains(const Card& card);
    bool contains(const Cards& cards);

    //随机取一张牌 模拟洗牌
    Card takeRandCard();

    //将扑克牌排序
    CardList toCardList(SortType type);
private:
    QSet<Card> m_cards;
};

#endif // CARDS_H
