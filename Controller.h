//
// Created by chip on 09/06/18.
//

#ifndef BICASENLAUTEC_CONTROLLER_H
#define BICASENLAUTEC_CONTROLLER_H

#include "Scenes/Scenes.h"
#include "Persona/Persona.h"

class Controller {
    RenderWindow& window;
    Event evento;
    Scenes scene;
public:
    Controller(RenderWindow &window, Event &evento):window(window),evento(evento){}
    void SceneDraw();
};


#endif //BICASENLAUTEC_CONTROLLER_H
