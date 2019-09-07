import QtQuick 2.12
import QtQuick.Window 2.12
import QtQml.Models 2.12
import QtQuick.Controls.Imagine 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.13
import QtQuick.Controls.Material 2.12
import tos 1.0

Window {
    visible: true
    width: 1080
    height: 720
    title: qsTr("Hello World")
    Material.theme: Material.Dark
    Material.accent: Material.Purple
    color: Material.backgroundColor

    Yaml {
        id: yaml
    }

    TabBar {
        id: bar
        width: parent.width
        TabButton {
            text: qsTr("Disk select")
        }
        TabButton {
            text: qsTr("User")
        }
        TabButton {
            text: qsTr("Locals")
        }
        TabButton {
            text: qsTr("Installing")
        }
        TabButton {
            text: qsTr("Finished")
            onClicked: {
                yaml.setNetwork("hello", "hi")
                yaml.setSystem("en_US.UTF-8", "be-latin1", "123", "tos")
                yaml.setUser("alpha", "123")
                yaml.addPartition(0, "boot", "/boot", "ext4", "1MiB", "200MiB");
                yaml.addPartition(0, "offset", "/usr", "ext4", "97%", "100%", 5);
                yaml.addResizePartition(0, "test", "/test", "ext4", "100GB");

                yaml.addLogicVolume(0, "root", "200GB", "/");
                yaml.addLogicVolume(0, "home", "200GB", "/home");
                yaml.addEncryptionPartition(0,0, "abc", "root", "/", "200MiB", "100%");


                yaml.addDisk("/dev/sda", "499G", true, false, 0);
                yaml.addDisk("/dev/sdb", "499G", true, false, 0);
                console.log(yaml.getConfig())
                //console.log(yaml.execute("run.sh"))
            }
        }
    }

    StackLayout {
        width: parent.width
        height: parent.height
        currentIndex: bar.currentIndex
        Item {
            id: selectTab
        }
        Item {
            id: userTab
        }
        Item {
            id: localsTab
        }
        Installing {
            id: installTab
            function test(param){
                console.log("testing " + param);
            }
        }

        Final {
            id: finishedTab
        }
    }

}
