//
// Created by chip on 16/06/18.
//

#include "Piso1.h"

Piso1::Piso1(){

};

int Piso1::Draw(RenderWindow &window, Event &evento)
{
    Clock clock1;
    Soundtrack.openFromFile("../Scenes/Piso1/Sounds/Neon District.wav");
        Soundtrack.setLoop(true);
        Soundtrack.play();
    Texture BGTexture;
        BGTexture.loadFromFile("../Scenes/Piso1/Graphics/piso1.png");
    Sprite Background;
        Background.setTexture(BGTexture);
        Background.setScale(8,7.5);
        Background.setPosition(BackX,BackY);

    Texture FGTexture;
        FGTexture.loadFromFile("../Scenes/Piso1/Graphics/piso1bounds.png");
    Sprite Foreground;
        Foreground.setTexture(FGTexture);
        Foreground.setScale(8,7.5);
        Foreground.setPosition(BackX,BackY);

    Texture ProtaTextura;
        ProtaTextura.loadFromFile("../Scenes/Piso1/Graphics/pSprite.png");
        IntRect SpriteBx(0,0,65,65);
    Sprite Protagonista(ProtaTextura,SpriteBx);
        Protagonista.setPosition((window.getSize().x)/3,(window.getSize().y)/3);
        Protagonista.setScale(3,3);

    while (window.isOpen()) {
        while (window.pollEvent(evento)) {
            switch (evento.type) {
                case Event::Closed:
                    window.close();
                    break;
                case Event::KeyPressed:
                    if(evento.key.code == sf::Keyboard::Down) {
                        BackY -= 10;
                        Background.move(0,-10);
                        Foreground.move(0,-10);
                        if(Protagonista.getPosition()==Foreground.getPosition()){
                            BackY+=10;
                            Background.move(0,10);
                        }
                        if(clock1.getElapsedTime().asMilliseconds()>64){
                            SpriteBx.top = 0;
                            if (SpriteBx.left == 192)
                                SpriteBx.left = 0;
                            else if (SpriteBx.left==64)
                                SpriteBx.left= 128;
                            else if (SpriteBx.left== 128)
                                SpriteBx.left= 192;
                            else
                                SpriteBx.left=64;
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
                            SpriteBx.top = 192;
                            if (SpriteBx.left == 192)
                                SpriteBx.left = 0;
                            else if (SpriteBx.left==64)
                                SpriteBx.left= 128;
                            else if (SpriteBx.left== 128)
                                SpriteBx.left= 192;
                            else
                                SpriteBx.left=64;
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
                            SpriteBx.top = 64;
                            if (SpriteBx.left == 192)
                                SpriteBx.left = 0;
                            else if (SpriteBx.left==64)
                                SpriteBx.left= 128;
                            else if (SpriteBx.left== 128)
                                SpriteBx.left= 192;
                            else
                                SpriteBx.left=64;
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
                            SpriteBx.top = 128;
                            if (SpriteBx.left == 192)
                                SpriteBx.left = 0;
                            else if (SpriteBx.left==64)
                                SpriteBx.left= 128;
                            else if (SpriteBx.left== 128)
                                SpriteBx.left= 192;
                            else
                                SpriteBx.left=64;
                            Protagonista.setTextureRect(SpriteBx);
                            clock1.restart();
                        }
                        break;
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
