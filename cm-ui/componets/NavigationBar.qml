import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.0
import QtQuick.Dialogs.qml 1.0
import assets.Style 1.0
import  assets 1.0;
import componets 1.0
Item {
    id: naviBar
    width: isCollapsed ? NavItemStyling.widthNavigationBarCollapsed : NavItemStyling.heightNavigationBarExpanded
    anchors {
     top: parent.top
     bottom: parent.bottom
     left: parent.left
    }
    property bool isCollapsed: true
    visible: true
    clip: false
    Rectangle {
        id: navigationBarRect
        color: "black"
        anchors.fill: parent
        anchors {

        }

        Column{
            id: column
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.right: parent.right
            anchors.rightMargin:0

            NavMenuComponet {
                id: toggleMenu
                iconCharacter:"\uf0c9"
                description: ""
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.rightMargin: 0
                onNavigationButtonClicked: isCollapsed = !isCollapsed


            }
            NavMenuComponet {
                id: dashBoardMenu
                iconCharacter:"\uf015"
                description: "Dashboard"
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.rightMargin: 0
                onNavigationButtonClicked:
                masterController.ui_navigationController.goDashboardView();
            }
            NavMenuComponet {
                id: newClientMenu
                iconCharacter:"\uf234"
                description: "NewClient"
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.rightMargin: 0
                onNavigationButtonClicked:
                masterController.ui_navigationController.goCreateClientView();

            }

            NavMenuComponet {
                id: findClientMenu
                iconCharacter:"\uf002"
                description: "Find-User"
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.rightMargin: 0
                onNavigationButtonClicked:
                masterController.ui_navigationController.goFindClientView();
            }
            NavMenuComponet {
                id: backMenu
                iconCharacter:"\uf060"
                description: "Go Back"
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.rightMargin: 0
                onNavigationButtonClicked:contentFrame.pop();

            }


        }


    }
}
