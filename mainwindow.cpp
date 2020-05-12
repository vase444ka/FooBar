#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , cellSize(50)
    , cellCount(9)
    , margin(1)
    , wallsCount(10)
{
    ui->setupUi(this);
    ui->verticalLayout->setSpacing(0);
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
    QRect field[cellCount][cellCount];
    for (int i = 0; i < cellCount; i++)
        for (int j = 0; j < cellCount; j++){
            field[i][j].setRect(j*cellSize, i*cellSize, cellSize, cellSize);
            fieldScene->addRect(field[i][j], blackPen);
        }

    QBrush p1Brush(Qt::red);
    QBrush p2Brush(Qt::green);
    QGraphicsEllipseItem* player1 = fieldScene->addEllipse
            (field[0][cellCount/2], blackPen, p1Brush);
    player1->setFlag(QGraphicsItem::ItemIsMovable, true);
    QGraphicsEllipseItem* player2 = fieldScene->addEllipse
            (field[cellCount - 1][cellCount/2], blackPen, p2Brush);
    player2->setFlag(QGraphicsItem::ItemIsMovable, true);


    QPen bluePen(Qt::blue);
    bluePen.setWidth(6);
    QGraphicsLineItem *p1Walls[wallsCount], *p2Walls[wallsCount];
    int x = 0;
    for (int i = 0; i < wallsCount; i++, x+=cellSize){
        p1Walls[i] = p1Scene->addLine(x, 0, x, p1Scene->height(), bluePen);
        p2Walls[i] = p2Scene->addLine(x, 0, x, p1Scene->height(), bluePen);

        p1Walls[i]->setFlag(QGraphicsItem::ItemIsMovable, true);
        p2Walls[i]->setFlag(QGraphicsItem::ItemIsMovable, true);
    }

    player1View->show();
    fieldView->show();
    player2View->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

