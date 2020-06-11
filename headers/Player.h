#ifndef PLAYER_H
#define PLAYER_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QGraphicsItem>
#include <QtCore>
#include <QtDebug>
#include <vector>
#include "logs.h"
#include "customscenes.h"

class Player
{
public:
    Player();
    Player(BattleScene* battle_scene, LootScene* loot_scene, bool is_second = false);
    void makeTurn(TurnLog log);
private:
    std::vector <QGraphicsLineItem*> _walls;
    QGraphicsEllipseItem *_chip;
    BattleScene *_battle_scene;
    LootScene *_loot_scene;
    int _curr_wall;

    void moveChip(QRect);
    void setWall(std::pair <QPoint, QPoint>);
};

#endif // PLAYER_H
