//
// Created by chip on 16/06/18.
//

#ifndef BICASENLAUTEC_PISO1_H
#define BICASENLAUTEC_PISO1_H

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <cstdlib>
using namespace sf;
using namespace std;

class Piso1 {
    Music Soundtrack;
    Clock clock1;
    int BackX = -250;
    int BackY = -1700;
    int EncounterValue;
public:
    Piso1();
    int Draw(RenderWindow &window, Event &evento);
};



#endif //BICASENLAUTEC_PISO1_H
