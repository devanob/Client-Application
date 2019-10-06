import QtQuick 2.0
import componets 1.0;
import assets 1.0;
Item{
    z: 0

    Rectangle{
         anchors.fill: parent
         color: "#fda2a2"
         Text {
             anchors.centerIn: parent
             text: "Dashoard View"
         }
         CommandBar {
             z: 1
             commandList:masterController.ui_commandController.ui_commands
             commandContext : "dashboard"
         }



//         MouseArea {
//          anchors.fill: parent

//          onClicked: masterController.ui_commandController.setTypeNotifier("hello")
//         }
    }

}




/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
