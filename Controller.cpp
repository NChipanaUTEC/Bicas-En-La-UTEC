//
// Created by chip on 09/06/18.
//

#include "Controller.h"

void Controller::SceneDraw() {
    GenerarPersonaje gp(prota,enemigo);
    scene.SetScene(window,evento, gp);

}