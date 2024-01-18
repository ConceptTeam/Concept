#include "ToolBox.h"
#include <QBoxLayout>
#include <QtWidgets/QtWidgets>

ToolBox::ToolBox(QQuickItem *parent) : QQuickItem(parent)
{
    // Initialize replace dialog components
    replaceDialog = new QDialog();
    replaceDialog->setWindowTitle("Replace");
    replaceTitleLabel = new QLabel("Enter keyword to replace and its replacement:", replaceDialog);
    keywordInput = new QLineEdit(replaceDialog);
    replacementInput = new QLineEdit(replaceDialog);
    replaceButton = new QPushButton("Replace", replaceDialog);
    replaceConfirmationLabel = new QLabel("", replaceDialog);
    closeReplaceButton = new QPushButton("Close Window", replaceDialog);

    // Design of the dialog box
    QVBoxLayout *replaceLayout = new QVBoxLayout(replaceDialog);
    replaceLayout->addWidget(replaceTitleLabel);
    replaceLayout->addWidget(keywordInput);
    replaceLayout->addWidget(replacementInput);
    replaceLayout->addWidget(replaceButton);
    replaceLayout->addWidget(closeReplaceButton);
    replaceLayout->addWidget(replaceConfirmationLabel);

    connect(replaceButton, &QPushButton::clicked, this, &ToolBox::onReplace);
    connect(closeReplaceButton, &QPushButton::clicked, replaceDialog, &QDialog::close);
}

ToolBox::~ToolBox() {}

void ToolBox::handleSearchAction(const QString &content)
{
    // Here, we use the SearchDialog class to execute the search
    SearchDialog *searchDialog = new SearchDialog(nullptr, content);
    searchDialog->exec();

    // In order to prevent memory leaks, we use a deleteLater function
    searchDialog->deleteLater();
}

void ToolBox::handleReplaceAction(const QString &content)
{
    // Here, due to the signal issue, we are forced to execute the
    // replace within the ToolBox class.
    text = content;
    replaceDialog->exec();

    // In order to prevent memory leaks, we use a deleteLater function
    replaceDialog->deleteLater();
}

SearchDialog::SearchDialog(QWidget *parent, const QString &editorText) : QDialog(parent), text(editorText)
{
    setWindowTitle("Search");
    // Initialize search dialog components
    titleLabel = new QLabel("Enter keyword to search:", this);
    keywordInput = new QLineEdit(this);
    searchButton = new QPushButton("Search", this);
    searchResults = new QListWidget(this);
    closeSearchButton = new QPushButton("Close Window", this);

    // Design of the dialog box
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(titleLabel);
    layout->addWidget(keywordInput);
    layout->addWidget(searchButton);
    layout->addWidget(searchResults);
    layout->addWidget(closeSearchButton);

    connect(searchButton, &QPushButton::clicked, this, &SearchDialog::onSearch);
    connect(closeSearchButton, &QPushButton::clicked, this, &QDialog::close);
}

void SearchDialog::onSearch()
{

    QString keyword = keywordInput->text();

    searchResults->clear();

    if (keyword.isEmpty())
    {
        searchResults->addItem("Keyword not found");
        return;
    }

    QStringList lines = text.split("\n");

    for (int i = 0; i < lines.size(); ++i)
    {
        // If the line contains the keyword
        int index = lines[i].indexOf(keyword);
        if (index != -1)
        {
            // Calculate the start and end positions for the substring

            // I chose +/- 10 arbitrarely to make it only print part of
            // line as it looks better
            int start = std::max(0, index - 10);
            int end = std::min(lines[i].length(), index + keyword.length() + 10);

            // Get the substring around the keyword
            QString substring = lines[i].mid(start, end - start);

            // Add the substring to the search results
            QListWidgetItem *item = new QListWidgetItem(QString("Line ") + QString::number(i + 1) + QString(". '") + substring + QString("'"));
            searchResults->addItem(item);
        }
    }

    if (searchResults->count() == 0)
    {
        searchResults->addItem("Keyword not found");
    }
}

SearchDialog::~SearchDialog()
{
}

void ToolBox::onReplace()
{
    // Get the keyword and its replacement from the inputs
    QString keyword = keywordInput->text();
    QString replacement = replacementInput->text();

    // Replace all occurrences of the keyword in the text
    QString copy = text;
    text.replace(keyword, replacement);

    if (copy == text)
    {
        replaceConfirmationLabel->setText("Nothing to change.");
    }
    else
    {
        replaceConfirmationLabel->setText("Replacement done.");

        // Emit the signal to update the main text in main.qml
        emit textChanged(text);
    }
}
