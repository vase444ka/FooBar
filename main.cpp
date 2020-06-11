#include "mainwindow.h"

#include <QApplication>
#include <vector>
#include "gameinstance.h"
#include "logs.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);//todo parsers
    MainWindow w(GameLog(std::vector<TurnLog>{TurnLog(0, 4), TurnLog(8,4), TurnLog(1, 5), TurnLog(7, 3)}, "", ""));//-1 in turnlogs
    w.show();
    return a.exec();
}
