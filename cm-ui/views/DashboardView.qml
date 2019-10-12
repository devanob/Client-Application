import QtQuick 2.0
import componets 1.0;
import assets 1.0;
import QtQuick.Layouts 1.12
Item{
    z: 0


    Rectangle{
         id: dashbaord_id
         anchors.fill: parent

//         Text {
//             anchors.centerIn: parent
//             text: "Dashoard View"
//         }

         CommandBar {
             id:command_bar_dashview
             z: 1
             commandList:masterController.ui_commandController.ui_commands
             commandContext : "dashboard"
         }

         GridLayout {
             id: gridView
             anchors.top: parent.top
             anchors.topMargin: 5
             anchors.left: parent.left
             anchors.leftMargin: 5
             anchors.right: parent.right
             anchors.rightMargin: 5
             height: dashbaord_id.height - command_bar_dashview.height - 10
             z: 0
             rows: 3
             columns: 3

             LevelComponet {
                 background_color: "white"
                 percent:0.30
                 statusText:"Location:East Tank"

             }
             LevelComponet {

                 background_color: "white"
                 percent:0.80
             }
             LevelComponet {

                 background_color: "white"
                 percent:0.90
             }
             LevelComponet {

                 background_color: "white"
                 percent:0.15
             }




           }


    }

}






















/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:3;anchors_height:140;anchors_width:140;anchors_x:237;anchors_y:175}
}
 ##^##*/
