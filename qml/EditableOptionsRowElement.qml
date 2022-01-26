import Felgo 3.0
import QtQuick 2.0

Item {
    property var fieldName: "temp name"
    property var fieldValue: 0.0

    width: 800
    height: 100

    Row {
        id: simpleRow
        width: 800
        height: 100

        AppText {
            id: maxSpeedTextField
            width: 400
            height: 100
            text: fieldName
            font.pointSize: 14
        }

        Rectangle {
            id:rectangleFill
            width: 400
            height: 100
            color: "#00000000"
            border.color: "#a6a6a6"

            AppTextEdit {
                id: optionTextEdit
                text: fieldValue
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
            }
        }
    }
}


