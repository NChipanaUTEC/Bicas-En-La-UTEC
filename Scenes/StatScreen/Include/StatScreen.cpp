//
// Created by chip on 05/07/18.
//

#include "StatScreen.h"

int StatScreen::Draw(RenderWindow &window, Event &evento, GenerarPersonaje &gp) {
    gp.GetType(ProtaData);
    gp.GetCarrera(Carrera);

    for(auto x: ProtaData)
        cout << x << endl;

    Font Letterfont;
    Letterfont.loadFromFile("../Scenes/FightScreen/Fonts/alterebro-pixel-font.ttf");

    Texture BGTexture;
    BGTexture.loadFromFile("../Scenes/StatScreen/Graphics/Screen.png");
    Sprite Background(BGTexture);
    Background.setScale(5, 4.9);
    Background.setPosition(0, 0);

    Text Crrea;
    Crrea.setString(Carrera);
    Crrea.setFont(Letterfont);
    Crrea.setPosition(320,120);
    Crrea.setCharacterSize(80);

    Text Attack;
    Attack.setString(to_string(ProtaData[1]));
    Attack.setFont(Letterfont);
    Attack.setPosition(320,340);
    Attack.setCharacterSize(80);

    Text Defense;
    Defense.setString(to_string(ProtaData[2]));
    Defense.setFont(Letterfont);
    Defense.setPosition(320,400);
    Defense.setCharacterSize(80);

    Text Speed;
    Speed.setString(to_string(ProtaData[3]));
    Speed.setFont(Letterfont);
    Speed.setPosition(320,460);
    Speed.setCharacterSize(80);

    Text Nivel;
    Nivel.setString(to_string(ProtaData[4]));
    Nivel.setFont(Letterfont);
    Nivel.setPosition(900,390);
    Nivel.setCharacterSize(80);


    Soundtrack.openFromFile("../Scenes/StatScreen/Sounds/Youve Got Me (VA-11 HALL-A).ogg");
    Soundtrack.setLoop(true);
    Soundtrack.play();

    SoundBuff.loadFromFile("../Scenes/StatScreen/Sounds/FGBS(27).wav");
    SelectButton.setBuffer(SoundBuff);

    while (window.isOpen()) {
        while (window.pollEvent(evento)) {
            switch (evento.type) {
                case Event::Closed:
                    window.close();
                    break;
                case Event::KeyPressed:
                    if (evento.key.code == Keyboard::X || evento.key.code == Keyboard::C) {
                        Soundtrack.stop();
                        SelectButton.play();
                        return 0;

                    }
                    window.clear();
                    window.draw(Background);
                    window.draw(Crrea);
                    window.draw(Attack);
                    window.draw(Defense);
                    window.draw(Speed);
                    window.draw(Nivel);
                    window.display();
            }
        }
    }
}
