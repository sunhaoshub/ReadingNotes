#include "card.h"

Card::Card()
{

}

void Card::setPoint(Card::CardPoint point)
{
    m_point = point;
}

void Card::setSuit(Card::CardSuit suit)
{
    m_suit = suit;
}

Card::CardSuit Card::suit()
{
    return m_suit;
}

Card::CardPoint Card::point()
{
    return m_point;
}
