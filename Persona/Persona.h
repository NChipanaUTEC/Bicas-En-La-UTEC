//
// Created by chip on 13/06/18.
//

#ifndef BICASENLAUTEC_PERSONAJE_H
#define BICASENLAUTEC_PERSONAJE_H

#include <string>
using namespace std;

class Persona {
    int HP;
    int ATK;
    int DEF;
    int SPD;
    int LVL;
public:
    Persona(const int &HP,const int &ATK,const int &DEF, const int &LVL,const int &SPD): HP(0), ATK(0), DEF(0),SPD(0),LVL(0){}
};

class Protagonista: Persona{
    string CARRERA;
public:
    Protagonista(const int &HP,const int &ATK,const int &DEF, const int &LVL,const int &SPD, string CARRERA):
            Persona(HP,ATK,DEF,LVL,SPD),CARRERA(CARRERA){}
    void SetValues();
};

class Enemigo: Persona{
    using Persona::Persona;
    void SetValues();
};

#endif //BICASENLAUTEC_PERSONAJE_H
