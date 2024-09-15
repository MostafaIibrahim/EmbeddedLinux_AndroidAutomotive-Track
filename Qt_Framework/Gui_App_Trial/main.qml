import QtQuick
// import QtQuick.Window 2.15
// import QtQuick.Controls
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Image{
        id: name
        source: "file:://home/mostafa/Downloads/WhatsApp Image 2024-07-08 at 1.22.12 PM.jpeg"
        width: parent.width
    }
    // Rectangle{
    //     width: id.width
    // }
}
