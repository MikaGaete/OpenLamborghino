//
// Created by Mikael Gaete López on 1/10/2025.
//

#ifndef LAMBORGHINO_ENGINES_H
#define LAMBORGHINO_ENGINES_H

#include <Arduino.h>

#define AIN1 8    // left engine direction pin 1
#define AIN2 9    // left engine direction pin 2
#define PWMA 5    // left engine PWM pin
#define BIN1 4    // right engine direction pin 1
#define BIN2 7    // right engine direction pin 2
#define PWMB 6    // right engine PWM pin

void setupEngineController() {
    pinMode(AIN1, OUTPUT);
    pinMode(AIN2, OUTPUT);
    pinMode(PWMA, OUTPUT);
    pinMode(BIN1, OUTPUT);
    pinMode(BIN2, OUTPUT);
    pinMode(PWMB, OUTPUT);
}

void adjustLeftEngine(int value) {

    if (value >= 0) {
        digitalWrite(AIN1, HIGH);
        digitalWrite(AIN2, LOW);
    }
    else {
        digitalWrite(AIN1, LOW);
        digitalWrite(AIN2, HIGH);
        value *= -1;
    }

    analogWrite(PWMA, value);
}

void adjustRightEngine(int value) {
    if (value >= 0) {
        digitalWrite(BIN1, HIGH);
        digitalWrite(BIN2, LOW);
    }
    else {
        digitalWrite(BIN1, LOW);
        digitalWrite(BIN2, HIGH);
        value *= -1;
    }

    analogWrite(PWMB, value);
}

void adjustEngines(int left, int right) {
    adjustLeftEngine(left);
    adjustRightEngine(right);
}

#endif //LAMBORGHINO_ENGINES_H