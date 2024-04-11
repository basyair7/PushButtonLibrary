#include <pushbutton.h>

// create a object button
PushButtonAnalog analogButton(A0, INPUT);

// last millis variable
long lastTimeMillis = 0;

void setup() {
    // initialize the button
    Serial.begin(9600);
    analogButton.init();
}

void loop() {
    if((unsigned long) (millis() - lastTimeMillis) >= 1000) {
        lastTimeMillis = millis();
        int value = analogButton.analogReadPushButton();
        Serial.print(F("Value : "));
        Serial.println(value);
    }
}
