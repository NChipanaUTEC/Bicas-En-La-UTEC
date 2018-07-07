//
// Created by chip on 19/06/18.
//

#ifndef BICASENLAUTEC_GENERARPERSONAJE_H
#define BICASENLAUTEC_GENERARPERSONAJE_H

#include "../Persona/Persona.h"


class GenerarPersonaje {
    Protagonista& persona;
public:
    GenerarPersonaje(Protagonista& persona): persona(persona) {}
    void CreateType(string type);
    void GetType (int(&data)[7]);
    void GetCarrera(string& carrera);
};
#endif //BICASENLAUTEC_GENERARPERSONAJE_H
