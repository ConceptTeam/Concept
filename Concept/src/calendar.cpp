//calendar.cpp
#include "../includes/calendar.h"
#include <QVBoxLayout>
#include <QDate>
#include <QTextCharFormat>
#include <QMainWindow>
#include <QList>
Calendar::Calendar(QWidget *parent) : QMainWindow(parent)
{
    calendarWidget = new QCalendarWidget(this);
    eventLineEdit = new QLineEdit(this);
    addButton = new QPushButton("Add Event", this);
    eventDisplay = new QTextBrowser(this);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(calendarWidget);
    layout->addWidget(eventLineEdit);
    layout->addWidget(addButton);
    layout->addWidget(eventDisplay);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    connect(addButton, SIGNAL(clicked()), this, SLOT(addEvent()));

    setWindowTitle("Event Calendar");

    connect(this, SIGNAL(destroyed(QObject*)), this, SLOT(closeCalendar()));

    setGeometry(50, 100, 200, 300);

    this->initializeEvents();
}

void Calendar::addEvent()
{
    QDate selectedDate = calendarWidget->selectedDate();
    QString eventText = eventLineEdit->text();

    if (!eventText.isEmpty())
    {
        QString currentText = eventDisplay->toPlainText();
        currentText += QString("%1: %2\n").arg(selectedDate.toString("yyyy-MM-dd")).arg(eventText);
        eventDisplay->setText(currentText);
    }

    eventLineEdit->clear();
}

void Calendar::initializeEvents(){
    QList<calendarEvents> e;
    QSqlError fetchError = qx::dao::fetch_all(e);
    QString textToAdd = QString("");
    if(fetchError.is_valid()){
    	for(const calendarEvents& event : e){
		textToAdd += QString("%1: %2\n").arg(event.date.toString("yyyy-MM-dd")).arg(event.eventName);
    	} 
    eventDisplay->setText(textToAdd);	

}
}
CalendarQML::CalendarQML(QObject *parent) : QObject(parent)
{
    this->myCalendar = new Calendar();
}

void CalendarQML::showCalendar()
{
    myCalendar->show();
}

void Calendar::closeCalendar() {
    emit calendarClosed();
}

void CalendarQML::closeCalendarFromQML() {
    myCalendar->close();  // Close the calendar window
}

void Calendar::closeCalendarFromButton() {
    close();  // Close the calendar window
}
