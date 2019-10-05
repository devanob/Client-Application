import QtQuick 2.0
import assets 1.0;
import CM 1.0;
Item {
    property Command command
    width: ComandBarStyling.widthCommandButton
    height: ComandBarStyling.heightCommandButton
    Rectangle {
        id: background
        anchors.fill: parent
        color: ComandBarStyling.colourCommandBarBackground
        Text {
        id: textIcon
        anchors {
             centerIn: parent
             verticalCenterOffset: -10
        }
        font {
             family: ComandBarStyling.fontAwesome
             pixelSize: ComandBarStyling.pixelSizeCommandBarIcon
         }
         color: command.ui_isActive ? ComandBarStyling.colourCommandBarFont :ComandBarStyling.colourCommandBarFontDisabled
         text: command.ui_command_icon
         horizontalAlignment: Text.AlignHCenter
         }
        Text {
             id: textDescription
             anchors {
                 top: textIcon.bottom
                 bottom: parent.bottom
                 left: parent.left
                 right: parent.right
             }
             font.pixelSize: ComandBarStyling.pixelSizeCommandBarText
             color: command.ui_isActive ? ComandBarStyling.colourCommandBarFont :
             ComandBarStyling.colourCommandBarFontDisabled
             text: command.ui_description
             horizontalAlignment: Text.AlignHCenter
             verticalAlignment: Text.AlignVCenter
             }
         MouseArea {
             anchors.fill: parent
             cursorShape: Qt.PointingHandCursor
             hoverEnabled: true
             onEntered: background.state = "hover"
             onExited: background.state = ""
             onClicked: if(command.ui_isActive) {
             command.executed();
             }
         }
         states: [
              State {
                  name: "hover"
                  PropertyChanges {
                      target: background
                      color: Qt.darker(ComandBarStyling.colourCommandBarBackground)
                  }
                  PropertyChanges {
                      target: background
                      color: Qt.darker(ComandBarStyling.colourCommandBarBackground)
                  }
               }
         ]
    }

}
