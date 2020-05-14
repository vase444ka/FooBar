#include "mainwindow.h"
#include "turn.h"

#include <QApplication>
#include <vector>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::vector <turn> t;
    readTurns(t, argc, argv);
    MainWindow w(t);
    w.show();
    return a.exec();
}
