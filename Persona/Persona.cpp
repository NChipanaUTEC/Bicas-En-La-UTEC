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
}
