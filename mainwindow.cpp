#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->addText("Shit!");
    scene->setBackgroundBrush(Qt::yellow);
    QGraphicsView *shit = new QGraphicsView(scene, ui->centralwidget);
    shit->setFixedSize(500, 500);
    shit->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

