#ifndef SIMULATEDAXIS_H
#define SIMULATEDAXIS_H

#include <QObject>
#include <QDebug>

class SimulatedAxis : public QObject
{
    Q_OBJECT
    float m_maxSpeed;
    float m_minPos;
    float m_maxPos;
    float m_acceleration;
    float m_jerk;
    float m_currentSpeed;
    bool m_busy;
    float m_currentPosition;

public:
    explicit SimulatedAxis(QObject *parent = nullptr);
    Q_PROPERTY(float maxSpeed READ maxSpeed WRITE setMaxSpeed NOTIFY maxSpeedChanged)
    Q_PROPERTY(float minPos READ minPos WRITE setMinPos NOTIFY minPosChanged)
    Q_PROPERTY(float maxPos READ maxPos WRITE setMaxPos NOTIFY maxPosChanged)
    Q_PROPERTY(float acceleration READ acceleration WRITE setAcceleration NOTIFY accelerationChanged)
    Q_PROPERTY(float jerk READ jerk WRITE setJerk NOTIFY jerkChanged)
    Q_PROPERTY(float currentPosition READ currentPosition WRITE setCurrentPosition NOTIFY currentPositionChanged)
    Q_PROPERTY(float currentSpeed READ currentSpeed WRITE setCurrentSpeed NOTIFY currentSpeedChanged)
    Q_PROPERTY(bool busy READ busy WRITE setBusy NOTIFY busyChanged)

    float maxSpeed() const;
    float minPos() const;
    float maxPos() const;
    float acceleration() const;
    float jerk() const;
    float currentPosition() const;
    float currentSpeed() const;
    bool busy() const;

signals:
    void maxSpeedChanged();
    void minPosChanged();
    void maxPosChanged();
    void accelerationChanged();
    void jerkChanged();
    void currentPositionChanged();
    void currentSpeedChanged();
    void busyChanged();

public slots:
    void setMaxSpeed(float newMaxSpeed);
    void setMinPos(float newMinPos);
    void setMaxPos(float newMaxPos);
    void setAcceleration(float newAcceleration);
    void setJerk(float newJerk);

    void homing();
    void halt();
    void reset();
    void goTo(float position, float speed = 0.0);

    void cycle();

private slots:
    void setCurrentPosition(float newCurrentPosition);
    void setCurrentSpeed(float newCurrentSpeed);
    void setBusy(bool newBusy);

private:
    float targetPosition;
    float targetSpeed;
    float targetAccelleration;
    float targetJerk;
    float currentAccelleration = 0.0;
    float currentJerk = 0.0;
};

#endif // SIMULATEDAXIS_H
