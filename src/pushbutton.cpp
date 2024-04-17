#include "Arduino.h"
#include "pushbutton.h"

PushButtonDigital::PushButtonDigital(uint8_t pin, uint8_t mode)
{
    pinInit = pin;
    modeInit = mode;
}

PushButtonAnalog::PushButtonAnalog(uint8_t pin, uint8_t mode)
{
    pinInit = pin;
    modeInit = mode;
}

void pushbutton::init()
{
    pinMode(pinInit, modeInit);
}

/*
 * count push button digital (available for digial pins)
 * delayPush = delay for push
 * delayReset = Automatic reset count after delay
 */
uint8_t PushButtonDigital::countPushButton(long delayPush, long delayReset)
{
    uint8_t buttonState = digitalRead(pinInit);
    if ((unsigned long)(millis() - lastTimePush) >= delayPush && buttonState == HIGH)
    {
        lastTimePush = millis();
        count++;
    }
    if ((unsigned long)(millis() - lastTimeReset) >= delayReset && buttonState == LOW)
    {
        lastTimeReset = millis();
        count = 0;
    }

    return count;
}

/*
 * count push button no reset (available for digital pins)
 * delayPush = delay for push
 * unlimite (no self reset count)
*/
int PushButtonDigital::countPushNoReset(long delayPush) {
    uint8_t buttonState = digitalRead(pinInit);
    if((unsigned long) (millis() - lastTimePush) >= delayPush && buttonState == HIGH) {
        lastTimePush = millis();
        countUnlimite++;
    } 
    return countUnlimite;
}

/*
 * count push button analog (available for analog pins)
 * value analog (please check in serial monitor before use this function)
 * delayPush = delay for push
 * delayReset = Automatic reset count after delay
 */
uint8_t PushButtonAnalog::countPushButton(uint16_t valueAnalog, long delayPush, long delayReset)
{
    uint16_t buttonValue = analogRead(pinInit);
    if ((unsigned long)(millis() - lastTimePush) >= delayPush && buttonValue == valueAnalog)
    {
        lastTimePush = millis();
        count++;
    }
    if ((unsigned long)(millis() - lastTimeReset) >= delayReset && buttonValue != valueAnalog)
    {
        lastTimeReset = millis();
        count = 0;
    }

    return count;
}

/*
 * count push button no reset (available for digital pins)
 * value analog (please check in serial monitor before use this function)
 * delayPush = delay for push
 * unlimite (no self reset count)
*/
int PushButtonAnalog::countPushNoReset(uint16_t valueAnalog, long delayPush) {
    uint16_t buttonValue = analogRead(pinInit);
    if((unsigned long) (millis() - lastTimePush) >= delayPush && buttonValue == valueAnalog) {
        lastTimePush = millis();
        countUnlimite++;
    } 
    return countUnlimite;
}

void PushButtonDigital::resetCount()
{
    count = 0;
    countUnlimite = 0;
}

void PushButtonAnalog::resetCount()
{
    count = 0;
    countUnlimite = 0;
}

uint8_t PushButtonDigital::digitalReadPushButton()
{
    uint8_t state = digitalRead(pinInit);
    return state;
}

uint16_t PushButtonAnalog::analogReadPushButton()
{
    uint16_t state = analogRead(pinInit);
    return state;
}