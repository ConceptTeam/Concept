#include "texteditor.hpp"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
// New imports
#include "database.hpp"
#include <QCoreApplication> // This one might be useless
#include <QInputDialog>
#include <QString>
#include <ctime>
#include <string> // This one might be useless

TextEditor::TextEditor(QWidget *parent)
    : QMainWindow(parent)
{
    textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);

    createMenu();
}

TextEditor::~TextEditor()
{
    // DESTROY TO IMPLEMENT IF NECESSARY
}

void TextEditor::createMenu()
{
    QMenuBar *menuBar = new QMenuBar(this);
    setMenuBar(menuBar);

    QMenu *fileMenu = menuBar->addMenu("File");

    QAction *newAction = fileMenu->addAction("New");
    connect(newAction, &QAction::triggered, this, &TextEditor::newFile);

    QAction *openAction = fileMenu->addAction("Open");
    connect(openAction, &QAction::triggered, this, &TextEditor::openFile);

    QAction *saveAction = fileMenu->addAction("Save");
    connect(saveAction, &QAction::triggered, this, &TextEditor::saveFile);

    QAction *saveAsAction = fileMenu->addAction("Save As");
    connect(saveAsAction, &QAction::triggered, this, &TextEditor::saveFileAs);
}

void TextEditor::newFile()
{
    textEdit->clear();
    currentFilePath.clear();
}

void TextEditor::openFile()
{
    bool ok;
    int noteId = QInputDialog::getInt(this, tr("Note ID"),
                                      tr("Enter the ID of the Note you want to open:"), 1, 1, 1000, 1, &ok);
    if (!ok)
    {
        return;
    }
    if (!storage)
    {
        storage = std::make_unique<Storage>(initStorage("../Concept/Backend/src/database/database.db"));
        storage->sync_schema();
    }

    try
    {
        Note note = storage->get<Note>(noteId);
        textEdit->setPlainText(QString::fromStdString(note.content));

        // Store the current file path or note ID (if needed for saving)
        // currentFilePath = ...; // Adjust this if necessary
    }
    catch (const std::exception &e)
    {
        qDebug() << "Error opening note:" << e.what();
    }
}

void TextEditor::saveFile()
{
    if (currentFilePath.isEmpty())
    {
        saveFileAs();
    }
    else
    {
        QFile file(currentFilePath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream out(&file);
            out << textEdit->toPlainText();
            file.close();
        }
    }
}

void TextEditor::saveFileAs()
{
    storage = std::make_unique<Storage>(initStorage("../Concept/Backend/src/database/database.db"));
    storage->sync_schema();
    bool ok;
    int folder_id = QInputDialog::getInt(this, tr("Folder ID"),
                                         tr("Enter the folder ID:"), 1, 1, 1000, 1, &ok);
    QString Title = QInputDialog::getText(this, tr("Title"),
                                          tr("Enter the Title of the note:"), QLineEdit::Normal, QString(), &ok);
    if (ok)
    {
        std::string titleStr = Title.toStdString();
        auto existingNote = storage->get_all<Note>(where(c(&Note::title) == titleStr && c(&Note::folder_id) == folder_id));
        Note note;
        note.folder_id = folder_id;
        note.title = Title.toStdString();
        note.content = textEdit->toPlainText().toStdString();
        note.last_modified = std::time(0);

        if (!existingNote.empty())
        {
            note.id = existingNote.front().id;
            updateObject(note);
        }
        else
        {
            insertObject(note);
        }
    }
}

// Old functions for reference

// void TextEditor::openFile()
// {
//     QString filePath = QFileDialog::getOpenFileName(this, "Open File", QString(), "Text Files (*.txt);;All Files (*.*)");
//     if (!filePath.isEmpty())
//     {
//         QFile file(filePath);
//         if (file.open(QIODevice::ReadOnly | QIODevice::Text))
//         {
//             QTextStream in(&file);
//             textEdit->setPlainText(in.readAll());
//             currentFilePath = filePath;
//             file.close();
//         }
//     }
// }

// void TextEditor::saveFileAs()
// {
//     QString filePath = QFileDialog::getSaveFileName(this, "Save File As", QString(), "Text Files (*.txt);;All Files (*.*)");
//     if (!filePath.isEmpty())
//     {
//         currentFilePath = filePath;
//         saveFile();
//     }
// }

// 0 clue where the following comes from - probably a ChatGPT thing I lost track of

// void TextEditor::showEditor() {
//     listofTE.push_back(new TextEditor());
//     listofTE[numberofTE]->show();
//     numberofTE++;
// }
