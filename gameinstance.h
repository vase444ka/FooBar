#ifndef GAMEINSTANCE_H
#define GAMEINSTANCE_H

#include <iostream>
#include <QPoint>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QtCore>
#include <QtDebug>
#include "logs.h"
#include "Player.h"

class GameInstance
{
public:
    GameInstance(GameLog, BattleScene*, LootScene*, LootScene*);
public slots:
    bool makeTurn(); //true if game goes on
    void timerOn();
    void timerOff();
private:
    GameLog _log;
    int _curr_turn;
    std::pair <Player, Player> _players;
    QTimer *_timer;
};
#endif // GAMEINSTANCE_H
