import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Imagine 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.13
import tos 1.0
Item {
    id: diskTab
    property int nextClicked: 0
    property string device: ""
    property string type: "normal"
    GroupBox {
        id: disktype;
        title: "Install TOS"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        Column {
            RadioButton {
                text: "Erase disk and install TOS"
                checked: true
                onClicked: {
                             type = "normal"
                }
            }
            RadioButton {
                text: "Erase disk and install TOS with encryption"
                onClicked: {
                             type = "encryption"
                }
            }
            RadioButton {
                text: "Dual boot"
                onClicked: {
                             type = "bualboot"
                }
            }
        }
    }

    Handler {
        id: handle
    }

    GroupBox {
        id: diskselect;
        title: "Choose your install disk"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        visible: false
        Column {
               id: column
               Repeater {
                    function getDrives() {
                           return handle.getDisks();
                    }
                    id: repeater
                    model: getDrives()
                    RadioButton {
                        text: modelData
                        onClicked: {
                            device = modelData.split(" ")[0]
                        }
                    }
               }
        }
    }

    Button {
        text: "Next"
        Material.background:  Material.accent
        anchors.rightMargin: 20
        anchors.bottomMargin: 20
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        onClicked: {
            if (nextClicked == 0){
                diskselect.visible=true;
                disktype.visible=false;
            }else if (nextClicked == 1){
                diskselect.visible=false;
                console.log(type, device);
                advance();
            }

            nextClicked++;
        }
    }
}







/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
