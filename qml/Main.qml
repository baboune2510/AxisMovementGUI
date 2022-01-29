import Felgo 3.0
import QtQuick 2.0
import com.PEB.SimulatedAxis 1.0
import com.PEB.ViewControllerAxis 1.0

App {

    /*
    Rectangle{
        x: 0
        y: 44
        width: 800
        height: 1000
        color: "#2f2e2e"
        Column {
            id: columnOptions
            anchors.fill: parent

            EditableOptionsRowElement{
                fieldName: "Maximum speed"
                fieldValue: xAxis.maxSpeed.toFixed(1)
            }

            EditableOptionsRowElement{
                fieldName: "Minimum position"
                fieldValue: xAxis.minPos.toFixed(1)
            }

            EditableOptionsRowElement{
                fieldName: "Maximum position"
                fieldValue: xAxis.maxPos.toFixed(1)
            }

            EditableOptionsRowElement{
                fieldName: "Acceleration"
                fieldValue: xAxis.acceleration.toFixed(1)
            }

            EditableOptionsRowElement{
                fieldName: "Jerk"
                fieldValue: xAxis.jerk.toFixed(1)
            }

            EditableOptionsRowElement{
                fieldName: "Current Position"
                fieldValue: xAxis.currentPosition.toFixed(1)
            }

            EditableOptionsRowElement{
                fieldName: "Current Speed"
                fieldValue: xAxis.currentSpeed.toFixed(1)
            }

            EditableOptionsRowElement{
                fieldName: "Busy"
                fieldValue: xAxis.busy.toFixed(1)
            }
        }
    }
*/

    Rectangle{
        x: 0
        y: 44
        width: 800
        height: 1000
        color: "#2f2e2e"
        Column {
            id: columnOptions2
            spacing: 10
            anchors.fill: parent

            Repeater{
                model : [
                    [qsTr("Maximum speed"), xAxis.maxSpeed.toFixed(1), true],
                    [qsTr("Minimum position"), xAxis.minPos.toFixed(1), true],
                    [qsTr("Maximum position"), xAxis.maxPos.toFixed(1), true],
                    [qsTr("Acceleration"), xAxis.acceleration.toFixed(1), true],
                    [qsTr("Jerk"), xAxis.jerk.toFixed(1), true],
                    [qsTr("Current Position"), xAxis.currentPosition.toFixed(1), false],
                    [qsTr("Current Speed"), xAxis.currentSpeed.toFixed(1), false],
                    [qsTr("Busy"), xAxis.busy, false]
                ]
                EditableOptionsRowElement
                {
                    fieldName: modelData[0]
                    fieldValue: modelData[1]
                    editableField: modelData[2]
                }
            }
        }
    }

    SimulatedAxis{
        id: xAxis
    }

    ViewControllerAxis{
        id: xAxisViewController
        model: xAxis
    }
}
