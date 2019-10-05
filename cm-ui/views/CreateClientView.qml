import QtQuick 2.0
import QtQuick.Dialogs 1.0
Item{
    Rectangle{
         anchors.fill: parent
         color: "#7be114"
         Text {
             anchors.centerIn: parent
             text: "CreateClient View"
         }
         FileDialog {
             id: fileDialog
             title: "Please choose a file"
             folder: shortcuts.home
             onAccepted: {
                 console.log("You chose: " + fileDialog.fileUrls)
                 Qt.quit()
             }
             onRejected: {
                 console.log("Canceled")
                 Qt.quit()
             }
             selectMultiple:true
             Component.onCompleted: visible = true
         }

    }
}



/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
