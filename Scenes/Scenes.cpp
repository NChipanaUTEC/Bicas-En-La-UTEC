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
                gp.CreateEnemy();
                Actual = TypeScenes::Transition;
                break;
            case TypeScenes ::Transition:
                ts.Draw(window,evento);
                Actual = TypeScenes::Piso1;
                break;
            case TypeScenes::Piso1:
                Previous = TypeScenes::Piso1;
                InSceneChanger = p1.Draw(window,evento);
                switch(InSceneChanger){
                    case 0:
                        Actual = TypeScenes::FightScreen;
                        break;
                    case 1:
                        Actual = TypeScenes::StatScreen;
                        break;
                    case 2:
                        Actual = TypeScenes::Auditorio;
                        break;
                }
                break;
            case TypeScenes::Auditorio:
                Previous = TypeScenes::Auditorio;
                InSceneChanger = audi.Draw(window,evento);
                switch(InSceneChanger){
                    case 0:
                        Previous = TypeScenes ::Auditorio;
                        Actual = TypeScenes::FightScreen;
                        break;
                    case 1:
                        Previous = TypeScenes ::Auditorio;
                        Actual = TypeScenes::StatScreen;
                        break;
                    case 2:
                        Actual = TypeScenes::Piso1;
                        break;
                    case 3:
                        Actual = TypeScenes::BossScreen;
                        break;
                }
                break;
            case TypeScenes::FightScreen:
                gp.UpdateEnemy();
                InSceneChanger = fs.Draw(window,evento,gp);
                switch (InSceneChanger){
                    case 0:
                        if(Previous == TypeScenes::Piso1){
                            Actual = TypeScenes::Piso1;
                            break;
                        }
                        else if(Previous == TypeScenes::Auditorio){
                            Actual = TypeScenes::Auditorio;
                            break;
                        }
                    case 1:
                        Actual = TypeScenes::Defeat;
                        break;
                }
                break;
            case TypeScenes::BossScreen:
                gp.UpdateEnemy();
                InSceneChanger = bs.Draw(window,evento,gp);
                switch (InSceneChanger){
                    case 0:
                        Actual = TypeScenes::Auditorio;
                        break;
                    case 1:
                        Actual = TypeScenes::Defeat;
                        break;
                    case 2:
                        Actual = TypeScenes ::Win;
                        break;
                }
                break;
            case TypeScenes ::StatScreen:
                ss.Draw(window,evento,gp);
                if(Previous == TypeScenes::Piso1){
                    Actual = TypeScenes::Piso1;
                    break;
                }
                else if(Previous==TypeScenes::Auditorio){
                    Actual = TypeScenes::Auditorio;
                    break;
                }
            case TypeScenes ::Defeat:
                dt.Draw(window,evento);
                Actual = TypeScenes::Intro;
                break;
            case TypeScenes ::Win:
                wn.Draw(window,evento);
                Actual = TypeScenes::Intro;
                break;
        }
        if(Actual==TypeScenes::Quit)
            break;
    }

}
