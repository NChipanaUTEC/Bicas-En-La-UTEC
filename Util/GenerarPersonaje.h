//
// Created by chip on 19/06/18.
//

#ifndef BICASENLAUTEC_GENERARPERSONAJE_H
#define BICASENLAUTEC_GENERARPERSONAJE_H

#include "../Persona/Persona.h"


class GenerarPersonaje {
    Protagonista& persona;
    Enemigo& enemigo;
    string Carrera;
public:
    GenerarPersonaje(Protagonista& persona, Enemigo& enemigo): persona(persona),enemigo(enemigo) {}
    void CreateType(string type);
    void CreateEnemy();
    void UpdateEnemy();
    void LVLPersonaje();
    void UpdatePersonaje(int(&data)[7]);;
    void GetDataProta (int(&data)[7]);
    void GetDataEnem (int(&data)[5]);
    void GetCarrera(string& carrera);
};
#endif //BICASENLAUTEC_GENERARPERSONAJE_H
