//
// Created by chip on 08/07/18.
//

#ifndef BICASENLAUTEC_DEFEAT_H
#define BICASENLAUTEC_DEFEAT_H
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <string>
#include <iostream>
using namespace sf;
using namespace std;

class Defeat {
    Music Soundtrack;
public:
    Defeat(){};
    int Draw(RenderWindow &window, Event &evento);
    void StylizeText(Text &texto, Font &Letterfont, string Text, int x, int y);
};



#endif //BICASENLAUTEC_DEFEAT_H
