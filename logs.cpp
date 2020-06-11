#include "logs.h"

TurnLog::TurnLog(){

}

TurnLog::TurnLog(int chip_x, int chip_y, std::pair<QPoint, QPoint> wall_coords, bool is_wall)
{
    _x_chip = chip_x;
    _y_chip = chip_y;
    if (is_wall)
        _wall = wall_coords;
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

GameLog::GameLog(std::vector<TurnLog> log, std::string name1, std::string name2){
    _turns = std::move(log);
    _team_names = {name1, name2};
}

TurnLog GameLog::getTurn(int n){
    if (n < _turns.size()){
        return _turns[n];
    }
}

int GameLog::getSize(){
    return _turns.size();
}
