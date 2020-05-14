#ifndef MOVE_H
#define MOVE_H

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <QPoint>


class turn
{
    int xPlayer, yPlayer;//(1,1)-(9,9)
    QPoint beginWall, endWall; //(0,0)-(9,9)
public:

    turn();
    ~turn();

    friend std::ifstream& operator>> (std::ifstream& in, turn &a);
    friend class MainWindow;

    friend void readTurns(std::vector <turn> &t, int argc, char *argv[]);
};

void readTurns(std::vector <turn> &t, int argc, char *argv[]);

#endif // MOVE_H
