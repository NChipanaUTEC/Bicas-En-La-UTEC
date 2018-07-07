//
// Created by chip on 05/07/18.
//

#ifndef BICASENLAUTEC_STATSCREEN_H
#define BICASENLAUTEC_STATSCREEN_H
#include <string>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "../../../Util/GenerarPersonaje.h"
#include <iostream>
using namespace std;
using namespace sf;



class StatScreen {
    int ProtaData[7];
    string Carrera;
    Music Soundtrack;
    SoundBuffer SoundBuff;
    Sound SelectButton;
public:
    StatScreen(){}
    int Draw(RenderWindow &window, Event &evento, GenerarPersonaje& gp);
};


#endif //BICASENLAUTEC_STATSCREEN_H
