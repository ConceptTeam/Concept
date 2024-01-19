#ifndef POMODORO
#define POMODORO


#include <QObject>
#include <QWidget>
#include <QString>
#include <QPushButton>
#include "setFocusPeriod.h"

class pomodoro : public QWidget{
	

	


	
	private:
	SetFocusItem focusItem = new SetFocusItem(this); 
	
};



#endif 

