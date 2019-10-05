import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.0
import QtQuick.Dialogs.qml 1.0
import assets.Style 1.0
import  assets 1.0;
import componets 1.0

Item {
    property alias commandList: commandRepeater.model
    property string  commandContext
    Component.onCompleted: masterController.ui_commandController.setTypeNotifier(commandContext)
     anchors {
         left: parent.left
         bottom: parent.bottom
         right: parent.right
     }
     height: ComandBarStyling.heightCommandBar
     Rectangle {
        anchors.fill: parent
        color: ComandBarStyling.colourCommandBarBackground
        Row {
            anchors {
                top: parent.top
                bottom: parent.bottom
                right: parent.right
            }
            Repeater {

                id: commandRepeater
                delegate: CommandButton {
                    command: modelData
                }
            }
        }
      }
}
