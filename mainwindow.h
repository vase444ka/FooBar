#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QtCore>
#include <QtDebug>
#include "customscenes.h"
#include "gameinstance.h"
#include "logs.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(GameLog passed_log, QWidget *parent = nullptr);
    ~MainWindow();
    void setGameInstance(GameLog g_log);

private:
    Ui::MainWindow *ui;
    BattleScene *_field_scene;
    LootScene *_p1_scene, *_p2_scene;
    GameInstance _curr_game;
};
#endif // MAINWINDOW_H
