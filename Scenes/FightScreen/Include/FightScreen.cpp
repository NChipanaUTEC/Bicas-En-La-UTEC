//
// Created by chip on 23/06/18.
//

#include "FightScreen.h"

int FightScreen::Draw(RenderWindow &window, Event &evento, GenerarPersonaje& gp) {
    srand(time(nullptr));
    SpriteRandom = rand()%3;
    gp.GetType(ProtaData);
    
    Texture BGTexture;
        BGTexture.loadFromFile("../Scenes/FightScreen/Graphics/piso1battle.png");
    Sprite Background(BGTexture);
        Background.setScale(5,4.9);
        Background.setPosition(0,0);

    Texture ProtaTextura;
        ProtaTextura.loadFromFile("../Scenes/FightScreen/Graphics/yosuke.png");
    Sprite Protagonista(ProtaTextura);
        Protagonista.setPosition(200,80);

    Texture EnemigoTextura;
    Sprite Enemigo;
        switch (SpriteRandom){
            case 0:
                EnemigoTextura.loadFromFile("../Scenes/FightScreen/Graphics/pingpong.png");
                Enemigo.setTexture(EnemigoTextura);
                Enemigo.setPosition(575,130);
                Enemigo.setScale(0.1,0.1);
                break;
            case 1:
                EnemigoTextura.loadFromFile("../Scenes/FightScreen/Graphics/barcelo.png");
                Enemigo.setTexture(EnemigoTextura);
                Enemigo.setPosition(600,70);
                Enemigo.setScale(0.6,0.6);
                break;
            case 2:
                EnemigoTextura.loadFromFile("../Scenes/FightScreen/Graphics/dota2_logo.png");
                Enemigo.setTexture(EnemigoTextura);
                Enemigo.setPosition(575,130);
                Enemigo.setScale(0.5,0.5);
                break;
        }


    CircleShape Triangle(10,3);
        Triangle.rotate(90);
        Triangle.setFillColor(Color::White);
        Triangle.setPosition(TrianglePosX,TrianglePosY);
        Triangle.setScale(1.8,1.8);

     Font Letterfont;
        Letterfont.loadFromFile("../Scenes/FightScreen/Fonts/alterebro-pixel-font.ttf");
     Text Attack;
        Attack.setFont(Letterfont);
        Attack.setString("ATTACK");
        Attack.setFillColor(Color::White);
        Attack.setPosition(110,510);
        Attack.setCharacterSize(70);
    Text Skills;
        Skills.setFont(Letterfont);
        Skills.setString("SKILLS");
        Skills.setFillColor(Color::White);
        Skills.setPosition(410,510);
        Skills.setCharacterSize(70);
    Text Defend;
        Defend.setFont(Letterfont);
        Defend.setString("DEFEND");
        Defend.setFillColor(Color::White);
        Defend.setPosition(110,600);
        Defend.setCharacterSize(70);
    Text Run;
        Run.setFont(Letterfont);
        Run.setString("RUN");
        Run.setFillColor(Color::White);
        Run.setPosition(410,600);
        Run.setCharacterSize(70);

        Soundtrack.openFromFile("../Scenes/FightScreen/Sounds/Will Power.wav");
        Soundtrack.setLoop(true);
        Soundtrack.play();


    while (window.isOpen()) {
        while (window.pollEvent(evento)) {
            switch(evento.type) {
                case Event::Closed:
                    window.close();
                    break;
                case Event::KeyPressed:
                    if(evento.key.code == Keyboard::Down){
                        if(TrianglePosY == 550){
                            TrianglePosY += 90;
                            Triangle.move(0,90);
                        }
                    }
                    if(evento.key.code == Keyboard::Up){
                        if(TrianglePosY == 640){
                            TrianglePosY -= 90;
                            Triangle.move(0,-90);
                        }
                    }
                    if(evento.key.code == Keyboard::Right){
                        if(TrianglePosX == 100){
                            TrianglePosX += 300;
                            Triangle.move(300,0);
                        }
                    }
                    if(evento.key.code == Keyboard::Left){
                        if(TrianglePosX == 400){
                            TrianglePosX-= 300;
                            Triangle.move(-300,0);
                        }
                    }
                    if(evento.key.code == Keyboard::Z){
                        switch(TrianglePosY){
                            case(550):
                                if(TrianglePosX == 100){
                                    Soundtrack.stop();
                                    return 0;
                                }
                                else{
                                    Soundtrack.stop();
                                    return 0;
                                }
                            case(640):
                                if(TrianglePosX == 400){
                                    Soundtrack.stop();
                                    return 0;
                                }
                                else{
                                    Soundtrack.stop();
                                    return 0;
                                }
                        }
                    }
            }
            window.clear();
            window.draw(Background);
            window.draw(Protagonista);
            window.draw(Triangle);
            window.draw(Attack);
            window.draw(Defend);
            window.draw(Skills);
            window.draw(Run);
            window.draw(Enemigo);
            window.display();
        }
    }
}
