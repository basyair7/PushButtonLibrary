#include <pushbutton.h>

// create a object button
PushButtonAnalog analogButton(A0, INPUT);
PushButtonDigital digitalButton(2, INPUT_PULLUP);

// last millis variable
long lastTimeMillis = 0;
uint8_t digitalValue, analogValue;

void setup() {
    // initialize the button
    Serial.begin(9600);
    analogButton.init();
}

void loop() {
    // count push button
    if((unsigned long) (millis() - lastTimeMillis) >= 1000) {
        // get count if push button HIGH
        digitalValue = digitalButton.countPushButton(200, 5000);
        analogValue = analogButton.countPushButton(200, 5000);
        
        // display result
        Serial.print(F("Digital Value : "));
        Serial.println(digitalValue);
        Serial.print(F("Analog Value : "));
        Serial.println(analogValue);
        
        lastTimeMillis = millis();
    }
}
