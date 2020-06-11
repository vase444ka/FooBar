#include "../headers/customscenes.h"

BattleScene::BattleScene(){
    setSceneRect(0, 0, _cell_size*_cell_n, _cell_size*_cell_n);
    QPen blackPen(Qt::black);
    for (int i = 0; i < _cell_n; i++)
        for (int j = 0; j < _cell_n; j++){
            field[i][j].setRect(j*_cell_size, i*_cell_size, _cell_size, _cell_size);
            addRect(field[i][j], blackPen);
        }
}

QRect BattleScene::getCell(int x, int y){
    return field[x][y];
}

LootScene::LootScene(){
    setSceneRect(0, 0, _cell_size*_cell_n, _cell_size*2);
}

int QuorridorScene::getCellN()
{
    return _cell_n;
}

int QuorridorScene::getWallN()
{
    return _wall_n;
}

int QuorridorScene::getCellSize()
{
    return _cell_size;
}
