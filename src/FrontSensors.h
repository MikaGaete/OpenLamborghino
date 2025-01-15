//
// Created by Mikael Gaete López on 1/10/2025.
//

#ifndef LAMBORGHINO_FRONTSENSORS_H
#define LAMBORGHINO_FRONTSENSORS_H

#include <Arduino.h>

#define buzzerPin 10
#define buttonPin 2

typedef struct {
    int HL, HR;
    int s[6];
} FrontSensorArray;

FrontSensorArray sensors;
int v_s_min[6] = {0, 0, 0, 0, 0, 0};
int v_s_max[6] = {1023, 1023, 1023, 1023, 1023, 1023};
volatile int s_p[6];
boolean online;
int position, lPosition;

void setupPeripherals() {
    pinMode(buttonPin, INPUT);
    pinMode(buzzerPin, OUTPUT);
}

void beep() {
    tone(buzzerPin, 2000, 100);
    delay(200);
}

void readFrontSensors() {
    sensors.HL = analogRead(A7);
    sensors.s[0] = analogRead(A6);
    sensors.s[1] = analogRead(A5);
    sensors.s[2] = analogRead(A4);
    sensors.s[3] = analogRead(A3);
    sensors.s[4] = analogRead(A2);
    sensors.s[5] = analogRead(A1);
    sensors.HR = analogRead(A0);

    for (int i = 0; i < 6; i++) {
        if (sensors.s[i] < v_s_min[i]) {
            sensors.s[i] = v_s_min[i];
        }

        if (sensors.s[i] > v_s_max[i]) {
            sensors.s[i] = v_s_max[i];
        }
        s_p[i] = map(sensors.s[i], v_s_min[i], v_s_max[i], 100, 0);
    }

    volatile int sum = s_p[0] + s_p[1] + s_p[2] + s_p[3] + s_p[4] + s_p[5];

    if (sum > 100) {
        online = true;

    }
    else {
        online = false;
        sum = 100;
    }
}

void calibration() {
    int v_s[6];

    for (int j = 0; j < 100; j++) {
        delay(10);
        v_s[0] = analogRead(A6);
        v_s[1] = analogRead(A5);
        v_s[2] = analogRead(A4);
        v_s[3] = analogRead(A3);
        v_s[4] = analogRead(A2);
        v_s[5] = analogRead(A1);

        for (int i : v_s) {
            Serial.print(i);
            Serial.print("\t");
        }

        Serial.println();

        for (int i = 0; i < 6; i++) {
            if (v_s[i] < v_s_min[i]) {
                v_s_min[i] = v_s[i];
            }
        }


        for (int i = 0; i < 6; i++) {
            if (v_s[i] > v_s_max[i]) {
                v_s_max[i] = v_s[i];
            }
        }
    }

    beep();
    beep();

    Serial.println();
    Serial.print("Mínimos \t");

    for (int i : v_s_min) {
        Serial.print(i);
        Serial.print("\t");

    }

    Serial.println();
    Serial.print("Máximos \t");

    for (int i : v_s_max) {
        Serial.print(i);
        Serial.print("\t");
    }

    Serial.println();
}

int getPositions() {
    readFrontSensors();
    int prom = -2.5 * s_p[0] - 1.5 * s_p[1] - 0.5 * s_p[2] + 0.5 * s_p[3] + 1.5 * s_p[4] + 2.5 * s_p[5];
    int sum = s_p[0] + s_p[1] + s_p[2] + s_p[3] + s_p[4] + s_p[5];

    if (online) {
        position = int(100.0 * prom / sum);
    }
    else {
        if (lPosition < 0) {
            position = -255;
        }
        if (lPosition >= 0) {
            position = 255;
        }
    }

    lPosition = position;

    return position;
}

#endif //LAMBORGHINO_FRONTSENSORS_H
