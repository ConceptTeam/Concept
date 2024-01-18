#ifndef DATECELL_HPP
#define DATECELL_HPP

#include <QWidget>
#include <QLabel>

class DateCell : public QWidget {
    Q_OBJECT

public:
    DateCell(int day, QWidget *parent = nullptr);

signals:
    void clicked(int day);

protected:
    void mousePressEvent(QMouseEvent *event) override;

private slots:
    void cellClicked();

private:
    QLabel *dateLabel;
    int day;
};

#endif // DATECELL_HPP

