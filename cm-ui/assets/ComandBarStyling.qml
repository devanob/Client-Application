pragma Singleton
import QtQuick 2.0


Item {
    readonly property color colourCommandBarBackground: "#cecece"
    readonly property color colourCommandBarFont: "#131313"
    readonly property color colourCommandBarFontDisabled: "#636363"
    readonly property real heightCommandBar: heightCommandButton
    readonly property int pixelSizeCommandBarIcon: 32
    readonly property int pixelSizeCommandBarText: 12
    readonly property real widthCommandButton: 80
    readonly property real heightCommandButton: widthCommandButton
    property alias fontAwesome: fontAwesomeLoader.name
    FontLoader {
     id: fontAwesomeLoader
     source: "qrc:/assets/fontawesome.ttf"
    }
}
