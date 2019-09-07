import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Imagine 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.13
import tos 1.0

Item {
    property string username: " "
    property string password: "pass"
    property string passwordConfirm: "pass2"

    Handler {
        id: handle
    }

    GroupBox {
        id: group;
        width: 300
        height: 440
        title: "System information"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        Column {
            id: column
            TextField {
                id: language
                width: 280
                height: 60
                anchors.top: parent.top
                anchors.topMargin: 5
                placeholderText: qsTr("Enter the system language")
            }

            TextField{
                id: keymap
                width: 280
                height: 60
                anchors.top: language.bottom
                anchors.topMargin: 20
                placeholderText: qsTr("What is your keyboard layout")
            }
            TextField{
                id: hostname
                width: 280
                height: 60
                anchors.top: keymap.bottom
                anchors.topMargin: 20
                placeholderText: qsTr("What is your hostname")
            }
            TextField{
                id: rootpwd
                width: 280
                height: 60
                anchors.top: hostname.bottom
                anchors.topMargin: 20
                placeholderText: qsTr("What is your root password?")
                echoMode: TextInput.Password
            }
            TextField{
                id: rootpwdconfirm
                width: 280
                height: 60
                anchors.top: rootpwd.bottom
                anchors.topMargin: 20
                placeholderText: qsTr("Confirm your password")
                echoMode: TextInput.Password
            }
        }
    }
    Dialog {
        id: dialog
        x: (parent.width - width) / 2
        y: (parent.height - height) / 2
        title: "Your passwords don't match"
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
            onClicked: {
                var _language = language.text
                var _keymap = keymap.text
                var _hostname = hostname.text
                password = rootpwd.text
                passwordConfirm = rootpwdconfirm.text
                console.log(username, password)

                function showDialog(){
                    dialog.title="You forgot to fill in your fields"
                    if(password !== passwordConfirm){
                        dialog.title="You passwords don't match"
                    }
                    dialog.visible=true
                }

                // empty strings or single spaces as username/passwords is forbidden
                if(_language !== " " && _keymap !== " " && _hostname !== " " && password !== " " && passwordConfirm !== " "){
                    if(_language !== "" && _keymap !== "" && _hostname !== "" && password !== "" && passwordConfirm !== ""){
                        if(password === passwordConfirm){
                            createSystem(_language, _keymap, _hostname, password);
                            advance()
                        }else{
                            showDialog();
                        }
                   }else{
                        showDialog();
                    }
                }else{
                        showDialog();
                }
            }
        }
}
