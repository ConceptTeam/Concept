#include "texteditor.hpp"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <iostream>

TextEditor::TextEditor(QWidget *parent)
    : QWidget(parent), textEdit(new QTextEdit(this)), menuBar(new QMenuBar(this)) {
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setMenuBar(menuBar);
    layout->addWidget(textEdit);

    createMenu();
}

TextEditor::~TextEditor() {
    //DESTROY TO IMPLEMENT IF NECESSARY

}

void TextEditor::createMenu() {
    //QMenu *fileMenu = new QMenu("File");
    QMenu *fileMenu = menuBar->addMenu("File");

    QAction *newAction = fileMenu->addAction("New");
    connect(newAction, &QAction::triggered, this, &TextEditor::newFile);

    QAction *openAction = fileMenu->addAction("Open");
    connect(openAction, &QAction::triggered, this, &TextEditor::openFile);

    QAction *saveAction = fileMenu->addAction("Save");
    connect(saveAction, &QAction::triggered, this, &TextEditor::saveFile);

    QAction *saveAsAction = fileMenu->addAction("Save As");
    connect(saveAsAction, &QAction::triggered, this, &TextEditor::saveFileAs);

    //menuBar->addAction(fileMenu->menuAction());
}

void TextEditor::newFile() {
    textEdit->clear();
    currentFilePath.clear();
}

void TextEditor::openFile() {
    QString filePath = QFileDialog::getOpenFileName(this, "Open File", QString(), "Text Files (*.txt);;All Files (*.*)");
    if (!filePath.isEmpty()) {
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            textEdit->setPlainText(in.readAll());
            currentFilePath = filePath;
            file.close();
        }
    }
}

void TextEditor::saveFile() {
    if (currentFilePath.isEmpty()) {
        saveFileAs();
    } else {
        QFile file(currentFilePath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << textEdit->toPlainText();
            file.close();
        }
    }
}

void TextEditor::saveFileAs() {
    QString filePath = QFileDialog::getSaveFileName(this, "Save File As", QString(), "Text Files (*.txt);;All Files (*.*)");
    if (!filePath.isEmpty()) {
        currentFilePath = filePath;
        saveFile();
    }
}

void TextEditor::showEditor() {
    TextEditor* NewTextEditor = new TextEditor();
    //NewTextEditor->setFixedSize(QSize(750, 400));
    listofTE.push_back(NewTextEditor);
    NewTextEditor->show();
    numberofTE++;
}

void TextEditor::resizeEditor(int width, int height){
    if(listofTE.empty())    return;
    //std::cout << width << ' ' << height << '\n';
    listofTE.back()->resize(width, height);
}

