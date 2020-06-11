#include "Player.h"

Player::Player(BattleScene* battle_scene, LootScene* loot_scene, bool is_second)
    :_battle_scene(battle_scene)
    ,_loot_scene(loot_scene)
    ,_curr_wall(0)
{
    if (!battle_scene || !loot_scene)
        return;

    QBrush red_brush(Qt::red);
    QBrush green_brush(Qt::green);
    QPen black_pen(Qt::black);
    QPen blue_pen(Qt::blue);

    if (is_second)
        _chip = _battle_scene->addEllipse
                (_battle_scene->getCell(_battle_scene->getCellN() - 1, battle_scene->getCellN()/2), black_pen, red_brush);
    else
        _chip = _battle_scene->addEllipse
                (_battle_scene->getCell(0, _battle_scene->getCellN()/2), black_pen, green_brush);
    blue_pen.setWidth(6);

    for (int i = 0, x = 0; i < battle_scene->getWallN(); i++, x+=battle_scene->getCellSize()){
        _walls.push_back(_loot_scene->addLine(x, 0, x, _loot_scene->height(), blue_pen));
    }

}


void Player::moveChip(QRect rect){
    _chip->setRect(rect);
}

void Player::setWall(std::pair <QPoint, QPoint> coord){
    if (_curr_wall < _loot_scene->getWallN()){
        QPen blue_pen(Qt::blue);
        blue_pen.setWidth(6);
        int size = _battle_scene->getCellSize();
        _walls[_curr_wall]->setLine(coord.first.x()*size, coord.first.y()*size,
                                    coord.second.x()*size, coord.second.y()*size);
        _battle_scene->addItem(_walls[_curr_wall]);
        _curr_wall++;
    }
}

void Player::makeTurn(TurnLog log){
    moveChip(_battle_scene->getCell( log.getChipY(), log.getChipX()));
    if (log.getWall()){
        setWall(log.getWall().value());
    }
}
