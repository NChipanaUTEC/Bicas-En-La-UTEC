//
// Created by chip on 09/06/18.
//

#ifndef BICASENLAUTEC_SCENES_H
#define BICASENLAUTEC_SCENES_H

#include "Introduction/Include/Introduction.h"
#include "Transition/Include/Transition.h"
#include "CharacterSelect/Include/CharacterSelect.h"
#include "Piso1/Include/Piso1.h"
#include "FightScreen/Include/FightScreen.h"
#include "StatScreen/Include/StatScreen.h"
#include "Defeat/Include/Defeat.h"
#include "Auditorio/Include/Auditorio.h"
#include "../Util/GenerarPersonaje.h"
#include "BossScreen/Include/BossScreen.h"
#include "Win/Include/Win.h"

enum class TypeScenes{Intro, Characters, Piso1, Auditorio, FightScreen, BossScreen, StatScreen, Transition, Defeat, Win,  Quit};

class Scenes {
    int InSceneChanger = 0;
    Introduction intro;
    CharacterSelect chars;
    Piso1 p1;
    Auditorio audi;
    FightScreen fs;
    BossScreen bs;
    StatScreen ss;
    Transition ts;
    Defeat dt;
    Win wn;
    TypeScenes Previous = TypeScenes::Intro;
    TypeScenes Actual = TypeScenes::Intro;
public:
    void SetScene (RenderWindow &window, Event &evento, GenerarPersonaje& gp);
};


#endif //BICASENLAUTEC_SCENES_H
