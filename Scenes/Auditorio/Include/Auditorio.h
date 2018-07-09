//
// Created by chip on 16/06/18.
//

#ifndef BICASENLAUTEC_AUDITORIO_H
#define BICASENLAUTEC_AUDITORIO_H

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <cstdlib>
using namespace sf;
using namespace std;

class Auditorio {
    Music Soundtrack;
    SoundBuffer Sf;
    Sound Collision;
    Clock clock1;
    int BackX = -2770;
    int BackY = -1040;
    int EncounterValue = 0;
public:
    Auditorio(){}
    int Draw(RenderWindow &window, Event &evento);
};



#endif //BICASENLAUTEC_PISO1_H
