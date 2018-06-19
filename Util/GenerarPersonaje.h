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

    void updateType(string type) {
     /*  if(persona.CARRERA != "")
           ++ persona;
       else
       */
     persona = Protagonista(100,10,10,10,10,type);
    }
};
#endif //BICASENLAUTEC_GENERARPERSONAJE_H
