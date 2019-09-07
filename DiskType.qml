import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Imagine 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.13
Item {
    id: disktype
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.verticalCenter: parent.verticalCenter
    GroupBox {
        id: diskbox;
        title: "Install TOS"

        ColumnLayout {
            ExclusiveGroup { id: tabPositionGroup }
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
}
