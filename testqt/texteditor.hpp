#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QWidget>
#include <QTextEdit>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QVBoxLayout>
#include <vector>
#include <iostream>
#include "mainwindow.h"

class MainWindow;

class TextEditor : public QWidget {
    Q_OBJECT
public:
    explicit TextEditor(QWidget *parent = nullptr);
    virtual ~TextEditor() override;
    void setId(int newid);
    void setMain(MainWindow *newmain);

public slots:


private slots:
    void newFile();
    void openFile();
    void saveFile();
    void saveFileAs();
    void closeTE();

private:
    QTextEdit *textEdit;
    QString currentFilePath;
    QMenuBar *menuBar;
    void createMenu();
    int id;
    MainWindow* main;
};

#endif // TEXTEDITOR_H
                                                       
