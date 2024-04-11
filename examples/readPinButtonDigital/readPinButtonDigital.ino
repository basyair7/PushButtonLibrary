#include <pushbutton.h>

// create a object button
PushButtonDigital digitalButton(2, INPUT_PULLUP);

// last millis variable
long lastTimeMillis = 0;

void setup() {
    // initialize the button
    Serial.begin(9600);
    digitalButton.init();
}

void loop() {
    if((unsigned long) (millis() - lastTimeMillis) >= 1000) {
        lastTimeMillis = millis();
        int value = digitalButton.digitalReadPushButton();
        Serial.print(F("Value : "));
        Serial.println(value);
    }
}
