#include "mainwindow.h"
#include "globals.h"
#include <QApplication>

PlayerHealth initialPlayerHealth = {50};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.setFixedSize(801,623);
    return a.exec();
}
