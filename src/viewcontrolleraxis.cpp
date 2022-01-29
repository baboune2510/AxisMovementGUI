#include "viewcontrolleraxis.h"

ViewControllerAxis::ViewControllerAxis(QObject *parent)
    : QObject{parent}
{

}

void ViewControllerAxis::setmodel(SimulatedAxis *model)
{
    if (m_model == model)
        return;

    m_model = model;

    if(model != nullptr)
    {
        QQmlListProperty<QQmlListProperty<QVariant>> list;

        //QQmlListProperty<QVariant> test = { QVariant(7), QVariant(7), QVariant(7), QVariant(7)};
        //list.append(QQmlListProperty<QVariant>(QString("Maximum speed"), 100.0, true) );




        //this->setparamList()

    }

    /*
    [
    [qsTr("Maximum speed"), xAxis.maxSpeed.toFixed(1), true],
            [qsTr("Minimum position"), xAxis.minPos.toFixed(1), true],
            [qsTr("Maximum position"), xAxis.maxPos.toFixed(1), true],
            [qsTr("Acceleration"), xAxis.acceleration.toFixed(1), true],
            [qsTr("Jerk"), xAxis.jerk.toFixed(1), true],
            [qsTr("Current Position"), xAxis.currentPosition.toFixed(1), false],
            [qsTr("Current Speed"), xAxis.currentSpeed.toFixed(1), false],
            [qsTr("Busy"), xAxis.busy, false]
            ]*/
}
