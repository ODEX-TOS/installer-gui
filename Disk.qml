import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Imagine 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.13
import tos 1.0
Item {
    id: diskTab

    GroupBox {
        id: disktype;
        title: "Install TOS"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        Column {
            RadioButton {
                text: "Erase disk and install TOS"
                checked: true
            }
            RadioButton {
                text: "Erase disk and install TOS with encryption"
            }
            RadioButton {
                text: "Dual boot"
            }
        }
    }

    Handler {
        id: handle
    }

    GroupBox {
        id: diskselect;
        title: "Install TOS"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        visible: false
        Column {
               id: column
               Repeater {
                    function getDrives() {
                            for(var item in handle.getDisks())
                                console.log(item)
                           return handle.getDisks();
                           //return ["sda", "sdb", "nvme0n1p"];
                    }
                    id: repeater
                    model: getDrives()
                    RadioButton { text: "/dev/" + modelData }
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
            diskselect.visible=true;
            disktype.visible=false;
        }
    }
}







/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
