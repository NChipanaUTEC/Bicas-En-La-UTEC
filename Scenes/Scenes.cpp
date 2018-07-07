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
                Actual = TypeScenes::Characters;
                break;
            case TypeScenes::Characters:
                gp.CreateType(chars.Draw(window,evento));
                Actual = TypeScenes::Piso1;
                break;
            case TypeScenes::Piso1:
                InSceneChanger = p1.Draw(window,evento);
                switch(InSceneChanger){
                    case 0:
                        Actual = TypeScenes::FightScreen;
                        break;
                    case 1:
                        Actual = TypeScenes::StatScreen;
                        break;
                }
                break;
            case TypeScenes::FightScreen:
                fs.Draw(window,evento,gp);
                Actual = TypeScenes::Piso1;
                break;
            case TypeScenes ::StatScreen:
                ss.Draw(window,evento,gp);
                Actual = TypeScenes::Piso1;
                break;
        }
        if (Actual == TypeScenes::Quit)
            break;
    }

}
