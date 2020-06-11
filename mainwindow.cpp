#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customscenes.h"

MainWindow::MainWindow(GameLog passed_log, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,_field_scene(new BattleScene)
    ,_p1_scene(new LootScene)
    ,_p2_scene(new LootScene)
    ,_curr_game(GameInstance(passed_log, _field_scene, _p1_scene, _p2_scene))
{
    ui->setupUi(this);

    ui->fieldView->scale(1, -1);

    ui->fieldView->setScene(_field_scene);
    ui->player1View->setScene(_p1_scene);
    ui->player2View->setScene(_p2_scene);//TODO OVERLAP

    _curr_game.connectControls(ui->turnButton, ui->timerButton);
}

MainWindow::~MainWindow()
{
    delete ui;
}

