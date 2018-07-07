//
// Created by chip on 19/06/18.
//

#include "GenerarPersonaje.h"

void GenerarPersonaje::CreateType(string type) {
    persona = Protagonista(100,10,10,10,1,type,0,100);
}

void GenerarPersonaje::GetType(int(&data)[7]) {
    persona.GetData(data);
}

void GenerarPersonaje::GetCarrera(string &carrera) {
    persona.GetCarrera(carrera);
}
