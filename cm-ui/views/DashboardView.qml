import QtQuick 2.0
import componets 1.0;
import assets 1.0;
Item{
    Connections {

        target: masterController.ui_commandController
        onCommandContextChanged : console.log("command changed")



    }
    Rectangle{
         anchors.fill: parent
         color: "#fda2a2"
         Text {
             anchors.centerIn: parent
             text: "Dashoard View"
         }
         CommandBar {
            commandList:masterController.ui_commandController.ui_commands
            commandContext : "dashboard"
         }


//         MouseArea {
//          anchors.fill: parent

//          onClicked: masterController.ui_commandController.setTypeNotifier("hello")
//         }
    }

}

