#include "CSideBar.h"

CSideBarItem::CSideBarItem(QWidget* parent) : QWidget(parent){
this->setStyleSheet("color: blue"); //test display
}

void CSideBarItem::setIconURL(QString url ){ this->iconURL = url;}

void CSideBarItem::setColor(Colors color){this->color = color;}

CSideBar::CSideBar(QWidget* parent) : QWidget(parent){
//create the menu itens:
CSideBarItem* Calendar = new CSideBarItem(this);
CSideBarItem* Timer = new CSideBarItem(this);
CSideBarItem* Notebooks = new CSideBarItem(this);

//set the tooltips
Calendar->tooltip = new QLabel("Calendar");
Timer->tooltip = new QLabel("Timer");
Notebooks->tooltip = new QLabel("Notebooks");

//set layout:
layout = new QVBoxLayout(this);
layout->addWidget(Calendar);
layout->addWidget(Timer);
layout->addWidget(Notebooks);

}

