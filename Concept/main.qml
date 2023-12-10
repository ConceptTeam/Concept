import QtQuick 6.2
import QtQuick.Controls 6.2
import QtQuick.Window 2.2
import Concept

Window {
    width: Screen.width
    height: Screen.height
    title: "Concept"
    visible: true

    // This is the title bar
    Rectangle {
        id: nameBar
        width: parent.width
        height: parent.height * 0.07 // Set a percentage of the screen height
        color: "#A1B5D8"

        // Title Concept
        Text {
            text: "Concept"
            id: conceptText
            font.pixelSize: nameBar.height * 0.6 // Set a percentage of the nameBar height
            font.family: "Helvetica"
            anchors.left: parent.left
            verticalAlignment: Text.AlignVCenter
            leftPadding: parent.width * 0.1
        }

        // Spacing item
        Item {
            id: spacerTitleHelp
            anchors.left: conceptText.right
            width: parent.width * 0.45 // Set a percentage of the screen width
        }

        // "Help" button
        Button {
            id: helpButton
            text: "Help"
            font.pixelSize: nameBar.height * 0.25 // Set a percentage of the nameBar height
            anchors.left: spacerTitleHelp.right
            anchors.verticalCenter: parent.verticalCenter
        }

        // Spacing item
        Item {
            id: spacerHelpSearch
            anchors.left: helpButton.right
            width: parent.width * 0.07 // Set a percentage of the screen width
        }

        // Search Bar
        TextField {
            id: searchBar
            placeholderText: "Search..."
            width: parent.width * 0.12 // Set a percentage of the screen width
            height: nameBar.height * 0.55 // Set a percentage of the nameBar height
            anchors.left: spacerHelpSearch.right
            anchors.verticalCenter: parent.verticalCenter
        }

        // Spacing item
        Item {
            id: spacerSearchButton
            anchors.left: searchBar.right
            width: parent.width * 0.01 // Set a percentage of the screen width
        }

        // "Search" button
        Button {
            id: searchButton
            text: "Search"
            font.pixelSize: nameBar.height * 0.25 // Set a percentage of the nameBar height
            anchors.left: spacerSearchButton.right
            anchors.verticalCenter: parent.verticalCenter
        }

        // Spacing item
        Item {
            width: parent.width * 0.04 // Set a percentage of the screen width
            anchors.left: searchButton.right
        }
    }

    // Main Content with three columns
    Row {
        id: mainContentRow
        width: parent.width
        height: parent.height - nameBar.height
        anchors.top: nameBar.bottom

        // Column 1
        Rectangle {
            id: column1Container
            width: parent.width * 0.2
            height: mainContentRow.height
            color: "#F0EEE9"
        }

        // Column 2
        Rectangle {
            id: column2Container
            width: parent.width * 0.6
            height: mainContentRow.height
            color: "#F0EEE9"

            //header for column2 with 'View' 'Edit' functionnality to add the text editor
            Rectangle{
                id:column2Header
                width: parent.width
                height: parent.height * 0.05
                color: Qt.rgba(0.094, 0.294, 0.612, 0.769) //modify later, for now its to show you new stuff

                // "Edit" button
                Button {
                    id: editButton
                    text: "Edit"
                    font.pixelSize: column2Header.height * 0.25
                    anchors.right: column2Header.right
                    anchors.verticalCenter: column2Header.verticalCenter
                }

                // "View" button
                Button {
                    id: viewButton
                    text: "View"
                    font.pixelSize: column2Header.height * 0.25
                    anchors.right: editButton.left
                    anchors.verticalCenter: column2Header.verticalCenter
                }
            }

            Rectangle {
                id: chosenListColumn
                width: pomodoroColumn.width * 0.004
                height: column2Container.height
                color: "grey"
                //MouseArea {
                  //  anchors.fill: parent
                    //cursorShape: Qt.SizeHorCursor // Change cursor to horizontal resize

                    //property real startX: 0
                    //property real startWidth: 0

                    //onPressed: {
                      //  chosenListColumn.startX = mouse.x;
                        //chosenListColumn.startWidth = chosenListColumn.width;
                    //}

                    //onPositionChanged: {
                      //  let deltaX = mouse.x - chosenListColumn.startX;
                      //  let newWidth = chosenListColumn.startWidth + deltaX;

                        // Limit the width to a maximum of 500 pixels
                       // chosenListColumn.width = Math.min(500, Math.max(0, newWidth));
                       // column2Container.width = mainContentRow.width * 0.55 - chosenListColumn.width;
                       // column1Container.width = mainContentRow.width * 0.25;
                    //}

                    //onClicked: {
                        // Add this block to enable continuous resizing
                      //  chosenListColumn.startX = mouse.x;
                        //chosenListColumn.startWidth = chosenListColumn.width;
                    //}
                //}
            }
        }

        // Column 3
        Rectangle {
            id: pomodoroColumn
            width: parent.width * 0.2
            height: mainContentRow.height
            color: "#F0EEE9"

            Rectangle {
                id: column3Container
                width: pomodoroColumn.width * 0.004
                height: pomodoroColumn.height
                color: "grey"
            }

            Rectangle {
                id: spacerTitleBarStudyTimerText
                width: pomodoroColumn.width - column3Container.width
                height: mainContentRow.height * 0.05
                anchors.top: parent.top
                anchors.left:column3Container.right
                color: "#F0EEE9"
            }

            Text {
                text: "Study Timer"
                id: studyTimerText
                font.pixelSize: nameBar.height * 0.4
                font.family: "Helvetica"
                //anchors.left: column3Container.right
                verticalAlignment: pomodoroColumn.AlignVCenter
                anchors.top: spacerTitleBarStudyTimerText.bottom
                leftPadding: pomodoroColumn.width * 0.3
            }

            Rectangle {
                id: spacerStudyTimerTextTimerBlock
                width: pomodoroColumn.width - column3Container.width
                height: mainContentRow.height * 0.05
                anchors.top: studyTimerText.bottom
                anchors.left:column3Container.right
                color: "#F0EEE9"
            }

            Rectangle {
                id: timerBlock
                width: pomodoroColumn.width - column3Container.width
                height: mainContentRow.height * 0.2
                anchors.top: spacerStudyTimerTextTimerBlock.bottom
                anchors.left:column3Container.right
                color: "#C2D8B9"

                Row {

                    Button {
                        id: studyButton
                        text: "Study"
                        font.pixelSize: timerBlock.height * 0.07
                        //onClicked: startTimer(25)
                    }

                    Button {
                        text: "Break"
                        id: breakButton
                        font.pixelSize: timerBlock.height * 0.07
                        //onClicked: startTimer(5)
                    }

                }

                // Timer Display
                Text {
                    id: timerDisplay
                    text: "00:00"
                    font.pixelSize: timerBlock.height * 0.16
                    anchors.centerIn: parent
                }

                //Timer {
                    //id: countdownTimer
                    //interval: 1000
                    //onTriggered: updateTimerDisplay()
                //}

                //function startTimer(minutes) {
                    //countdownTimer.stop()
                    //countdownTimer.repeat = minutes * 60 * 1000
                    //countdownTimer.start()
                    //updateTimerDisplay()
                //}

                //function updateTimerDisplay() {
                    //var minutes = Math.floor(countdownTimer.repeat / 60000)
                    //var seconds = Math.floor((countdownTimer.repeat % 60000) / 1000)
                    //timerDisplay.text = Qt.formatDateTime(new Date(0, 0, 0, 0, minutes, seconds), "mm:ss")
                //}

            }
        }
    }
}

