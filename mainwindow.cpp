#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(GameLog passed_log, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _field_scene = new BattleScene;
    _p1_scene = new LootScene;
    _p2_scene = new LootScene;
    ui->fieldView->scale(1, -1);

    ui->fieldView->setScene(_field_scene);
    ui->player1View->setScene(_p1_scene);
    ui->player2View->setScene(_p2_scene);//TODO OVERLAP

    setGameInstance(passed_log);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::setGameInstance(GameLog g_log){
    _curr_game = GameInstance(g_log, _field_scene, _p1_scene, _p2_scene);
}
