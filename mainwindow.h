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

private:
    Ui::MainWindow *ui;
    QGraphicsView *fieldView, *player1View, *player2View;
    QTimer *timer;
    QGraphicsScene *fieldScene, *p1Scene, *p2Scene;
    const int margin;
    static const int cellCount = 9, wallsCount = 10, cellSize = 50;

    QRect field[cellCount][cellCount];
    QGraphicsLineItem *p1Walls[wallsCount], *p2Walls[wallsCount];

    int currentTurn, p1CurrWall, p2CurrWall;
    std::vector <turn> turns;
    QGraphicsEllipseItem *player1, *player2;
};
#endif // MAINWINDOW_H
