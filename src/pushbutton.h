// Push Button Library
// Copyright © 2024, Basyair Fathul
// MIT License

#pragma once

#ifndef pushbutton_h

#include <Arduino.h>

class variable {
    protected:
        uint8_t pinInit, modeInit;
        unsigned long lastTimePush = 0, lastTimeReset = 0;
};

class pushbutton {
    public:
        void init();
};

class PushButtonDigital: public pushbutton, protected variable {
    private:
        uint8_t count;
        int countUnlimite;

    public:
        PushButtonDigital(uint8_t pin, uint8_t mode);
        uint8_t countPushButton(long delayPush, long delayReset);
        int countPushNoReset(long delayPush);
        uint8_t digitalReadPushButton();
        void resetCount();
};

class PushButtonAnalog: public pushbutton, protected variable {
    private:
        uint8_t count;
        int countUnlimite;
        
    public:
        PushButtonAnalog(uint8_t pin, uint8_t mode);
        uint8_t countPushButton(uint16_t valueAnalog, long delayPush, long delayReset);
        int countPushNoReset(uint16_t valueAnalog, long delayPush);
        uint16_t analogReadPushButton();
        void resetCount();
};

#endif