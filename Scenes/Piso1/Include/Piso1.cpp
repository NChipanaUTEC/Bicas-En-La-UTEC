//
// Created by chip on 16/06/18.
//

#include "Piso1.h"

Piso1::Piso1(){

};

int Piso1::Draw(RenderWindow &window, Event &evento)
{
    srand(time(NULL));
    Soundtrack.openFromFile("../Scenes/Piso1/Sounds/Neon District.wav");
        Soundtrack.setLoop(true);
        Soundtrack.play();
    Texture BGTexture;
        BGTexture.loadFromFile("../Scenes/Piso1/Graphics/piso1background.png");
    Sprite Background;
        Background.setTexture(BGTexture);
        Background.setScale(8,7.5);
        Background.setPosition(BackX,BackY);

    Texture FGTexture;
        FGTexture.loadFromFile("../Scenes/Piso1/Graphics/piso1foreground.png");
    Sprite Foreground;
        Foreground.setTexture(FGTexture);
        Foreground.setScale(8,7.5);
        Foreground.setPosition(BackX,BackY);

    Texture ProtaTextura;
        ProtaTextura.loadFromFile("../Scenes/Piso1/Graphics/pSprite.png");
        IntRect SpriteBx(0,0,34,47);
    Sprite Protagonista(ProtaTextura,SpriteBx);
        Protagonista.setPosition((window.getSize().x)/2.35,(window.getSize().y)/3);
        Protagonista.setScale(3,3);

    while (window.isOpen()) {
        while (window.pollEvent(evento)) {
            switch (evento.type) {
                case Event::Closed:
                    window.close();
                    break;
                case Event::KeyPressed:
                    EncounterValue = rand()%1000;
                    if(EncounterValue > 5){
                        if(evento.key.code == Keyboard::Down) {
                            BackY -= 10;
                            Background.move(0,-10);
                            Foreground.move(0,-10);
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
                            Foreground.move(0,10);
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
                            Foreground.move(10,0);
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
                            Foreground.move(-10,0);
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
                    }
                    else{
                        Soundtrack.stop();
                        return 0;
                    }
            }
            window.clear();
            window.draw(Background);
            window.draw(Foreground);
            window.draw(Protagonista);
            window.display();
        }
    }
}
