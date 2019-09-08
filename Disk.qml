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
            CheckBox {
                id: efi
                text: "Install as EFI (leave checked if you don't know)"
                checked: true
                font.pixelSize: 15
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

    Dialog {
        id: dialog
        x: (parent.width - width) / 2
        y: (parent.height - height) / 2
        title: "Please select a device"
        standardButtons: Dialog.Ok

        onAccepted: console.log("Ok clicked")
    }

    Button {
        text: "Next"
        Material.background:  Material.accent
        anchors.rightMargin: 20
        anchors.bottomMargin: 20
        anchors.bottom: parent.bottom
        anchors.right: parent.right

        function addNormalDisk(){
            if(efi.checked){
                createPartition(0, "efi", "/boot/efi", "fat32", "1MiB", "200MiB");
                createPartition(0, "boot", "/boot", "ext4", "200MiB", "800MiB");
            }else{
                createPartition(0, "boot", "/boot", "ext4", "1MiB", "800MiB");
            }


            createPartition(0, "root", "/", "ext4", "800MiB", "40%");
            createPartition(0, "home", "/home", "ext4", "40%", "100%");

            createDisk(device, yaml.diskSize(device), efi.checked, true, 0);
        }

        onClicked: {
            if (nextClicked == 0){
                diskselect.visible=true;
                disktype.visible=false;
                nextClicked++;
            }else if (nextClicked == 1){
                if (device !== ""){
                    diskselect.visible=false;
                    console.log(type, device);
                    if(type === "normal"){
                        addNormalDisk();
                    }

                    advance();
                    nextClicked++;
                }else{
                    dialog.visible=true;
                }
            }

        }
    }
}







/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
