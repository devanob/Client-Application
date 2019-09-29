import QtQuick 2.9
import assets.Style 1.0
import componets 1.0
Item{
    id: element

    Rectangle {
         anchors.fill: parent
         Text {
             anchors.centerIn: parent
             text: masterController.ui_welcomeMessage
         }
         color: Style.colourBackground
    }
}



/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
