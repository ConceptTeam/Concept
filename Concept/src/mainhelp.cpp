// mainhelp.cpp
#include "mainhelp.h"
#include <QAction>
#include <QCursor>
#include <QDebug>
#include <QQuickItem>
#include <QBoxLayout>

MainHelp::MainHelp(QQuickItem *parent) : QQuickItem(parent) {
    QAction *helpAction1 = new QAction("File - View - Format", this);
    QAction *helpAction2 = new QAction("Notebooks", this);
    QAction *helpAction3 = new QAction("3. Help Text 3", this);

    connect(helpAction1, &QAction::triggered, this, &MainHelp::handleHelpAction1);  // Corrected connection
    connect(helpAction2, &QAction::triggered, this, &MainHelp::handleHelpAction2);
    connect(helpAction3, &QAction::triggered, this, &MainHelp::handleHelpAction3);

    helpMenu.addAction(helpAction1);
    helpMenu.addAction(helpAction2);
    helpMenu.addAction(helpAction3);
}

void MainHelp::showHelpMenu() {
    // Show the context menu at the current cursor position
    helpMenu.exec(QCursor::pos());
}

void MainHelp::handleHelpAction2() {
    qDebug() << "Help Text 2 clicked!";

    HelpNotebooks *helpNotebooks = new HelpNotebooks();
    helpNotebooks->exec();  // Use exec() for a modal dialog

    // Cleanup the dialog when done
    delete helpNotebooks;
}

void MainHelp::handleHelpAction3() {
    qDebug() << "Help Text 3 clicked!";
    // Add your logic here
}

MainHelp::~MainHelp() {
    // Perform cleanup or resource release here, if needed
}

void MainHelp::handleHelpAction1() {
    qDebug() << "File";

    HelpDialog1 *helpDialog1 = new HelpDialog1();
    helpDialog1->exec();  // Use exec() for a modal dialog

    // Cleanup the dialog when done
    delete helpDialog1;
}

HelpDialog1::HelpDialog1(QWidget *parent) : QDialog(parent) {
    setWindowTitle("Help File");

    // Create and setup UI components
    titleLabel = new QLabel("", this);
    featuresLabel = new QLabel("Features:", this);

    // Create a QListWidget for displaying the list of features
    featuresList = new QListWidget(this);
    featuresList->addItem("Save Note");
    featuresList->addItem("New Note");
    featuresList->addItem("Increase/Decrease Font");
    featuresList->addItem("Toggle Line Number");
    featuresList->addItem("Toggle Expand Path");
    featuresList->addItem("Exit");


    // Populate the feature explanations map
    featureExplanations["Save Note"] = "This feature saves the note into the \nNotebooks section.";
    featureExplanations["New Note"] = "This feature creates a new note in the current \ntext editor, while still adding it to the \nNotebooks section.";
    featureExplanations["Increase/Decrease Font"] = "This feature changes the \nfont size as wanted.";
    featureExplanations["Toggle Line Number"] = "Turn ON/OFF the line numbers on the left of \nthe text editor.";
    featureExplanations["Toggle Expand Path"] = "This feature expands all \npaths in the current file.";
    featureExplanations["Exit"] = "Closes the whole app.";


    // Create a QLabel for displaying feature explanations
    featureExplanationLabel = new QLabel("", this);

    closeButton = new QPushButton("Close", this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(titleLabel);
    layout->addWidget(featuresLabel);
    layout->addWidget(featuresList);
    layout->addWidget(featureExplanationLabel);
    layout->addWidget(closeButton);

    connect(closeButton, &QPushButton::clicked, this, &HelpDialog1::close);

    // Connect the itemClicked signal to the custom slot
    connect(featuresList, &QListWidget::itemClicked, this, &HelpDialog1::onFeatureItemSelected);
}

void HelpDialog1::onFeatureItemSelected(QListWidgetItem *item) {
    // Update the explanation label based on the selected feature
    QString feature = item->text();
    if (featureExplanations.contains(feature)) {
        featureExplanationLabel->setText(featureExplanations[feature]);
    } else {
        featureExplanationLabel->setText("");
    }
}

HelpDialog1::~HelpDialog1() {
    // Perform cleanup or resource release here, if needed
}


HelpNotebooks::HelpNotebooks(QWidget *parent) : QDialog(parent) {
    setWindowTitle("Help Notebooks");

    // Create and setup UI components
    titleNotebooks = new QLabel("", this);
    featuresNotebooks = new QLabel("This section is where you find your saved and current \nfolders and files. You can toggle between them, \nopen which one you like, read or edit it!", this);

    closeButton2 = new QPushButton("Close", this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(titleNotebooks);
    layout->addWidget(featuresNotebooks);
    //layout->addWidget(featuresList);
    //layout->addWidget(featureExplanationLabel);
    layout->addWidget(closeButton2);

    connect(closeButton2, &QPushButton::clicked, this, &HelpNotebooks::close);

    // Connect the itemClicked signal to the custom slot
    //connect(featuresList, &QListWidget::itemClicked, this, &HelpDialog1::onFeatureItemSelected);
}


HelpNotebooks::~HelpNotebooks() {
    // Perform cleanup or resource release here, if needed
}
