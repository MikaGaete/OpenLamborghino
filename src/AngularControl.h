//
// Created by mikag on 1/15/2025.
//

#ifndef LAMBORGHINO_ANGULARCONTROL_H
#define LAMBORGHINO_ANGULARCONTROL_H

int setpoint = 0;
int last_error = 0;
int pot_limite = 250;

int PIDLambo(int pos, float Kp, float Kd, float Ki) {
    int error = pos - setpoint;
    int derivative = error - last_error;
    last_error = error;
    int pot_giro = (error * Kp + derivative * Kd);

    if (pot_giro > pot_limite) {
        pot_giro = pot_limite;
    }
    else if (pot_giro <- pot_limite) {
        pot_giro = -pot_limite;
    }

    return pot_giro;
}

#endif //LAMBORGHINO_ANGULARCONTROL_H
