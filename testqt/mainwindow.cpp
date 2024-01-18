// mainwindow.cpp
#include "mainwindow.h"
#include <iostream>
#include "texteditor.hpp"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>
#include <QWidget>
#include <QLabel>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

// those are the columns in the main app; this might be subject to change

column1 = new QWidget(this);
column1->setStyleSheet("border: 1px solid black"); //will be changed

//

column2 = new QScrollArea(this);
column2->setStyleSheet("border: 1px solid black"); //will be changed

subrow1 = new QWidget(this);

EditButton = new QPushButton("Edit",subrow1);
ViewButton = new QPushButton("View",subrow1);
NewButton = new QPushButton("New",subrow1);
content = new QWidget(column2);

//

column3 = new QWidget(this);
column3->setStyleSheet("border: 1px solid black"); //will be changed
timerWidget = new Timer(column3);
timerWidget->addStyle();
timerWidget->show();
// 

//leftbar = new QWidget(this);
//leftbar->setStyleSheet("background-color: rgb(123,203,255)");

//

topbar = new QWidget(this);

topbar->setGeometry(-20,0,this->width(), 60);
topbar->setStyleSheet("background-color: rgb(123,203,255); border: 1px solid black;");
topbar->show();
QLabel *title = new QLabel("Concept",topbar);
title->setStyleSheet("padding: 5px; font-size: 35px;");

helpButton = new MainHelp(topbar);

helpButton->setStyleSheet("background-color: white ; padding: 5px; border: 1px solid black ;");
qDebug() << "topbar stylesheet: " << topbar->styleSheet();
qDebug() << "helpButton stylesheet: " << helpButton->styleSheet();
//QLabel *test = new QLabel("tesst", helpButton);
//test->setStyleSheet("font-size: 5px;");

helpButton->setGeometry(0.9*topbar->width(),0.2*topbar->height(),50,30 );
helpButton->show();


column2->setWidget(content);


//connect buttons:
	connect(NewButton,&QPushButton::clicked, this, &MainWindow::newTE);



}

MainWindow::~MainWindow()
{
	delete subrow1;
	delete NewButton;
	delete ViewButton;
	delete EditButton;
	delete column1;
	delete column2;
	delete column3;
//	delete leftbar;
	delete topbar;
	delete content;
	delete helpButton;
	delete timerWidget;
}



void MainWindow::resizeEvent(QResizeEvent *event){
	QMainWindow::resizeEvent(event);

	column1->setGeometry(0, 60,this->width()/4, this->height());
//
	topbar->setGeometry(0,0,this->width(), 60);
	column2->setGeometry(this->width()*0.25, 110,this->width()/2, this->height());
	subrow1->setGeometry(this->width()*0.25,60,this->width()/2, 50);
	NewButton->setGeometry(0.9*subrow1->width(),5,0.1*subrow1->width(),40);
	EditButton->setGeometry(0.75*subrow1->width(),5,0.1*subrow1->width(),40);
	ViewButton->setGeometry(0.60*subrow1->width(),5,0.1*subrow1->width(),40);
	content->setGeometry(0,0,column2->width(),400*numberofTE);
	helpButton->setGeometry(0.8*topbar->width(),0.3*topbar->height(),50,30 );

for(int i = 0; i != numberofTE; i++){
		TElist[i]->setGeometry(0,400*i, column2->width()*0.98,400);
}
//	

	column3->setGeometry(this->width()*0.75, 60,this->width()/4, this->height());
	timerWidget->setGeometry(0,0,column3->width(),700);

qDebug() << topbar->isVisible();
qDebug() << helpButton->isVisible();


}

void MainWindow::ChangeView(){ //will be added to create a dark mode
}


void MainWindow::newTE(){
  TextEditor* newTE = new TextEditor(content);
  newTE->setId(numberofTE);
  newTE->setMain(this->parent);
  TElist.push_back(newTE);
  newTE->setGeometry(0,400*numberofTE, column2->width()*0.98,400);
  numberofTE++;
  content->setGeometry(0,0,column2->width(),400*numberofTE);
  newTE->show();
}


void MainWindow::removeTE(int id){

//define the trigger -> trigger activated, then:

std::vector<TextEditor*> m;
delete TElist[id];
for(int i = 0; i < numberofTE;++i){
	if(i != id){
		m.push_back(TElist[i]);
	}
}
for(int i = 0; i < m.size();++i){
m[i]->setId(i);
}

TElist = m;
numberofTE--;
qDebug() << TElist.capacity() << " " << TElist.size() << "\n"; 
for(int i = 0; i != numberofTE; i++){
		TElist[i]->setGeometry(0,400*i, column2->width()*0.98,400);
}
}
