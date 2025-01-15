#include <Arduino.h>
#include <Engines.h>
#include <FrontSensors.h>
#include "AngularControl.h"

int base = 0;
float Kprop = 1.2;
float Kderiv = 7.5;
float Kinte = 0.0;

void start() {
    while (!digitalRead(buttonPin));
    tone(buzzerPin, 2000, 100);
}

void setup() {
    Serial.begin(9600);
    Serial.println("Init...");

    pinMode(13, OUTPUT);
    digitalWrite(13, LOW);
    //adjustEngines(0, 0);

    start();

    digitalWrite(13, HIGH);
    setupPeripherals();
    beep();

    delay(1000);

    calibration();
    digitalWrite(13, LOW);
    tone(buzzerPin, 1500, 50);

    delay(70);

    tone(buzzerPin, 1500, 50);

    delay(70);

    start();

    delay(1000);

    digitalWrite(13, HIGH);
}

void loop() {
    int line_position = getPositions();
    int Correction_power = PIDLambo(line_position, Kprop, Kderiv, Kinte);
    adjustEngines(base + Correction_power, base + -Correction_power);

    Serial.print(line_position);
    Serial.print("\t");
    Serial.println(Correction_power);
}