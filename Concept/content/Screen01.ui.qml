import QtQuick 6.2
import QtQuick.Controls 6.2
import Concept

Rectangle {
    width: Constants.width
    height: Constants.height

    // This is the title bar
    Rectangle {
        id: nameBar
        width: parent.width
        height: 80
        color: "#A1B5D8"

        //Title Concept
        Text {
            text: "Concept"
            id: conceptText
            font.pixelSize: 50
            //font.family: "Helvetica"
            anchors.left: parent.left
            verticalAlignment: Text.AlignVCenter
            leftPadding: 150
        }

        //spacing item
        Item {
            id: spacerTitleHelp
            anchors.left: conceptText.right
            width: 800
        }

        // "Help" button
        Button {
            id: helpButton
            text: "Help"
            font.pixelSize: 20
            anchors.left: spacerTitleHelp.right
            anchors.verticalCenter: parent.verticalCenter
        }

        //spacing item
        Item {
            id: spacerHelpSearch
            anchors.left: helpButton.right
            width: 100
        }

        // Search Bar
        TextField {
            id: searchBar
            placeholderText: "Search..."
            width: 300
            anchors.left: spacerHelpSearch.right
            anchors.verticalCenter: parent.verticalCenter
        }

        //spacing item
        Item {
            id: spacerSearchButton
            anchors.left: searchBar.right
            width: 40
        }

        // "Search" button
        Button {
            id: searchButton
            text: "Search"
            font.pixelSize: 20
            anchors.left: spacerSearchButton.right
            anchors.verticalCenter: parent.verticalCenter
        }

        //spacing item
        Item {
            width: 200
            anchors.left: searchButton.right
        }

    }


    // Main Content
    Rectangle {
        id: rectangle
        width: parent.width
        height: parent.height - nameBar.height

        anchors.top: nameBar.bottom

        color: Constants.backgroundColor

        Button {
            id: button
            text: qsTr("Press me")
            anchors.verticalCenter: parent.verticalCenter
            checkable: true
            anchors.horizontalCenter: parent.horizontalCenter

            Connections {
                target: button
                onClicked: animation.start()
            }
        }

        Text {
            id: label
            text: qsTr("Hello Concept")
            anchors.top: button.bottom
            font.family: Constants.font.family
            anchors.topMargin: 45
            anchors.horizontalCenter: parent.horizontalCenter

            SequentialAnimation {
                id: animation

                ColorAnimation {
                    id: colorAnimation1
                    target: rectangle
                    property: "color"
                    to: "#2294c6"
                    from: Constants.backgroundColor
                }

                ColorAnimation {
                    id: colorAnimation2
                    target: rectangle
                    property: "color"
                    to: Constants.backgroundColor
                    from: "#2294c6"
                }
            }
        }

        states: [
            State {
                name: "clicked"
                when: button.checked

                PropertyChanges {
                    target: label
                    text: qsTr("Button Checked")
                }
            }
        ]
    }
}
