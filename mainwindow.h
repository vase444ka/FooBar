#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QGraphicsItem>
#include <QtCore>
#include <QtDebug>
#include <vector>
#include "turn.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(std::vector <turn> &t, QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void makeTurn();
    void timerOn();
    void timerOff();

private:
    Ui::MainWindow *ui;
    QTimer *timer;

    QGraphicsScene *fieldScene;
    int currentTurn;
    std::vector <turn> turns;
    const int margin;
    static const int cellCount = 9, wallsCount = 10, cellSize = 50;
    QRect field[cellCount][cellCount];

    QGraphicsScene *p1Scene, *p2Scene;
    QGraphicsLineItem *p1Walls[wallsCount], *p2Walls[wallsCount];
    QGraphicsEllipseItem *player1, *player2;
    int p1CurrWall, p2CurrWall;
};
#endif // MAINWINDOW_H
