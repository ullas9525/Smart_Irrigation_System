#include <SoftwareSerial.h>

int moisture = A0, relay = 6, red = 12, green = 11, sense, value = 800;
float percentage;
char Motor;
#define BT_RX_PIN 7 // Change these to match your Bluetooth module's RX pin
#define BT_TX_PIN 8 // Change these to match your Bluetooth module's TX pin
SoftwareSerial mySerial(BT_TX_PIN, BT_RX_PIN);

bool initialPrintDone = false; // Flag to check if initial print is done
bool moistureChanged = true; // Flag to track moisture value change
bool motorStateChanged = true; // Flag to track motor state change

int oldSensorValue = 0; // Declare oldSensorValue before loop

void setup() {
    pinMode(relay, OUTPUT);
    pinMode(moisture, INPUT);
    pinMode(red, OUTPUT);
    pinMode(green, OUTPUT);
    Serial.begin(9600);
    mySerial.begin(9600);
}

void printInitialSetup() {
    // Print initial parameters only once
    mySerial.print("Soil Moisture Percentage: ");
    mySerial.print(percentage);
    mySerial.println("%");
    mySerial.print("Motor is ");
    mySerial.print(Motor);
    initialPrintDone = true; // Set the flag to true after initial print
}

void loop() {
    if (!initialPrintDone) {
        printInitialSetup();
    }

    int newSense = analogRead(moisture);
    float newPercentage = map(newSense, 1023, 0, 0, 100);

    if (newSense != oldSensorValue) {
        moistureChanged = true;
    }
    if (Motor != (newSense > value ? 'ON' : 'OFF')) {
        motorStateChanged = true;
    }

    if (moistureChanged) {
        Serial.print("Soil Moisture Percentage: ");
        Serial.print(newPercentage);
        Serial.println("%");
        mySerial.print("Soil Moisture Percentage: ");
        mySerial.print(newPercentage);
        mySerial.println("%");
        moistureChanged = false;
        oldSensorValue = newSense;
    }

    if (motorStateChanged) {
        digitalWrite(red, newSense > value ? HIGH : LOW);
        digitalWrite(green, newSense > value ? LOW : HIGH);
        digitalWrite(relay, newSense > value ? HIGH : LOW);
        Motor = newSense > value ? 'ON' : 'OFF';
        mySerial.print("Motor is ");
        mySerial.println(Motor);
        motorStateChanged = false;
    }

    delay(500);
}
