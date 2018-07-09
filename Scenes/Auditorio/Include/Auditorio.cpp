//
// Created by chip on 16/06/18.
//
#include <iostream>
#include "Auditorio.h"

using namespace std;

int Auditorio::Draw(RenderWindow &window, Event &evento)
{
    srand(time(nullptr));
    Soundtrack.openFromFile("../Scenes/Auditorio/Sounds/Neon District.wav");
        Soundtrack.setLoop(true);
        Soundtrack.play();
    Sf.loadFromFile("../Scenes/Auditorio/Sounds/oof.ogg");
    Collision.setBuffer(Sf);

    Texture BGTexture;
        BGTexture.loadFromFile("../Scenes/Auditorio/Graphics/auditorioBackground.png");
    Sprite Background;
        Background.setTexture(BGTexture);
        Background.setPosition(BackX,BackY);
        Background.setScale(2,2);

    Texture ProtaTextura;
        ProtaTextura.loadFromFile("../Scenes/Auditorio/Graphics/pSprite.png");
        IntRect SpriteBx(0,0,34,47);
    Sprite Protagonista(ProtaTextura,SpriteBx);
        Protagonista.setPosition((window.getSize().x)/2.35,(window.getSize().y)/3);
        Protagonista.setScale(3,3);

    RectangleShape AuditorioDoor;
        AuditorioDoor.setSize(Vector2f(20,320));
        AuditorioDoor.setFillColor(Color::Yellow);
        AuditorioDoor.setPosition(BackX+3440,BackY+1180);

    Texture PenaTextura;
        PenaTextura.loadFromFile("../Scenes/Auditorio/Graphics/PixelPena.png");
    Sprite Pena(PenaTextura);
        Pena.setPosition(BackX+320,BackY+1625);

    while (window.isOpen()) {
        while (window.pollEvent(evento)) {
            switch (evento.type) {
                case Event::Closed:
                    window.close();
                    break;
                case Event::KeyPressed:
                    EncounterValue = rand()%200;
                    if(EncounterValue > 1){
                        if(evento.key.code == Keyboard::Down) {
                            BackY -= 10;
                            Background.move(0,-10);
                            AuditorioDoor.move(0,-10);
                            Pena.move(0,-10);
                            /*
                            Color BoundsColor = Bounds.getPixel(BackX,BackY);
                            if (BoundsColor == Color::Black && Protagonista.getGlobalBounds().intersects(Foreground.getGlobalBounds())){
                                BackY += 10;
                                Background.move(0, 10);
                                Foreground.move(0, 10);
                           }
                            */
                            if(clock1.getElapsedTime().asMilliseconds()>64){
                                SpriteBx.top = 0;
                                if (SpriteBx.left == 0)
                                    SpriteBx.left = 34;
                                else if (SpriteBx.left==34)
                                    SpriteBx.left= 68;
                                else if (SpriteBx.left== 68)
                                    SpriteBx.left= 102;
                                else
                                    SpriteBx.left=0;
                                Protagonista.setTextureRect(SpriteBx);
                                clock1.restart();
                            }
                            break;
                        }
                        else if (evento.key.code == Keyboard::Up) {
                            BackY += 10;
                            Background.move(0,10);
                            AuditorioDoor.move(0,10);
                            Pena.move(0,10);
                            if (clock1.getElapsedTime().asMilliseconds()>64)
                            {
                                SpriteBx.top = 152;
                                if (SpriteBx.left == 0)
                                    SpriteBx.left = 34;
                                else if (SpriteBx.left==34)
                                    SpriteBx.left= 68;
                                else if (SpriteBx.left== 68)
                                    SpriteBx.left= 102;
                                else
                                    SpriteBx.left=0;
                                Protagonista.setTextureRect(SpriteBx);
                                clock1.restart();
                            }
                            break;
                        }
                        else if(evento.key.code == Keyboard::Left) {
                            BackX += 10;
                            Background.move(10,0);
                            AuditorioDoor.move(10,0);
                            Pena.move(10,0);
                            if (clock1.getElapsedTime().asMilliseconds()>64)
                            {
                                SpriteBx.top = 53;
                                if (SpriteBx.left == 0)
                                    SpriteBx.left = 34;
                                else if (SpriteBx.left==34)
                                    SpriteBx.left= 68;
                                else if (SpriteBx.left== 68)
                                    SpriteBx.left= 102;
                                else
                                    SpriteBx.left=0;
                                Protagonista.setTextureRect(SpriteBx);
                                clock1.restart();
                            }
                            break;
                        }
                        else if(evento.key.code == Keyboard::Right){
                            BackX -= 10;
                            Background.move(-10,0);
                            AuditorioDoor.move(-10,0);
                            Pena.move(-10,0);
                            if (clock1.getElapsedTime().asMilliseconds()>64)
                            {
                                SpriteBx.top = 104;
                                if (SpriteBx.left == 0)
                                    SpriteBx.left = 34;
                                else if (SpriteBx.left==34)
                                    SpriteBx.left= 68;
                                else if (SpriteBx.left== 68)
                                    SpriteBx.left= 102;
                                else
                                    SpriteBx.left=0;
                                Protagonista.setTextureRect(SpriteBx);
                                clock1.restart();
                            }
                            break;
                        }
                        else if(evento.key.code == Keyboard::C){
                            Soundtrack.stop();
                            return 1;
                        }
                        else if(evento.key.code == Keyboard::Z){
                            if(AuditorioDoor.getGlobalBounds().intersects(Protagonista.getGlobalBounds())){
                                Soundtrack.stop();
                                return 2;
                            }
                            if(Protagonista.getGlobalBounds().intersects(Pena.getGlobalBounds())){
                                Soundtrack.stop();
                                return 3;
                            }
                        }
                    }
                    else{
                        Soundtrack.stop();
                        return 0;
                    }
            }
            window.clear();
            window.draw(Background);
            window.draw(AuditorioDoor);
            window.draw(Pena);
            window.draw(Protagonista);
            window.display();
        }
    }
}
