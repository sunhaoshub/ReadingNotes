#include "gamecontrol.h"
#include<QRandomGenerator>

GameControl::GameControl(QObject *parent) : QObject(parent)
{

}

void GameControl::playerInit()
{
     m_RobotLeft = new Robot("机器人A",this);
     m_RobotRight = new Robot("机器人A",this);
     m_user = new UserPlayer("我自己",this);

     //设置头像方位
     m_RobotLeft->setDirection(Player::Left);
     m_RobotRight->setDirection(Player::Right);
     m_user->setDirection(Player::Right);

     //设置性别;
     Player::Sex sex;
     sex = (Player::Sex)QRandomGenerator::global()->bounded(2);
     m_RobotLeft->setSex(sex);
     sex = (Player::Sex)QRandomGenerator::global()->bounded(2);
     m_RobotRight->setSex(sex);
     sex = (Player::Sex)QRandomGenerator::global()->bounded(2);
     m_user->setSex(sex);

     //出牌顺序 逆时针出牌
    //user
     m_user->setNextPlayer(m_RobotRight);
     m_user->setPrevPlayer(m_RobotLeft);

     //left
     m_RobotLeft->setNextPlayer(m_user);
     m_RobotLeft->setPrevPlayer(m_RobotRight);

     //right
     m_RobotRight->setNextPlayer(m_RobotLeft);
     m_RobotRight->setPrevPlayer(m_user);


     //指定当前玩家
     m_currPlayer = m_user;
}

Robot *GameControl::getLeftRobot()
{
    return m_RobotLeft;
}

Robot *GameControl::getRightRobot()
{
    return m_RobotRight;
}

UserPlayer *GameControl::getUserPlayer()
{
    return m_user;
}

void GameControl::setCurrentPlayer(Player *currPlayer)
{
    m_currPlayer = currPlayer;
}

Player *GameControl::getCurrentPlayer()
{
    return m_currPlayer;
}

Player *GameControl::getPendPlayer()
{
    return m_pendPlayer;
}

Cards GameControl::getPendCards()
{
    return m_pendCards;
}

void GameControl::InitAllCards()
{
    m_allCards.clear();
    for(int p = Card::Point_Begin+1;p < Card::Card_SJ;++p)
    {
        for(int s = Card::Suit_Begin+1;s < Card::Suit_End;++s)
            m_allCards.add(Card((Card::CardPoint)p,(Card::CardSuit)s));
    }
    m_allCards.add(Card(Card::Card_SJ,Card::Suit_Begin));
    m_allCards.add(Card(Card::Card_BJ,Card::Suit_Begin));
}

Card GameControl::takeOneCard()
{
    return m_allCards.takeRandCard();
}

Cards GameControl::getSurplusCard()
{
    return m_allCards;
}

void GameControl::resetCardData()
{
    InitAllCards();

    m_user->clearCards();
    m_RobotLeft->clearCards();
    m_RobotRight->clearCards();

    m_pendCards.clear();
    m_pendPlayer = nullptr;
}

void GameControl::startLordCard()
{
    m_currPlayer->prepareLord();
}

void GameControl::becomeLord(Player *player)
{
    player->setRole(Player::Lord);
    player->getPrevPlayer()->setRole(Player::Farmer);
    player->getNextPlayer()->setRole(Player::Farmer);

    m_currPlayer = player;
    player->storeDispatchCard(m_allCards);

    m_currPlayer->preparePlayHand();
}

void GameControl::clearPlayerSocre()
{
    m_user->setScore(0);
    m_RobotLeft->setScore(0);
    m_RobotRight->setScore(0);
}
