import QtQuick 2.0
import QtQml.Models 2.12
import QtQuick.Controls.Imagine 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.13
import QtQuick.Controls.Material 2.12
Item {
    id: finalTab;
    Image {
        id: image
        width: 248
        height: 199
        anchors.left: parent.horizontalCenter
        anchors.leftMargin: -125
        anchors.top: parent.top
        anchors.topMargin: 50
        fillMode: Image.PreserveAspectFit
        source: "TOS_logo.svg"
    }

    Text {
        id: installed
        x: 103
        y: 326
        width: 457
        height: 65
        text: qsTr("TOS is installed")
        color: Material.foreground
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.leftMargin: 0
        horizontalAlignment: Text.AlignHCenter
        font.family: "Times New Roman"
        lineHeight: 1
        fontSizeMode: Text.Fit
        anchors.top: image.bottom
        anchors.topMargin: 100
        anchors.left: parent.horizontalCenter
        font.pixelSize: 50
    }

    RowLayout {
        id: buttons
        x: 207
        y: 420
        width: 236
        height: 100
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: installed.bottom
        anchors.topMargin: 50

        Button {
            text: qsTr("Quit")
            Material.background:  Material.Green
            onClicked: {
                        Qt.quit();
            }
        }

        Button {
            text: qsTr("Cancel")
            Material.background:  Material.Red
            onClicked: {
                        console.log(myobject.reken_tijden_uit())
            }
        }
    }

}









/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:1;anchors_width:248;anchors_x:196;anchors_y:141}
D{i:2;anchors_height:65;anchors_width:457;anchors_x:103;anchors_y:326}
}
 ##^##*/
