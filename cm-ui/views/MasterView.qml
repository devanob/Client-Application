import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.0
import QtQuick.Dialogs.qml 1.0
import assets.Style 1.0
import componets 1.0
Window {
    Connections {

        target: masterController.ui_navigationController

        onGoCreateClientView: {
            console.log(contentFrame.depth);
            contentFrame.push("qrc:/views/CreateClientView.qml")
        }

        onGoDashboardView: {
             console.log(contentFrame.depth);
            contentFrame.push("qrc:/views/DashboardView.qml")
        }

        onGoEditClientView:{
             console.log(contentFrame.depth);
            contentFrame.push("qrc:/views/EditClientView.qml", {selectedClient:client})
        }

        onGoFindClientView:{
             console.log(contentFrame.depth);
            contentFrame.push("qrc:/views/FindClientView.qml")
        }

    }
    id: window
    visible: true
    width: 500
    height: 500
    title: qsTr("Demo Application")

    NavigationBar {
        id: navigationBar
        rotation: 0
        scale: 1



    }

    StackView{
        id: contentFrame
        clip: true
        anchors {
            top: parent.top
            bottom: parent.bottom
            right: parent.right
            left: navigationBar.right
        }
        pushEnter: Transition {
                PropertyAnimation {
                    property: "opacity"
                    from: 0
                    to:1
                    duration: 200
                }
            }
            pushExit: Transition {
                PropertyAnimation {
                    property: "opacity"
                    from: 1
                    to:0
                    duration: 200
                }
            }
            popEnter: Transition {
                PropertyAnimation {
                    property: "opacity"
                    from: 0
                    to:1
                    duration: 200
                }
            }
            popExit: Transition {
                PropertyAnimation {
                    property: "opacity"
                    from: 1
                    to:0
                    duration: 200
                }
            }
        //Component.onCompleted:contentFrame.replace("qrc:/views/DashboardView.qml");
        initialItem: Qt.resolvedUrl("qrc:views/SplashView.qml")
    }

       Component.onCompleted:
       contentFrame.replace("qrc:/views/DashboardView.qml");

}











































/*##^## Designer {
    D{i:2;anchors_height:500}
}
 ##^##*/
