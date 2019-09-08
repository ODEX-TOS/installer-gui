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
        height: 280
        title: "System information"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        Column {
            id: column
            TextField{
                id: hostname
                width: 280
                height: 60
                anchors.top: column.bottom
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
    GroupBox {
        id: group2;
        width: 300
        anchors.top: parent.top
        anchors.topMargin: 70
        visible: false
        title: "System Language"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        ListView {
            property string clicker: handle.getLocals()[0];
            id: locals
            x: -138
            y: -208
            anchors.rightMargin: 5
            anchors.leftMargin: 5
            anchors.bottomMargin: 20
            anchors.topMargin: 20
            anchors.fill: parent
            model: handle.getLocals()
            focus: true
            highlight: Rectangle { color: Material.accent; radius: 5 }
            highlightMoveDuration: 500
            delegate:
                    Label {
                        text: modelData
                        color: Material.foreground
                        font.pixelSize: 20
                        anchors.topMargin: 5
                        MouseArea {
                                anchors.fill: parent
                                hoverEnabled: true
                                onEntered: {
                                    if(locals.clicker !== modelData)
                                        parent.color = Material.accent
                                }
                                onExited: {
                                        parent.color = Material.foreground
                                }
                                onClicked: {
                                    locals.currentIndex = index
                                    locals.clicker = modelData
                                    parent.color = Material.foreground
                                }
                      }
            }
        }
    }

    GroupBox {
        id: group3;
        width: 300
        anchors.top: parent.top
        anchors.topMargin: 70
        visible: false
        title: "System Keyboard layout"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        ListView {
            property string clicker: handle.getKeyMaps()[0];
            id: map
            x: -138
            y: -208
            anchors.rightMargin: 5
            anchors.leftMargin: 5
            anchors.bottomMargin: 20
            anchors.topMargin: 20
            anchors.fill: parent
            model: handle.getKeyMaps()
            focus: true
            highlight: Rectangle { color: Material.accent; radius: 5 }
            highlightMoveDuration: 500
            delegate:
                    Label {
                        text: modelData
                        color: Material.foreground
                        font.pixelSize: 20
                        anchors.topMargin: 5
                        MouseArea {
                                anchors.fill: parent
                                hoverEnabled: true
                                onEntered: {
                                    if(map.clicker !== modelData)
                                        parent.color = Material.accent
                                }
                                onExited: {
                                        parent.color = Material.foreground
                                }
                                onClicked: {
                                    map.currentIndex = index
                                    map.clicker = modelData
                                    parent.color = Material.foreground
                                }
                      }
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
        property int id: 0
        text: "Next"
        Material.background:  Material.accent
        anchors.rightMargin: 20
        anchors.bottomMargin: 20
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        function showDialog(){

            dialog.title="You forgot to fill in your fields"
            if(rootpwd.text !== rootpwdconfirm.text){
                dialog.title="You passwords don't match"
            }
            dialog.visible=true
        }

        onClicked: {
            if (id === 0){
                if(hostname.text !== "" && hostname.text !== " " && rootpwd.text === rootpwdconfirm.text && rootpwd.text!== " " && rootpwd.text!== " "){
                    group.visible= false
                    group2.visible = true
                }else{
                    showDialog()
                    id = -1
                }
            }else if (id == 1){
                group2.visible= false
                group3.visible = true
            }else{
             createSystem(locals.clicker, map.clicker, hostname.text, rootpwd.text);
             advance()
            }
            id++;
        }
    }

}

/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:9;anchors_height:500;anchors_width:100}
}
 ##^##*/
