#include "DateCell.hpp"
#include <QVBoxLayout>
#include <QMouseEvent>

DateCell::DateCell(int day, QWidget *parent) : QWidget(parent), day(day) {
    dateLabel = new QLabel(QString::number(day));
    dateLabel->setAlignment(Qt::AlignCenter);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(dateLabel);

    connect(this, &DateCell::clicked, this, &DateCell::cellClicked);
}

void DateCell::cellClicked() {
    emit clicked(day);
}

void DateCell::mousePressEvent(QMouseEvent *event) {
    Q_UNUSED(event);
    cellClicked();  // Call the slot directly
}

