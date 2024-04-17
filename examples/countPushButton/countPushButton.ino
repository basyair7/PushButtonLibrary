#include <pushbutton.h>

// create a object button
PushButtonAnalog analogButton(A0, INPUT);
PushButtonDigital digitalButton(2, INPUT_PULLUP);

// last millis variable
long lastTimeMillis = 0;
int digitalValue, analogValue;

void setup() {
    // initialize the button
    Serial.begin(9600);
    digitalButton.init();
    analogButton.init();
}

void loop() {
    // count push button
    if((unsigned long) (millis() - lastTimeMillis) >= 1000) {
        // get count if push button HIGH
        /*
        * count push button digital (available for digial pins)
        * delayPush = delay for push
        * delayReset = Automatic reset count after delay
        */
        digitalValue = digitalButton.countPushButton(200, 5000);
        /*
        * count push button no reset (available for digital pins)
        * value analog (please check in serial monitor before use this function)
        * delayPush = delay for push
        * unlimite (no self reset count)
        */

        // digitalValue = digitalButton.countPushNoReset(200);

        /*
        * count push button analog (available for analog pins)
        * value analog (please check in serial monitor before use this function)
        * delayPush = delay for push
        * delayReset = Automatic reset count after delay
        */
        int value = 500; // if 500 then push button analog HIGH
        analogValue = analogButton.countPushButton(value, 200, 5000);

        /*
        * count push button no reset (available for analog pins)
        * value analog (please check in serial monitor before use this function)
        * delayPush = delay for push
        * unlimite (no self reset count)
        */
        
        // analogValue = analogButton.countPushNoReset(value, 200);

        // display result
        Serial.print(F("Digital Value : "));
        Serial.println(digitalValue);
        Serial.print(F("Analog Value : "));
        Serial.println(analogValue);
        
        lastTimeMillis = millis();
    }
}
