#include "simulatedaxis.h"

SimulatedAxis::SimulatedAxis(QObject *parent)
    : QObject{parent}
{
    setMaxSpeed(100.0f);
    setMinPos(0.0f);
    setMaxPos(200.0f);
    setAcceleration(50.0f);
    setJerk(100.0f);
    setCurrentPosition(24.2f);
    setCurrentSpeed(0.0f);
    setBusy(false);

    targetPosition = currentPosition();
    targetSpeed = 0.0f;
    targetAccelleration = 0.0f;
    targetJerk = 0.0f;
}

float SimulatedAxis::maxSpeed() const
{
    return m_maxSpeed;
}

void SimulatedAxis::setMaxSpeed(float newMaxSpeed)
{
    if (qFuzzyCompare(m_maxSpeed, newMaxSpeed))
        return;
    m_maxSpeed = newMaxSpeed;
    emit maxSpeedChanged();
}

float SimulatedAxis::minPos() const
{
    return m_minPos;
}

void SimulatedAxis::setMinPos(float newMinPos)
{
    if (qFuzzyCompare(m_minPos, newMinPos))
        return;
    m_minPos = newMinPos;
    emit minPosChanged();
}

float SimulatedAxis::maxPos() const
{
    return m_maxPos;
}

void SimulatedAxis::setMaxPos(float newMaxPos)
{
    if (qFuzzyCompare(m_maxPos, newMaxPos))
        return;
    m_maxPos = newMaxPos;
    emit maxPosChanged();
}

float SimulatedAxis::acceleration() const
{
    return m_acceleration;
}

void SimulatedAxis::setAcceleration(float newAcceleration)
{
    if (qFuzzyCompare(m_acceleration, newAcceleration))
        return;
    m_acceleration = newAcceleration;
    emit accelerationChanged();
}

float SimulatedAxis::jerk() const
{
    return m_jerk;
}

void SimulatedAxis::setJerk(float newJerk)
{
    if (qFuzzyCompare(m_jerk, newJerk))
        return;
    m_jerk = newJerk;
    emit jerkChanged();
}

float SimulatedAxis::currentSpeed() const
{
    return m_currentSpeed;
}

void SimulatedAxis::setCurrentSpeed(float newCurrentSpeed)
{
    if (qFuzzyCompare(m_currentSpeed, newCurrentSpeed))
        return;
    m_currentSpeed = newCurrentSpeed;
    emit currentSpeedChanged();
}

bool SimulatedAxis::busy() const
{
    return m_busy;
}

void SimulatedAxis::setBusy(bool newBusy)
{
    if (m_busy == newBusy)
        return;
    m_busy = newBusy;
    emit busyChanged();
}

float SimulatedAxis::currentPosition() const
{
    return m_currentPosition;
}

void SimulatedAxis::setCurrentPosition(float newCurrentPosition)
{
    if (qFuzzyCompare(m_currentPosition, newCurrentPosition))
        return;
    m_currentPosition = newCurrentPosition;
    emit currentPositionChanged();
}

void SimulatedAxis::homing()
{
    qDebug() << "homing sequence...";
}

void SimulatedAxis::halt()
{
    targetSpeed = 0.0f;
}

void SimulatedAxis::reset()
{
    qDebug() << "Reset";
}

void SimulatedAxis::goTo(float position, float speed)
{
    float positionClamp = position;
    if(position > maxPos()) positionClamp = maxPos();
    if(position < minPos()) positionClamp = minPos();
    targetPosition = positionClamp;
    targetSpeed = (speed > maxSpeed() ? maxSpeed() : speed);
    if(targetPosition < currentPosition()) targetSpeed = -targetSpeed;
}

void SimulatedAxis::cycle()
{
    float tick = 1.0f/1000.0f;

    setCurrentPosition(currentPosition() + currentSpeed() * tick);
    setCurrentSpeed(currentSpeed() + currentAccelleration * tick);
    currentAccelleration += currentJerk * tick;
}

