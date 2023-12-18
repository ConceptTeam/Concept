#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QWidget>
#include <QTextEdit>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QVBoxLayout>
#include <vector>
class TextEditor : public QWidget {
    Q_OBJECT
public:
    explicit TextEditor(QWidget *parent = nullptr);
    virtual ~TextEditor() override;


public slots:
    void showEditor();
    void resizeEditor(int width, int height);


private slots:
    void newFile();
    void openFile();
    void saveFile();
    void saveFileAs();


private:
    QTextEdit *textEdit;
    QString currentFilePath;
    QMenuBar *menuBar;
    std::vector<TextEditor*> listofTE;
    int numberofTE{0};
    void createMenu();
};

#endif // TEXTEDITOR_H
