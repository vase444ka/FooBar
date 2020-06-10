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
   _timer = new QTimer();
    /*if (_log.getSize()){
        QObject::connect(ui->turnButton, SIGNAL(clicked()), this, SLOT(timerOff()));
        QObject::connect(ui->timerButton, SIGNAL(clicked()), this, SLOT(timerOn()));
        QObject::connect(_timer, SIGNAL(timeout()), this, SLOT(makeTurn()));
    }*/
}

bool GameInstance::makeTurn(){
    if(_curr_turn >= _log.getSize()){
        return false;
    }

    if ((_curr_turn&1) == 0)
        _players.first.makeTurn(_log.getTurn(_curr_turn));
    else
        _players.second.makeTurn(_log.getTurn(_curr_turn));

    return true;
}
