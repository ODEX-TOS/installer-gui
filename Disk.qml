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
                text: "Install as EFI (leave at default if you don't know)"
                checked: handle.isEFI()
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

    GroupBox {
        id: encrypt;
        width: 300
        height: 220
        title: "What is your encryption password"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        visible: false
        Column {
            id: encryptedpwd
            TextField{
                id: pass
                width: 280
                height: 60
                anchors.top: name.bottom
                anchors.topMargin: 20
                placeholderText: qsTr("Enter password")
                echoMode: TextInput.Password
            }
            TextField{
                id: passconfirm
                width: 280
                height: 60
                anchors.top: pass.bottom
                anchors.topMargin: 20
                placeholderText: qsTr("Confirm your password")
                echoMode: TextInput.Password
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
        function addEncryptedDisk(){
            if(efi.checked){
                createPartition(0, "efi", "/boot/efi", "fat32", "1MiB", "200MiB");
                createPartition(0, "boot", "/boot", "ext4", "200MiB", "800MiB");
            }else{
                createPartition(0, "boot", "/boot", "ext4", "1MiB", "800MiB");
            }
            var size = yaml.diskSizeInGB(device);
            createLogicVolume(0, "root", ((size/2)-1) + "GB", "/");
            createLogicVolume(0, "home", (size/2) + "GB", "/home");
            createEncryptedPartition(0,0, pass.text, "root", "/", "800MiB", "100%");

            createDisk(device, yaml.diskSize(device), efi.checked, true, 0);
        }

        function firstClick(){
            diskselect.visible=true;
            disktype.visible=false;
            nextClicked++;
        }

        function encryptionClick(){
            if (type === "encryption"){
                diskselect.visible = false;
                encrypt.visible = true;
                nextClicked++;
                return
            }
            nextClicked++;
            finalClick();

        }

        function finalClick(){
            if (device !== ""){
                diskselect.visible=false;
                console.log(type, device);
                if(type === "normal"){
                    addNormalDisk();
                }else if (type === "encryption"){
                    addEncryptedDisk();
                }
                advance();
                nextClicked++;
            }else{
                dialog.visible=true;
            }
        }

        function encryptionCheck(){
            if (type === "encryption"){
                if (pass.text === passconfirm.text && pass.text !== "" && pass.text !== " "){
                    finalClick();
                }else{
                    dialog.title = "Encryption passwords are wrong"
                    dialog.visible = true
                }
                return
            }
            finalClick();
        }

        onClicked: {
            if (nextClicked == 0){
                firstClick();
            }else if (nextClicked == 1){
                encryptionClick();
            }
            else if (nextClicked == 2){
                encryptionCheck();
            }else{
                finalClick()
            }

        }
    }
}







/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
