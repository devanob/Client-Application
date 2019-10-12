import QtQuick 2.0
import componets 1.0;
import assets 1.0;
import QtQuick.Layouts 1.12
Item {
    property alias background_color: propane_level_background.color
    property real percent
    property alias  statusText: rec1.text
    Layout.fillHeight: true
    Layout.fillWidth: true
    Rectangle{
        id: propane_level_background
//        property float level
        radius: width*0.5
        anchors.fill: parent
        Column{
            anchors.centerIn: parent;
            z: 5
            Text {

                font.pixelSize: 0.05*propane_level_background.width
                id: rec1
                color: "white"
                text: "Status :Online"


            }
            Text {

                font.pixelSize: 0.05*propane_level_background.width
                id: rec2
                color: "white"
                text: "Location :North Each Tank"


            }
            Text {

                font.pixelSize: 0.05*propane_level_background.width
                id: rec3
                text: "Percent Propane: 50%"


            }
        }

        Canvas {
            anchors.fill: parent
            onPaint: {
                var ctx = getContext("2d");
                ctx.reset();

                var centreX = width / 2;
                var centreY = height / 2;

                ctx.beginPath();
                ctx.fillStyle = "green"
                ctx.moveTo(centreX, centreY);
                ctx.arc(centreX, centreY, Math.min(width / 2.0, height/2.0), 0, -2*Math.PI *percent, true);
                ctx.lineTo(centreX, centreY);
                ctx.fill();
                //
                ctx.beginPath();
                ctx.fillStyle = "red"
                ctx.moveTo(centreX, centreY);
                ctx.arc(centreX, centreY, Math.min(width / 2.0, height/2.0), -2*Math.PI *percent,0, true);
                ctx.lineTo(centreX, centreY);

                ctx.fill();



            }
        }
    }
}



/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
