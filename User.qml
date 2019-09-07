import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Imagine 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.13

Item {
    property string username: " "
    property string password: "pass"
    property string passwordConfirm: "pass2"
    GroupBox {
        id: group;
        width: 300
        height: 280
        title: "What is your username"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        Column {
            id: column
            TextField {
                id: name
                width: 280
                height: 60
                anchors.top: parent.top
                anchors.topMargin: 5
                placeholderText: qsTr("Enter name")
            }

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
                username = name.text
                password = pass.text
                passwordConfirm = passconfirm.text
                console.log(username, password)
                // empty strings or single spaces as username/passwords is forbidden
                if(password === passwordConfirm && username !== "" && password != "" && username !== " " && password !== " "){
                    createUser(username, password);
                    advance()
                }else{
                    if(username === ""){
                        dialog.title="You forgot to fill in your fields"
                    }else{
                        dialog.title="Your passwords don't match"
                    }

                    dialog.visible=true
                }
            }
        }

}





/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
