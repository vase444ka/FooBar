#include "gameinstance.h"

void GameInstance::timerOn(){
    _timer->start(500);
}

void GameInstance::timerOff(){
    _timer->stop();
    makeTurn();
}

GameInstance::GameInstance(GameLog game_log, BattleScene* battle, LootScene* p1, LootScene* p2)
    :_log(game_log)
    ,_curr_turn(0)
    ,_players({Player(battle, p1), Player(battle, p2, 1)})
{

}

void GameInstance::connectControls(QPushButton *timer, QPushButton *click)
{
    _timer = new QTimer(this);
    if (_log.getSize()){
         QObject::connect(click, SIGNAL(clicked()), this, SLOT(timerOff()));
         QObject::connect(timer, SIGNAL(clicked()), this, SLOT(timerOn()));
         QObject::connect(_timer, SIGNAL(timeout()), this, SLOT(makeTurn()));
    }
}

bool GameInstance::makeTurn(){
    if(_curr_turn >= _log.getSize()){
        return false;
    }
    if ((_curr_turn&1) == 0){
        _players.first.makeTurn(_log.getTurn(_curr_turn));
    }
    else
        _players.second.makeTurn(_log.getTurn(_curr_turn));
    _curr_turn++;
    return true;
}
