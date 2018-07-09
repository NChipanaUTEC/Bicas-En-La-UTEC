//
// Created by chip on 19/06/18.
//

#include "GenerarPersonaje.h"

void GenerarPersonaje::CreateType(string type) {
    Carrera = type;
    persona = Protagonista(100,10,10,10,1,type,0,100);
}

void GenerarPersonaje::GetDataProta(int(&data)[7]) {
    persona.GetData(data);
}

void GenerarPersonaje::GetDataEnem(int (&data)[5]) {
    enemigo.GetData(data);
}

void GenerarPersonaje::GetCarrera(string &carrera) {
    persona.GetCarrera(carrera);
}

void GenerarPersonaje::CreateEnemy() {
    enemigo = Enemigo(50,5,5,5,1);
}

void GenerarPersonaje::UpdateEnemy() {
    int data[7];
    persona.GetData(data);
    enemigo = Enemigo(50*data[0]/100,10*data[1]/10,10*data[2]/10,10*data[3]/10,1);
}


void GenerarPersonaje::LVLPersonaje() {
    ++persona;
}

void GenerarPersonaje::UpdatePersonaje(int (& data)[7]) {
    persona = Protagonista(data[0],data[1],data[2],data[3],data[4],Carrera,data[5],data[6]);
}
