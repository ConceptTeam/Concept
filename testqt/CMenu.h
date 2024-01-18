#include <QObject>
#include <iostream>
#include <QWidget>
#include <QMenu>
#include <QLabel>
#include <QString>
#include "Colors.h"


class Menu: public QMenu{
	Q_OBJECT
public:
	Menu(QWidget* parent);
//use addSection to add the names;
	void setColor(Colors color); // maybe create a enum object to store colors.
};
