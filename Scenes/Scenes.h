//
// Created by chip on 09/06/18.
//

#ifndef BICASENLAUTEC_SCENES_H
#define BICASENLAUTEC_SCENES_H

#include "Introduction/Include/Introduction.h"
#include "CharacterSelect/Include/CharacterSelect.h"
#include "Piso1/Include/Piso1.h"
#include "../Util/GenerarPersonaje.h"

enum class TypeScenes{Intro, Characters, Piso1, Quit};

class Scenes {
    Introduction intro;
    CharacterSelect chars;
    Piso1 p1;
    TypeScenes Actual = TypeScenes::Intro;
public:
    void SetScene (RenderWindow &window, Event &evento, GenerarPersonaje& gp);
};


#endif //BICASENLAUTEC_SCENES_H
