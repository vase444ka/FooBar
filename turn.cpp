#include "turn.h"

turn::turn()
{

}

turn::~turn(){}

std::ifstream& operator>> (std::ifstream& in, turn &a){
    std::string turnMode;
    in>> turnMode;
    if (turnMode[0] == 'm'){
        in >> a.yPlayer >> a.xPlayer;
        a.xPlayer--; a.yPlayer--;
        a.beginWall.setX(-1);
    }
    else{
        int x, y;
        in>>y>>x;
        a.beginWall.setX(x - 1);
        a.beginWall.setY(y - 1);
        in>>y>>x;
        a.endWall.setX(x - 1);
        a.endWall.setY(y - 1);
        a.xPlayer = a.yPlayer = -1;
    }
    return in;
}

void readTurns(std::vector <turn> &t, int argc, char *argv[]){
    if (argc == 1)
        return;
    std::ifstream in;
    std::vector <turn> buffer;
    turn tmp;

    t.clear();
    in.open(argv[1]);

    while(in>>tmp){
        t.push_back(tmp);
    }
    in.close();
}
