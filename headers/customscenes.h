#ifndef CUSTOMSCENES_H
#define CUSTOMSCENES_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QGraphicsItem>
#include <QtCore>
#include <QtDebug>
#include <vector>


class QuorridorScene: public QGraphicsScene
{
public:
    QuorridorScene(){};
    static int getCellN();
    static int getWallN();
    static int getCellSize();
protected:
    static const int _cell_n = 9, _wall_n = 10, _cell_size = 50, _margin = 1;
};

class BattleScene: public QuorridorScene
{
public:
    BattleScene();
    QRect getCell(int, int);
private:
    QRect field[_cell_n][_cell_n];
};

class LootScene: public QuorridorScene
{
public:
    LootScene();
private:
};

#endif // CUSTOMSCENES_H
