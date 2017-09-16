#include "mainwindow.h"
#include <QApplication>
#include"management.h"

int main(int argc, char *argv[])
{
    management me;
    me.readfile();
    cout<<"bug"<<endl;
    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    return a.exec();
}
