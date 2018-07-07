//
// Created by chip on 13/06/18.
//

#include "Persona.h"


void Protagonista::operator++() {
    HP += 10;
    ATK += 10;
    DEF += 10;
    SPD += 10;
    LVL += 1;
    ActualXP = 0;
    MaxXP *= 1.1;
}

void Protagonista::GetData (int(&data)[7]) {
    data[0] = HP;
    data[1] = ATK;
    data[2] = DEF;
    data[3] = SPD;
    data[4] = LVL;
    data[5] = ActualXP;
    data[6] = MaxXP;
}

void Protagonista::GetCarrera(string &carrera) {
    carrera = CARRERA;
}
