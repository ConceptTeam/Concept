// main.cpp
#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include "mainhelp.h"
#include <QTimer>
#include "Calendar.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Calendar* x = new Calendar();
    x->show();
    return a.exec();
}
