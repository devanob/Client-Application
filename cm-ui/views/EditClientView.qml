import QtQuick 2.0
import QtQuick.Dialogs 1.0
Item{

    Rectangle{
         anchors.fill: parent
         color: "#1d0baf"
         Text {
             anchors.centerIn: parent
             text: "Edit Card"
         }

         GridView {
             id: gridView
             anchors.fill: parent
             model: ListModel {
                 ListElement {
                     name: "Grey"
                     colorCode: "grey"
                 }

                 ListElement {
                     name: "Red"
                     colorCode: "red"
                 }

                 ListElement {
                     name: "Blue"
                     colorCode: "blue"
                 }

                 ListElement {
                     name: "Green"
                     colorCode: "green"
                 }
             }
             cellWidth: 70
             cellHeight: 70
             delegate: Item {
                 x: 5
                 height: 50
                 Column {
                     Rectangle {
                         width: 40
                         height: 40
                         color: colorCode
                         anchors.horizontalCenter: parent.horizontalCenter
                     }

                     Text {
                         x: 5
                         text: name
                         anchors.horizontalCenter: parent.horizontalCenter
                         font.bold: true
                     }
                     spacing: 5
                 }
             }
         }

    }
}



/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:3;anchors_height:140;anchors_width:140;anchors_x:232;anchors_y:159}
}
 ##^##*/
