
pragma Singleton
import QtQuick 2.0

Item {
    //NavItemStyling
    readonly property color colourNavigationButtonColour: "#000000"
    readonly property color colourNavigationBarFont: "#ffffff"
    readonly property int pixelSizeNavigationBarIcon: 42
    readonly property real widthNavigationButtonIcon: 80
    readonly property real heightNavigationButtonIcon:widthNavigationButtonIcon
    readonly property real widthNavigationButtonDescription: 240
    readonly property real heightNavigationButtonDescription:heightNavigationButtonIcon
    readonly property real widthNavigationButton: widthNavigationButtonIcon +widthNavigationButtonDescription
    readonly property real heightNavigationButton: Math.max(heightNavigationButtonIcon, heightNavigationButtonDescription)
    property alias fontAwesome: fontAwesomeLoader.name
    FontLoader {
     id: fontAwesomeLoader
     source: "qrc:/assets/fontawesome.ttf"
    }
    //NavBarStyling
    readonly property real widthNavigationBarCollapsed:widthNavigationButtonIcon
    readonly property real heightNavigationBarExpanded: widthNavigationButton
}
