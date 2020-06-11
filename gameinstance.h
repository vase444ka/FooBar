#ifndef GAMEINSTANCE_H
#define GAMEINSTANCE_H

#include <iostream>
#include <QPoint>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QtCore>
#include <QtDebug>
#include "QPushButton"
#include "logs.h"
#include "Player.h"

class GameInstance: public QObject
{
public:
    GameInstance();
    GameInstance(GameLog, BattleScene*, LootScene*, LootScene*);
    ~GameInstance(){};

    void connectControls(QPushButton* timer, QPushButton* click);
public slots:
    bool makeTurn();
    void timerOn();
    void timerOff();
private:
    Q_OBJECT
    GameLog _log;
    int _curr_turn;
    std::pair <Player, Player> _players;
    QTimer *_timer;
};
#endif // GAMEINSTANCE_H
