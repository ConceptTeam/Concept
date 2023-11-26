/* This file is generated and only relevant for integrating the project into a Qt 6 and cmake based
C++ project. */
import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: "Sub noet Page"

    Rectangle {
        anchors.fill: parent
        color: "white"

        Column {
            spacing: 10
            width: parent.width

            Text {
                text: "Sub noet Page"
                font.pixelSize: 24
                padding: 10
            }

            ListView {
                width: parent.width
                height: parent.height - 50
                model: ListModel {
                    ListElement { name: "List" }
                    ListElement { name: "List" }
                    ListElement { name: "List" }
                }

                delegate: Text {
                    text: name
                    font.pixelSize: 18
                    padding: 10
                }
            }
        }
    }
}

