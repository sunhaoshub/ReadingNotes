#ifndef USERPLAYER_H
#define USERPLAYER_H

#include <QObject>
#include"player.h"

class UserPlayer : public Player
{
public:
    using Player::Player;
    UserPlayer();
    void prepareLord() override;
    void preparePlayHand() override;
};

#endif // USERPLAYER_H
