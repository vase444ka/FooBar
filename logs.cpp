#include "logs.h"

TurnLog::TurnLog(){

}

int TurnLog::getChipX() const
{
    return _x_chip;
}

int TurnLog::getChipY() const
{
    return _y_chip;
}

std::optional<std::pair<QPoint, QPoint>> TurnLog::getWall() const
{
    return _wall;
}

GameLog::GameLog(){

}

TurnLog GameLog::getTurn(int n){
    if (n < _turns.size()){
        return _turns[n];
    }
}

int GameLog::getSize(){
    return _turns.size();
}
