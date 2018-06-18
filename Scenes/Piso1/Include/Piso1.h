//
// Created by chip on 16/06/18.
//

#ifndef BICASENLAUTEC_PISO1_H
#define BICASENLAUTEC_PISO1_H

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>
using namespace sf;
using namespace std;

class Piso1 {
    SoundBuffer SoundBuff;
    Sound AButton;
    Sound SelectButton;
    Music Soundtrack;
    int BackX = -250;
    int BackY = -1700;
public:
    Piso1();
    int Draw(RenderWindow &window, Event &evento);
};



#endif //BICASENLAUTEC_PISO1_H
