import QtQuick
// import QtQuick.Controls
import QtQuick.Controls.Basic
import QtQuick.Layouts
import Concept
import QtQuick.Shapes

pragma ComponentBehavior: Bound

ApplicationWindow {
    id: root

    property bool showLineNumbers: true

    // readonly property font fontFamily: "Arial"

    width: Screen.width * 0.95
    height: Screen.height * 0.95
    title: "Concept"
    visible: true
    color: Colors.background
    flags: Qt.Window | Qt.FramelessWindowHint

    menuBar: CMenuBar {
        dragWindow: root
        infoText: "Concept"

        CMenu {
            title: qsTr("File")

            Action {
                text: qsTr("Increase Font")
                shortcut: StandardKey.ZoomIn
                onTriggered: editor.text.font.pixelSize += 1
            }
            Action {
                text: qsTr("Decrease Font")
                shortcut: StandardKey.ZoomOut
                onTriggered: editor.text.font.pixelSize -= 1
            }
            Action {
                text: root.showLineNumbers ? qsTr("Toggle Line Numbers OFF")
                    : qsTr("Toggle Line Numbers ON")
                shortcut: "Ctrl+L"
                onTriggered: root.showLineNumbers = !root.showLineNumbers
            }
            Action {
                text: root.expandPath ? qsTr("Toggle Short Path")
                    : qsTr("Toggle Expand Path")
                enabled: root.currentFilePath
                onTriggered: root.expandPath = !root.expandPath
            }
            Action {
                text: qsTr("Exit")
                onTriggered: Qt.exit(0)
                shortcut: StandardKey.Quit
            }

            
        }
    }

    RowLayout {
        anchors.fill: parent
        spacing: 0

        CSidebar {
            id: sidebar
            dragWindow: root
            Layout.preferredWidth: 50
            Layout.fillHeight: true
        }

        SplitView {
            Layout.fillWidth: true
            Layout.fillHeight: true
            // Customized handle to drag between the Navigation and the Editor.
            handle: Rectangle {
                implicitWidth: 5
                color: SplitHandle.pressed ? Colors.color2 : Colors.background
                border.color: SplitHandle.hovered ? Colors.color2 : Colors.background
                opacity: SplitHandle.hovered || navigationView.width < 15 ? 1.0 : 0.0

                Behavior on opacity {
                    OpacityAnimator {
                        duration: 1400
                    }
                }
            }

            Rectangle {
                id: navigationView
                color: Colors.surface1
                SplitView.preferredWidth: 250
                SplitView.fillHeight: true
                // The stack-layout provides different views, based on the
                // selected buttons inside the sidebar.
                StackLayout {
                    anchors.fill: parent
                    currentIndex: sidebar.currentTabIndex

                    // Shows the help text.
                    Text {
                        anchors.leftMargin: 10
                        anchors.topMargin: 10
                        text: qsTr("This is a field")
                        wrapMode: TextArea.Wrap
                        color: Colors.text
                    }

                    // Shows the files on the file system.
                    // FileSystemView {
                    //     id: fileSystemView
                    //     color: Colors.surface1
                    //     onFileClicked: path => root.currentFilePath = path
                    // }
                }
            }

            // The main view that contains the editor.
            CEditor {
                id: editor
                showLineNumbers: root.showLineNumbers
                currentFilePath: root.currentFilePath
                SplitView.preferredWidth: 800
                SplitView.fillHeight: true
            }

            SplitView {
                Layout.fillWidth: true
                Layout.fillHeight: true
                // Customized handle to drag between the Navigation and the Editor.
                handle: Rectangle {
                    implicitWidth: 5
                    color: SplitHandle.pressed ? Colors.color2 : Colors.background
                    border.color: SplitHandle.hovered ? Colors.color2 : Colors.background
                    opacity: SplitHandle.hovered || navigationView.width < 15 ? 1.0 : 0.0

                    Behavior on opacity {
                        OpacityAnimator {
                            duration: 1400
                        }
                    }
                }

                Pomodoro {
                    id: pomodoro
                    SplitView.fillWidth: true
                    SplitView.fillHeight: true
                    color: Colors.surface1
                }

            }
        }
    }
}

