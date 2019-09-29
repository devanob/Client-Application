import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.0
import QtQuick.Dialogs.qml 1.0
import assets.Style 1.0
import assets 1.0;

Item {
    property alias iconCharacter: textItemIcon.text
    property alias description: textItemDesc.text
    width: NavItemStyling.widthNavigationButton
    height: NavItemStyling.heightNavigationButton
    signal navigationButtonClicked()

    Rectangle {
        id:background
        color: NavItemStyling.colourNavigationButtonColour
        anchors.fill: parent
        Row {

            anchors.fill: parent
            id:  menuItem
            Text {
                id:textItemIcon
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                width: NavItemStyling.widthNavigationButtonIcon
                height: NavItemStyling.heightNavigationButtonIcon
                font {
                    family:NavItemStyling.fontAwesome
                    pixelSize:  NavItemStyling.pixelSizeNavigationBarIcon
                }
                color: "#ffffff"
                text: "\uf0c9"
            }
            Text {
             id: textItemDesc
             verticalAlignment: Text.AlignVCenter
             horizontalAlignment: Text.AlignHCenter
             text: "(Default Text)"
             width: NavItemStyling.widthNavigationButtonDescription
             height: NavItemStyling.heightNavigationButtonDescription
             color: NavItemStyling.colourNavigationBarFont

             }

        }
        states: [
             State {
                 name: "hover"
                 PropertyChanges {
                     target: textItemIcon
                     color: "red"
                 }
                 PropertyChanges {
                     target: textItemDesc
                     color: "red"
                 }
                 PropertyChanges {
                     target: background
                     color: "#cea1a1"
                 }
             }
        ]
        MouseArea {
         anchors.fill: parent
         cursorShape: Qt.PointingHandCursor
         hoverEnabled: true
         onEntered: background.state = "hover"
         onExited: background.state = ""
         onClicked: navigationButtonClicked()
        }
    }
}





/*##^## Designer {
    D{i:4;invisible:true}
}
 ##^##*/
