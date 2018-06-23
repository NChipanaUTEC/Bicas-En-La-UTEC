#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Controller.h"
using namespace sf;

int main()
{
    RenderWindow window (VideoMode(1400, 1200), "Bicas en la UTEC");
    Event evento;
    Controller controller(window,evento);
    controller.SceneDraw();
}

//Canción Save Room:You've got me
//Canción Pelea: The New Frontier