#include "mainwindow.h"
#include <QApplication>
#include <ctime>
int main(int argc, char *argv[])
{
    srand(time(nullptr));
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(1120,455);
    w.show();
    return a.exec();
}
