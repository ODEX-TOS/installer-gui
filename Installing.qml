import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Imagine 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.13
Item {
    id: installTab
    property int id: 1
    property int prev_id: 0
    property int state: 1

    function setImage(image) {
        view.source = image;
    }

    function setImageOld(image) {
        old.source = image;
    }

    function next() {
        let images = ["pictures/TOS-installer/TOS-installer-1.jpg", "pictures/random1.jpg",
                      "pictures/TOS-installer/TOS-installer-2.jpg", "pictures/random2.jpg",
                      "pictures/TOS-installer/TOS-installer-3.jpg", "pictures/random3.jpg",
                      "pictures/TOS-installer/TOS-installer-4.jpg", "pictures/random4.jpg",
                      "pictures/TOS-installer/TOS-installer-5.jpg", "pictures/random5.jpg",
                      "pictures/TOS-installer/TOS-installer-6.jpg", "pictures/ThankYou.jpg",
                      "pictures/TOS-installer/TOS-installer-7.jpg", "pictures/random1.jpg",
                      "pictures/TOS-installer/TOS-installer-8.jpg", "pictures/random2.jpg",
                      "pictures/TOS-installer/TOS-installer-9.jpg", "pictures/ThankYou.jpg"];
            // TODO: qt doesn't support array.lenght yet, implement if exists
            if(id==9)
                id=0;
            if (view.state == "off"){
                view.state="on";
            }
            setImage(images[id]);
            prev_id = id;
            id++;
            console.log("Next picture");
            test("Parameter");
    }

    function stateoff(){
        let images = ["pictures/TOS-installer/TOS-installer-1.jpg", "pictures/random1.jpg",
                      "pictures/TOS-installer/TOS-installer-2.jpg", "pictures/random2.jpg",
                      "pictures/TOS-installer/TOS-installer-3.jpg", "pictures/random3.jpg",
                      "pictures/TOS-installer/TOS-installer-4.jpg", "pictures/random4.jpg",
                      "pictures/TOS-installer/TOS-installer-5.jpg", "pictures/random5.jpg",
                      "pictures/TOS-installer/TOS-installer-6.jpg", "pictures/ThankYou.jpg",
                      "pictures/TOS-installer/TOS-installer-7.jpg", "pictures/random1.jpg",
                      "pictures/TOS-installer/TOS-installer-8.jpg", "pictures/random2.jpg",
                      "pictures/TOS-installer/TOS-installer-9.jpg", "pictures/ThankYou.jpg"];
        ++state;
        if(state == timer.interval/smooth.interval){
            state=0;
            view.state="off"
            setImageOld(images[prev_id]);
        }
    }

    Timer {
        id: timer
        interval: 10000; running: true; repeat: true
        onTriggered: next();
    }
    // interval must be be a subset of timer eg 10000/2000=5 is allowed
    // 11000/2000 is not a integer
    Timer {
        id: smooth
        interval: 2000; running: true; repeat: true
        onTriggered: stateoff();
    }
    Image {
        id: old
        anchors.topMargin: 50
        anchors.bottomMargin: 30
        anchors.leftMargin: 30
        anchors.rightMargin: 30
        anchors.fill: parent
        //fillMode: Image.PreserveAspectFit
        source: "pictures/slide2.png"
        opacity: 1
        visible: true
    }


    Image {
        id: view
        anchors.topMargin: 50
        anchors.bottomMargin: 30
        anchors.leftMargin: 30
        anchors.rightMargin: 30
        anchors.fill: parent
        //fillMode: Image.PreserveAspectFit
        source: "pictures/slide1.png"
        visible: true
        smooth: true
        opacity: 1
        state: "on"
        states: [
            State {
                name: "on";
                PropertyChanges { target: view; opacity: 1}
            },
            State {
                name: "off";
                PropertyChanges { target: view; opacity: 0}
            }
        ]

        transitions: Transition {
                NumberAnimation { properties: "opacity"; easing.type: Easing.InOutQuad; duration: 2000; }
        }
    }


    ProgressBar {
        height: 30
        anchors.topMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.bottom: parent.bottom
        indeterminate: true
    }
}

























/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
