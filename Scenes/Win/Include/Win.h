//
// Created by chip on 09/07/18.
//

#ifndef BICASENLAUTEC_WIN_H
#define BICASENLAUTEC_WIN_H


#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <string>
#include <iostream>
using namespace sf;
using namespace std;

class Win {
    Music Soundtrack;
public:
    Win(){};
    int Draw(RenderWindow &window, Event &evento);
    void StylizeText(Text &texto, Font &Letterfont, string Text, int x, int y);
};


#endif //BICASENLAUTEC_WIN_H
