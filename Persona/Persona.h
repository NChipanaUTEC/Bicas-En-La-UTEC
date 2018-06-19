//
// Created by chip on 13/06/18.
//

#ifndef BICASENLAUTEC_PERSONAJE_H
#define BICASENLAUTEC_PERSONAJE_H

#include <string>
using namespace std;

class Persona {
protected:
    int HP;
    int ATK;
    int DEF;
    int SPD;
    int LVL;
public:
    Persona(const int &HP,const int &ATK,const int &DEF, const int &LVL,const int &SPD): HP(HP), ATK(ATK), DEF(DEF),SPD(SPD),LVL(LVL){}
};

class Protagonista: public Persona{
    string CARRERA;
public:
    Protagonista(const int &HP,const int &ATK,const int &DEF, const int &LVL,const int &SPD, string CARRERA):
            Persona(HP,ATK,DEF,LVL,SPD),CARRERA(CARRERA){}
    void operator ++ ();
};

class Enemigo: public Persona{
    using Persona::Persona;
};

#endif //BICASENLAUTEC_PERSONAJE_H
