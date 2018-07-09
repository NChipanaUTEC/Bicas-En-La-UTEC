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
    Persona(const int &HP,const int &ATK,const int &DEF, const int &SPD,const int &LVL): HP(HP), ATK(ATK), DEF(DEF),SPD(SPD),LVL(LVL){}
};

class Protagonista: public Persona{
    int ActualXP;
    int MaxXP;
    string CARRERA;
public:
    Protagonista(const int &HP,const int &ATK,const int &DEF, const int &SPD,const int &LVL, string CARRERA, const int &ActualXP, const int &MaxXP):
            Persona(HP,ATK,DEF,SPD,LVL),CARRERA(CARRERA),ActualXP(ActualXP),MaxXP(MaxXP){}
    void operator ++ ();
    void GetData(int(&data)[7]);
    void GetCarrera(string &carrera);
};

class Enemigo: public Persona{
public:
    using Persona::Persona;
    void GetData(int(&data)[5]);
};

#endif //BICASENLAUTEC_PERSONAJE_H
