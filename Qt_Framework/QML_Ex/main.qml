import QtQuick
import QtQuick.Window
import QtQuick.Controls
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello bro")
    Column{
        spacing:10
        Image {
            id: iti
            source: "file:///home/mostafa/Desktop/ITI_Docs/AdminLinux_Lab/Embedded-LinuxI/iti_logo.5b9a0fd125be-300x133.png"
            width: 250
            height: 150
            fillMode:Image.PreserveAspectFit
        }

    }
    Text{
        text: qsTr("Hey My Friend!!")
        font.bold: true
        font.pixelSize: 20
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 100
    }


    Column{
        anchors.centerIn: parent
        spacing:10


        TextField{
            id: usrInput
            placeholderText: "Please Enter Usrname"
            // anchors.horizontalCenter: parent.horizontalCenter
            // anchors.verticalCenter: parent.verticalCenter
            height: 40
            width:200
        }
        Button{
            text: "Click Me,bitte!"
            width: 150
            height: 30
            // anchors.horizontalCenter: parent.horizontalCenter
            // anchors.verticalCenter: parent.verticalCenter

            onClicked:{
                if(usrInput.text === "mostafa"){
                    mostafa.source = "file:///home/mostafa/Downloads/Hey.jpeg"
                }else{
                    mostafa.visible = false
                }
            }
        }
        Image {
            id: mostafa

            width: 100
            height: 150
            fillMode:Image.PreserveAspectFit
        }
    }
    // function check(){

    // }

}
