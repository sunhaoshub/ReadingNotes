#include "cards.h"
#include<QRandomGenerator>

Cards::Cards()
{

}

void Cards::add(Card &card)
{
    m_cards.insert(card);
}

void Cards::add(Cards &cards)
{
    m_cards.unite(cards.m_cards);//取并集
}

Cards &Cards::operator <<(const Card &card)
{
    add(card);
    return *this;
}

Cards &Cards::operator <<(const Cards &cards)
{
    add(cards);
    return *this;
}

void Cards::remove(Card &card)
{
    m_cards.remove(card);
}

void Cards::remove(Cards &cards)
{
    m_cards.subtract(cards.m_cards);
}

int Cards::cardCount()
{
    return m_cards.size();
}

bool Cards::isEmpty()
{
    return m_cards.isEmpty();
}

void Cards::clear()
{
    m_cards.clear();
}

Card::CardPoint Cards::maxPoint()
{
    Card::CardPoint max = Card::Point_Begin;

    if(!m_cards.isEmpty())
    {
        for(auto it = m_cards.begin();i != m_cards.end();i++)
        {
            if(it->point() > max)
                max = it->point();
        }
    }

    return max;
}

Card::CardPoint Cards::minPoint()
{
    Card::CardPoint min = Card::Point_Begin;

    if(!m_cards.isEmpty())
    {
        for(auto it = m_cards.begin();i != m_cards.end();i++)
        {
            if(it->point() < min)
                max = it->point();
        }
    }

    return min;
}

Card::CardPoint Cards::pointCount(Card::CardPoint point)
{
    int count = 0;

    for(auto it = m_cards.begin();i != m_cards.end();i++)
    {
        if(it->point() == point)
           count++;
    }

    return count;
}

bool Cards::contains(const Card &card)
{
    return m_cards.contains(card);
}

bool Cards::contains(const Cards &cards)
{
    return m_cards.contains(cards.m_cards);
}

Card Cards::takeRandCard()
{
    int num = QRandomGenerator::global()->bounded(m_cards.size());
    QSet<Card>::const_iterator it = m_cards.constBegin();
    for(int i = 0;i < num;i++,it++);
    Card card = *it;
    m_cards.erase(it);

    return card;
}
