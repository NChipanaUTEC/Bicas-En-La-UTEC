//
// Created by chip on 09/06/18.
//

#ifndef BICASENLAUTEC_CONTROLLER_H
#define BICASENLAUTEC_CONTROLLER_H

#include "Scenes/Scenes.h"
#include "Persona/Persona.h"
#include "Util/GenerarPersonaje.h"


class Controller {
    RenderWindow& window;
    Event evento;
    Scenes scene;
    Protagonista prota;
    Enemigo enemigo;
public:
    Controller(RenderWindow &window, Event &evento):window(window),evento(evento),prota(0,0,0,0,0,"",0,0),enemigo(0,0,0,0,0){}
    void SceneDraw();
};


#endif //BICASENLAUTEC_CONTROLLER_H
