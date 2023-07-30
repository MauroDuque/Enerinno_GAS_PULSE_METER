#include <Arduino.h>

const int buttonPin = 15; // Pin where the button is connected
int previousState = LOW;
int counter = 0;
int buttonState = LOW;
unsigned long debounceDelay = 50; // Adjust this value as needed

int get_pulse_gas() {
    return buttonState;
}

int get_counter_gas() {
    return counter;
}

void setup_gas() {
    pinMode(buttonPin, INPUT);
}

void loop_gas() {
    int reading = digitalRead(buttonPin); // Read the current state of the button

    // Apply debounce logic
    if (reading != previousState) {
        unsigned long debounceTime = millis();
        while ((millis() - debounceTime) < debounceDelay) {
            reading = digitalRead(buttonPin);
        }
    }

    if (reading != buttonState) {
        buttonState = reading;
        if (buttonState == HIGH) {
            counter++;
        }
    }

    previousState = reading;
}
