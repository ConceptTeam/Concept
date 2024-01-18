// mainhelp.h
#ifndef MAINHELP_H
#define MAINHELP_H

#include <QWidget>
#include <QMenu>
#include <QObject>
#include <QLabel>
class MainHelp : public QWidget {
    Q_OBJECT

public:
    MainHelp(QWidget *parent = nullptr);
    ~MainHelp();

public slots:
    void showHelpMenu();

private:
    QMenu helpMenu;	
    //QLabel *label = new QLabel("help",this);
private slots:
    void handleHelpAction1();
    void handleHelpAction2();
    void handleHelpAction3();
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
};

#endif // MAINHELP_H
