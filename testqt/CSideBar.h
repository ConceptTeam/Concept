#include <QWidget>
#include <QLayout>
#include <QVBoxLayout>
#include <QString>
#include <QLabel>
#include "Colors.h"

class MenuItem: QWidget{
Q_OBJECT
public:
	SideBarItem(QWidget* parent);
	void setIconURL(QString);
	void setColor(Colors);
	QLabel tooltip;

private:
	QString	iconURL; //maybe change if needed
	Colors color;

};


class CSideBar: public QWidget{
Q_OBJECT
public:	
	CMenuBar(QWidget *parent);

private:
	Colors color;
	layout *layout;
};




