#include "mainwindow.h"

#include <QApplication>
#include <vector>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //readTurns(t, argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
