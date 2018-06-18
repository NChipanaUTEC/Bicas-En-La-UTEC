//
// Created by chip on 09/06/18.
//

#ifndef BICASENLAUTEC_SCENES_H
#define BICASENLAUTEC_SCENES_H

#include "Introduction/Include/Introduction.h"
#include "CharacterSelect/Include/CharacterSelect.h"
#include "Piso1/Include/Piso1.h"

class Scenes {
    Introduction intro;
    CharacterSelect chars;
    Piso1 p1;
public:
    void SetScene (RenderWindow &window, Event &evento);
};


#endif //BICASENLAUTEC_SCENES_H
