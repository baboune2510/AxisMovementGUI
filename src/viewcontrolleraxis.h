#ifndef VIEWCONTROLLERAXIS_H
#define VIEWCONTROLLERAXIS_H

#include <QObject>
#include <QDebug>
#include <QVariant>
#include <QQmlListProperty>
#include "simulatedaxis.h"

class ViewControllerAxis : public QObject
{
    Q_OBJECT
public:
    explicit ViewControllerAxis(QObject *parent = nullptr);

    Q_PROPERTY(SimulatedAxis* model READ model WRITE setmodel)
    Q_PROPERTY(QQmlListProperty<QQmlListProperty<QVariant>> paramList READ paramList WRITE setparamList)

    SimulatedAxis* model() const
    {
        return m_model;
    }

    QQmlListProperty<QQmlListProperty<QVariant>> paramList() const
    {
        return m_paramList;
    }

signals:

public slots:
    void setmodel(SimulatedAxis* model);

    void setparamList(QQmlListProperty<QQmlListProperty<QVariant>> paramList)
    {
        m_paramList = paramList;
    }

private:
    SimulatedAxis* m_model;
    QQmlListProperty<QQmlListProperty<QVariant>> m_paramList;
};

#endif // VIEWCONTROLLERAXIS_H
