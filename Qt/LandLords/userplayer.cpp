#include "userplayer.h"
#include<QDebug>

UserPlayer::UserPlayer(QObject *parent):Player(parent)
{
    m_type = Player::User;
}

void UserPlayer::prepareLord()
{
    qDebug()<<"hello,world";
}

void UserPlayer::preparePlayHand()
{
    qDebug()<<"Hello,World";
}
