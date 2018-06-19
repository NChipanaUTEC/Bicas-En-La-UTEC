//
// Created by chip on 16/06/18.
//

#ifndef BICASENLAUTEC_CHARACTERSELECT_H
#define BICASENLAUTEC_CHARACTERSELECT_H

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <string>
using namespace sf;
using namespace std;

class CharacterSelect {
    int TrianglePos;
    SoundBuffer SoundBuff;
    Sound AButton;
    Sound SelectButton;
public:
    CharacterSelect();
    string Draw(RenderWindow &window, Event &evento);
};


#endif //BICASENLAUTEC_CHARACTERSELECT_H
