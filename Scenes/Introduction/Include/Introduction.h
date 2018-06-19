//
// Created by chip on 09/06/18.
//

#ifndef BICASENLAUTEC_INTRODUCTION_H
#define BICASENLAUTEC_INTRODUCTION_H

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
using namespace sf;
using namespace std;

class Introduction{
    int TrianglePos = 420;
    SoundBuffer SoundBuff;
    Sound SelectButton;
public:
    Introduction();
    int Draw(RenderWindow &window, Event &evento);
};



#endif //BICASENLAUTEC_INTRODUCTION_H
