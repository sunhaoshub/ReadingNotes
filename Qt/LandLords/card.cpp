#include "card.h"


Card::Card()
{

}

Card::Card(CardPoint point1, CardSuit suit1)
{
    setPoint(point1);
    setSuit(suit1);
}

void Card::setPoint(Card::CardPoint point)
{
    m_point = point;
}

void Card::setSuit(Card::CardSuit suit)
{
    m_suit = suit;
}

Card::CardSuit Card::suit() const
{
    return m_suit;
}

Card::CardPoint Card::point() const
{
    return m_point;
}

bool lessSort(const Card &A, const Card &B)
{
    if(A.point() == B.point())
    {
        return A.suit()<B.suit();
    }
    else
    {
        return A.point()<B.point();
    }
}

bool greaterSort(const Card &A, const Card &B)
{
    if(A.point() == B.point())
    {
        return A.suit()>B.suit();
    }
    else
    {
        return A.point()>B.point();
    }
}



bool operator ==(const Card &A, const Card &B)
{
    return(A.point()==B.point() &&A.suit()==B.suit());
}

uint qHash(const Card &card)
{
    return card.point()+card.suit();
}
