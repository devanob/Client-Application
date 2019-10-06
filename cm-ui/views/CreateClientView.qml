import QtQuick 2.0
import QtQuick.Dialogs 1.0
import componets 1.0;
Item{
    Rectangle{
         anchors.fill: parent
         color: "#7be114"
         Text {
             anchors.centerIn: parent
             text: "CreateClient View"
         }

    }
    CommandBar {
       commandList:masterController.ui_commandController.ui_commands
       commandContext : "create-client"
    }
}



/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
