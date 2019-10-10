import QtQuick 2.0
import componets 1.0;
import assets 1.0;
import QtQuick.Layouts 1.12
Rectangle{
    
    radius: width*0.5
    Layout.fillHeight: true
    Layout.fillWidth: true
    Text {
        anchors.centerIn: parent
        
        id: rec1
        text: qsTr("rect1")
        z: 5
    }
    
    Canvas {
        anchors.fill: parent
        onPaint: {
            var ctx = getContext("2d");
            ctx.reset();
            
            var centreX = width / 2;
            var centreY = height / 2;
            
            ctx.beginPath();
            ctx.fillStyle = "black";
            ctx.moveTo(centreX, centreY);
            ctx.arc(centreX, centreY, width / 3, 0, Math.PI * 0.5, false);
            ctx.lineTo(centreX, centreY);
            
            ctx.fill();
            
            
            ctx.beginPath();
            ctx.fillStyle = "red";
            ctx.moveTo(centreX, centreY);
            ctx.arc(centreX, centreY, width / 4, Math.PI * 0.5, Math.PI * 2, false);
            ctx.lineTo(centreX, centreY);
            ctx.fill();
        }
    }
}
