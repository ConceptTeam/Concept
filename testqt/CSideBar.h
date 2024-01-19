#include <QWidget>
#include <QLayout>
#include <QVBoxLayout>
#include <QString>
#include <QLabel>
#include "Colors.h"

class CSideBarItem: public QWidget{
Q_OBJECT
public:
	CSideBarItem(QWidget* parent=nullptr);
	void setIconURL(QString);
	void setColor(Colors);
	QLabel* tooltip;

private:
	QString	iconURL; //maybe change if needed
	Colors color;

};


class CSideBar: public QWidget{
Q_OBJECT
public:	
	CSideBar(QWidget *parent = nullptr);

private:
	Colors color;
	QVBoxLayout *layout;
};




