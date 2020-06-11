#ifndef LOGS_H
#define LOGS_H

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <QPoint>
#include <QtCore>
#include <QtDebug>
#include <string>
#include <sstream>


class TurnLog
{
public:
    TurnLog();//TODO
    TurnLog(int, int, std::pair<QPoint, QPoint> = {{0,0},{0,0}}, bool is_wall = false);
    TurnLog(std::string, const TurnLog &prev = TurnLog(0,0));
    ~TurnLog(){}
    int getChipX() const;
    int getChipY() const;
    std::optional<std::pair <QPoint, QPoint>> getWall() const;
private:
    int _x_chip, _y_chip;//(1,1)-(9,9)
    std::optional<std::pair<QPoint, QPoint>> _wall; //(0,0)-(9,9)
};

class GameLog{
public:
    GameLog(){}
    GameLog(std::vector <TurnLog>, std::string, std::string);
    void parse(std::string filename);
    TurnLog getTurn(int);
    int getSize();
private:
    std::vector <TurnLog> _turns;
    std::pair<std::string, std::string> _team_names;
};

#endif // TURNLOG_H
