//
// Created by chip on 08/07/18.
//

#ifndef BICASENLAUTEC_TRANSITION_H
#define BICASENLAUTEC_TRANSITION_H
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <string>
#include <iostream>
using namespace sf;
using namespace std;

class Transition {
    int StringRandom;
public:
    Transition(){};
    int Draw(RenderWindow &window, Event &evento);
    void StylizeText(Text &text, Font& Letterfont);
};


#endif //BICASENLAUTEC_TRANSITION_H
