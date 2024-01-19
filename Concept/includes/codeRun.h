#ifndef CODERUN_H
#define CODERUN_H

#include <QQuickItem>
#include <QObject>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include <QDialog>
#include <QTextEdit>
#include <Python.h>

class CodeRun : public QQuickItem
{
    Q_OBJECT

public:
    CodeRun(QQuickItem *parent = nullptr);
    ~CodeRun();

public slots:
    void handleRunAction(const QString &content);

private:
    void initializePython();
    void finalizePython();

    PyThreadState *pythonThreadState;
};

class CodeDialog : public QDialog
{
    Q_OBJECT

public:
    CodeDialog(QWidget *parent = nullptr, const QString &output = QString());
    ~CodeDialog();

private:
    QDialog *codeDialog;
    QLabel *titleLabel;
    QTextEdit *outputText;
    QPushButton *closeButton;
};

#endif // CODERUN_H