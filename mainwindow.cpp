#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPushButton>
#include "grid.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->resize(700, 800);
    this->setWindowTitle(tr("ШАХМАТЫ ХУЛЕ"));
    QGridLayout *grid = new QGridLayout(ui->centralwidget);
    grid->setSizeConstraint(QLayout::SetFixedSize);
    //grid->setGeometry(QRect(0,0,500,500));

    QPalette *green = new QPalette();
    green->setColor(QPalette::Background, Qt::green);

    QPalette *red = new QPalette();
    red->setColor(QPalette::Background, Qt::red);
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
        {
            QPushButton *w = new QPushButton();
            //w->setFlat(true);
            w->setFixedSize(70, 70);
            //w->setAutoFillBackground(true);
            if ((i+j)%2)
                w->setStyleSheet(tr("background-color: red;"));
            else
                w->setStyleSheet(tr("background-color: green;"));

            //w->setAutoDefault(true);
            //w->setDefault(true);

            grid->addWidget(w, i, j);
        }





}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clikkk(bool checked)
{
    QPushButton *nb = new QPushButton(this->ui->centralwidget);
    nb->setText(tr("one more button"));
    nb->move(rand()%600, rand()%600);
    connect(nb, SIGNAL(clicked(bool)), this, SLOT(clikkk(bool)));
    nb->show();
}
