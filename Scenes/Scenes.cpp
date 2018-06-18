//
// Created by chip on 09/06/18.
//

#include "Scenes.h"


void Scenes::SetScene(RenderWindow &window, Event &evento) {
    int i = 0;
    switch(i)
    {
        case 0:
            intro.Draw(window,evento);
        case 1:
            chars.Draw(window,evento);
        case 2:
            p1.Draw(window,evento);
    }
}
