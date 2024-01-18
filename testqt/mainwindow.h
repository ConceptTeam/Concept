// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "texteditor.hpp"
#include "mainhelp.h"
#include "timer.h"
#include <QPushButton>
#include <iostream>
#include <QDockWidget>
#include <QWidget>
#include <QAction>
#include <QScrollArea>
#include <vector>

class TextEditor;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setptr(MainWindow* w){this->parent = w;}

private: //storing main widgets


MainWindow* parent;

QWidget *topbar; //objects in the top bar:

MainHelp *helpButton;

//

QWidget *column1; //Objects from column1:

//

QScrollArea *column2; //Objects from column2:

QWidget *subrow1;
QWidget *content;
QPushButton *NewButton;
QPushButton *ViewButton;
QPushButton *EditButton;

//

QWidget *column3; //Objects from column3:

Timer *timerWidget;

//

QWidget *leftbar;
int numberofTE{0};
std::vector<TextEditor*> TElist;

public slots:
void removeTE(int id);
void ChangeView();
void newTE(); //to create a new text editor and append it to the second column.

protected:
void resizeEvent(QResizeEvent *event) override;

};

#endif // MAINWINDOW_H
