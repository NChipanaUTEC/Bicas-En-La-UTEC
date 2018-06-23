//
// Created by chip on 23/06/18.
//

#ifndef BICASENLAUTEC_FIGHTSCREEN_H
#define BICASENLAUTEC_FIGHTSCREEN_H
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "../../../Util/GenerarPersonaje.h"
#include <iostream>
using namespace sf;
using namespace std;


class FightScreen {
    Music Soundtrack;
    int TrianglePosX = 100;
    int TrianglePosY = 550;
public:
    FightScreen() {}
    int Draw(RenderWindow &window, Event &evento, GenerarPersonaje& gp);
};


#endif //BICASENLAUTEC_FIGHTSCREEN_H
