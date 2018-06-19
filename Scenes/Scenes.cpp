//
// Created by chip on 09/06/18.
//

#include "Scenes.h"


void Scenes::SetScene(RenderWindow &window, Event &evento ,GenerarPersonaje& gp) {
    while(true){
        switch(Actual)
        {
            case TypeScenes::Intro:
                intro.Draw(window,evento);
                Actual = TypeScenes ::Characters;
                break;
            case TypeScenes::Characters:
                gp.updateType(chars.Draw(window,evento));
                Actual = TypeScenes ::Piso1;
                break;
            case TypeScenes::Piso1:
                p1.Draw(window,evento);
                Actual = TypeScenes ::Quit;
                break;
        }
        if (Actual == TypeScenes::Quit)
            break;
    }

}
