#include "mainwindow.h"

#include <QApplication>
#include <vector>
#include "gameinstance.h"
#include "logs.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);//todo parsers
    GameLog log;
    if (argc>=2)
    //log.parse(argv[1]);
    log.parse("log.txt");
    MainWindow w(log);
    w.show();
    return a.exec();
}
