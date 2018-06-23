//
// Created by chip on 09/06/18.
//

#include "Introduction.h"

Introduction::Introduction() {

}


int Introduction::Draw(RenderWindow &window, Event &evento) {
    Texture BGTexture;
        BGTexture.loadFromFile("../Scenes/Introduction/Graphics/BicasUTECTitle.png");
    Sprite Background;
        Background.setTexture(BGTexture);
        Background.setScale(0.65,0.65);
        Background.setPosition(0,-50);
    CircleShape Triangle(10,3);
        Triangle.rotate(90);
        Triangle.setFillColor(Color::White);
        Triangle.setPosition((window.getSize().x)/3,TrianglePos);
        Triangle.setScale(1.8,1.8);
    Font LetterFont;
        LetterFont.loadFromFile("../Scenes/Introduction/Fonts/alterebro-pixel-font.ttf");
    Text Start;
        Start.setFont(LetterFont);
        Start.setString("START");
        Start.setCharacterSize(50);
        Start.setFillColor(Color::White);
        Start.setPosition((window.getSize().x)/2.5,520);
        Start.setScale(1.8,1.8);
    Text Exit;
        Exit.setFont(LetterFont);
        Exit.setString("EXIT");
        Exit.setCharacterSize(50);
        Exit.setFillColor(Color::White);
        Exit.setPosition((window.getSize().x)/2.5,570);
        Exit.setScale(1.8,1.8);
        
    SoundBuff.loadFromFile("../Scenes/Introduction/Sounds/FGBS(27).wav");
    SelectButton.setBuffer(SoundBuff);

    while (window.isOpen()) {
        while (window.pollEvent(evento)) {
            switch(evento.type) {
                case Event::Closed:
                    window.close();
                    break;
                case Event::KeyPressed:
                    if(evento.key.code == Keyboard::Down) {
                        SelectButton.play();
                        if(TrianglePos == 570){
                            TrianglePos +=50;
                            Triangle.move(0,50);
                            break;}
                    }
                    else if (evento.key.code == Keyboard::Up) {
                        SelectButton.play();
                        if (TrianglePos == 620){
                            TrianglePos -=50;
                            Triangle.move(0,-50);
                            break;}
                    }
                    else if(evento.key.code == Keyboard::Z) {
                        if(TrianglePos==570){
                            return 0;
                        }
                        if(TrianglePos==620) {
                            window.close();
                        }
                        break;
                    }
            }

            window.clear();
            window.draw(Background);
            window.draw(Start);
            window.draw(Exit);
            window.draw(Triangle);
            window.display();
        }
    }
}
