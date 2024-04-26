#ifndef ROBOT_H
#define ROBOT_H

#include <QObject>
#include"player.h"

class Robot : public Player
{
    Q_OBJECT
public:
    using Player::Player;
    explicit Robot(QObject *parent = nullptr);
    void prepareLord() override;
    void preparePlayHand() override;
signals:

public slots:
};

#endif // ROBOT_H
