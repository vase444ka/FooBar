#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::makeTurn(){
    if (currentTurn >= turns.size()) return;
    turn t = turns[currentTurn];
    if (currentTurn&1)
    {
        if (t.xPlayer>=0)
            player2->setRect(field[t.yPlayer][t.xPlayer]);
        if (t.beginWall.x()>=0){
            p2Walls[p2CurrWall]->setLine
                    (t.beginWall.x()*cellSize, t.beginWall.y()*cellSize,
                     t.endWall.x()*cellSize, t.endWall.y()*cellSize);
            fieldScene->addItem(p2Walls[p2CurrWall]);
            p2CurrWall--;
        }
    }
    if (!(currentTurn&1))
    {
        if (t.xPlayer>=0)
            player1->setRect(field[t.yPlayer][t.xPlayer]);
        if (t.beginWall.x()>=0){
            p1Walls[p1CurrWall]->setLine
                    (t.beginWall.x()*cellSize, t.beginWall.y()*cellSize,
                     t.endWall.x()*cellSize, t.endWall.y()*cellSize);
            fieldScene->addItem(p1Walls[p1CurrWall]);
            p1CurrWall--;
        }
    }
    currentTurn++;
}

void MainWindow::timerOn(){
    timer->start(500);
}

void MainWindow::timerOff(){
    timer->stop();
    makeTurn();
}

MainWindow::MainWindow(std::vector <turn> &t, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , margin(1)
{
    ui->setupUi(this);
    ui->verticalLayout->setSpacing(0);
    currentTurn = 0;
    timer = new QTimer(this);
    turns = std::move(t);
    fieldScene = new QGraphicsScene;
    p1Scene = new QGraphicsScene;
    p2Scene = new QGraphicsScene;
    fieldView = ui->fieldView;
    player1View = ui->player1View;
    player2View = ui->player2View;

    fieldView->setFixedSize(cellSize*cellCount + margin*2, cellSize*cellCount + margin*2);
    fieldView->setScene(fieldScene);
    fieldScene->setSceneRect(0, 0, fieldView->width()-margin*2, fieldView->height()-margin*2);

    player1View->setFixedSize(cellSize*cellCount + margin*2, cellSize*2 + margin*2);
    player1View->setScene(p1Scene);
    p1Scene->setSceneRect(0, 0, player1View->width()-margin*2, player1View->height()-margin*2);

    player2View->setFixedSize(cellSize*cellCount + margin*2, cellSize*2 + margin*2);
    player2View->setScene(p2Scene);
    p2Scene->setSceneRect(0, 0, player2View->width()-margin*2, player2View->height()-margin*2);

    QPen blackPen(Qt::black);
    for (int i = 0; i < cellCount; i++)
        for (int j = 0; j < cellCount; j++){
            field[i][j].setRect(j*cellSize, i*cellSize, cellSize, cellSize);
            fieldScene->addRect(field[i][j], blackPen);
        }

    QBrush p1Brush(Qt::red);
    QBrush p2Brush(Qt::green);
    player1 = fieldScene->addEllipse
            (field[0][cellCount/2], blackPen, p1Brush);
    player2 = fieldScene->addEllipse
            (field[cellCount - 1][cellCount/2], blackPen, p2Brush);

    QPen bluePen(Qt::blue);
    bluePen.setWidth(6);
    int x = 0; p1CurrWall = p2CurrWall = wallsCount - 1;
    for (int i = 0; i < wallsCount; i++, x+=cellSize){
        p1Walls[i] = p1Scene->addLine(x, 0, x, p1Scene->height(), bluePen);
        p2Walls[i] = p2Scene->addLine(x, 0, x, p1Scene->height(), bluePen);
    }

    player1View->show();
    fieldView->show();
    player2View->show();

    if (turns.size()){
        QObject::connect(ui->turnButton, SIGNAL(clicked()), this, SLOT(timerOff()));
        QObject::connect(ui->timerButton, SIGNAL(clicked()), this, SLOT(timerOn()));
        QObject::connect(timer, SIGNAL(timeout()), this, SLOT(makeTurn()));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

