#include "player.h"

Player::Player(QObject *parent) : QObject(parent)
{

}

Player::Player(QString name, QObject *parent):m_name(name)
{

}

void Player::setName(QString name)
{
    m_name = name;
}

QString Player::getNmae()
{
    return m_name;
}

void Player::setRole(Player::Role role)
{
    m_role = role;
}

Player::Role Player::getRole()
{
    return m_role;
}

void Player::setSex(Player::Sex sex)
{
    m_sex = sex;
}

Player::Sex Player::getSex()
{
    return m_sex;
}

void Player::setDirection(Player::Direction direction)
{
    m_direction = direction;
}

Player::Direction Player::getDirection()
{
    return m_direction;
}

void Player::setType(Player::Type type)
{
    m_type = type;
}

Player::Type Player::getType()
{
    return m_type;
}

void Player::setScore(int socre)
{
    m_score = socre;
}

int Player::getScore()
{
    return m_score;
}

void Player::setWin(bool flag)
{
    m_flag = flag;
}

bool Player::getWin()
{
    return m_flag;
}

void Player::setPrevPlayer(Player *prev)
{
    m_prev = prev;
}

void Player::setNextPlayer(Player *next)
{
    m_next = next;
}

Player *Player::getPrevPlayer()
{
    return m_prev;
}

Player *Player::getNextPlayer()
{
    return m_next;
}

void Player::grabLordBet(int point)
{

}

void Player::storeDispatchCard(Card &card)
{
    m_cards.add(card);
}

void Player::storeDispatchCard(Cards &cards)
{
    m_cards.add(cards);
}

Cards Player::getCards()
{
    return m_cards;
}

void Player::clearCards()
{
    m_cards.clear();
}

void Player::playHand(Cards &cards)
{
    m_cards.remove(cards);
}

void Player::setPendingInfo(Cards pendCards, Player *pendPlayer)
{
    m_pendCards = pendCards;
    m_pendPlayer = pendPlayer;
}

Cards Player::getPendCards()
{
    return m_pendCards;
}

Player *Player::getPendPlayer()
{
    return m_pendPlayer;
}

void Player::prepareLord()
{

}

void Player::preparePlayHand()
{

}
