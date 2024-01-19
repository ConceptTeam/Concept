// main.cpp
#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include "mainhelp.h"
#include "CSideBar.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CSideBar* m = new CSideBar;
    m->show();
    return a.exec();
}
