#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPushButton>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for(auto ch : ui->centralwidget->children())
    {
        qInfo() << ch->objectName();
        connect(ch, SIGNAL(clicked(bool)), this, SLOT(clikkk(bool)));
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
