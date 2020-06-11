#include "../headers/logs.h"

TurnLog::TurnLog(){

}

TurnLog::TurnLog(int chip_x, int chip_y, std::pair<QPoint, QPoint> wall_coords, bool is_wall)
{
    _x_chip = chip_x;
    _y_chip = chip_y;
    if (is_wall)
        _wall = wall_coords;
}

TurnLog::TurnLog(std::string inp, const TurnLog &prev)
{
    std::stringstream in;
    in<<inp;
    std::string turnMode;
    in >> turnMode;
        if (turnMode[0] == 'm'){
            in >> _y_chip>>_x_chip;
            _y_chip--; _x_chip--;
        }
        else{
            (*this) = prev;
            int y1, x1, y2, x2;
            in>>y1>>x1>>y2>>x2;
            _wall = {{x1-1, y1-1}, {x2-1, y2-1}};
        }
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

void GameLog::parse(std::string filename){
    _turns.clear();
    std::ifstream in;
    std::string buffer;
    in.open(filename);

    _turns.push_back(TurnLog(4, 0));
    _turns.push_back(TurnLog(4, 8));

    int i = 2;
    while(getline(in, buffer)){
        _turns.push_back(TurnLog(buffer, _turns[i-2]));
        i++;
    }
    in.close();
}

TurnLog GameLog::getTurn(int n){
    if (n < _turns.size()){
        return _turns[n];
    }
}

int GameLog::getSize(){
    return _turns.size();
}
