//
// Created by chip on 16/06/18.
//

#include "CharacterSelect.h"

CharacterSelect::CharacterSelect() {
    TrianglePos = 90;
}

string CharacterSelect::Draw(RenderWindow &window, Event &evento) {
    CircleShape Triangle(10,3);
        Triangle.rotate(90);
        Triangle.setFillColor(Color::White);
        Triangle.setPosition(70,TrianglePos);
        Triangle.setScale(1.8,1.8);
    Font LetterFont;
        LetterFont.loadFromFile("../Scenes/Introduction/Fonts/alterebro-pixel-font.ttf");
    Text II;
        II.setFont(LetterFont);
        II.setString("Ingenieria Industrial");
        II.setCharacterSize(40);
        II.setFillColor(Color::White);
        II.setPosition(80,45);
        II.setScale(1.8,1.8);
    Text IEn;
        IEn.setFont(LetterFont);
        IEn.setString("Ingenieria de la Energia");
        IEn.setCharacterSize(40);
        IEn.setFillColor(Color::White);
        IEn.setPosition(80,90);
        IEn.setScale(1.8,1.8);
    Text IC;
        IC.setFont(LetterFont);
        IC.setString("Ingenieria Civil");
        IC.setCharacterSize(40);
        IC.setFillColor(Color::White);
        IC.setPosition(80,135);
        IC.setScale(1.8,1.8);
    Text IQ;
        IQ.setFont(LetterFont);
        IQ.setString("Ingenieria Quimica");
        IQ.setCharacterSize(40);
        IQ.setFillColor(Color::White);
        IQ.setPosition(80,180);
        IQ.setScale(1.8,1.8);
    Text IEl;
        IEl.setFont(LetterFont);
        IEl.setString("Ingenieria Electronica");
        IEl.setCharacterSize(40);
        IEl.setFillColor(Color::White);
        IEl.setPosition(80,225);
        IEl.setScale(1.8,1.8);
    Text IMcnc;
        IMcnc.setFont(LetterFont);
        IMcnc.setString("Ingenieria Mecanica");
        IMcnc.setCharacterSize(40);
        IMcnc.setFillColor(Color::White);
        IMcnc.setPosition(80,270);
        IMcnc.setScale(1.8,1.8);
    Text IA;
        IA.setFont(LetterFont);
        IA.setString("Ingenieria Ambiental");
        IA.setCharacterSize(40);
        IA.setFillColor(Color::White);
        IA.setPosition(80,315);
        IA.setScale(1.8,1.8);
    Text CS;
        CS.setFont(LetterFont);
        CS.setString("Ciencias de la Computacion");
        CS.setCharacterSize(40);
        CS.setFillColor(Color::White);
        CS.setPosition(80,360);
        CS.setScale(1.8,1.8);
    Text IMctr;
        IMctr.setFont(LetterFont);
        IMctr.setString("Ingenieria Mecatronica");
        IMctr.setCharacterSize(40);
        IMctr.setFillColor(Color::White);
        IMctr.setPosition(80,405);
        IMctr.setScale(1.8,1.8);
    Text BI;
        BI.setFont(LetterFont);
        BI.setString("Bioingenieria");
        BI.setCharacterSize(40);
        BI.setFillColor(Color::White);
        BI.setPosition(80,450);
        BI.setScale(1.8,1.8);
    Text Select;
        Select.setFont(LetterFont);
        Select.setString("Escoge tu carrera");
        Select.setCharacterSize(60);
        Select.setFillColor(Color::Cyan);
        Select.setPosition(400,500);
        Select.setScale(1.8,1.8);



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
                        if (TrianglePos == 495){
                            TrianglePos -=405;
                            Triangle.move(0,-405);
                            break;}
                        else if(TrianglePos != 0){
                            TrianglePos +=45;
                            Triangle.move(0,45);
                            break;}
                    }
                    else if (evento.key.code == Keyboard::Up) {
                        SelectButton.play();
                        if (TrianglePos == 90) {
                            TrianglePos += 405;
                            Triangle.move(0, 405);
                            break;}
                        else if (TrianglePos != 0) {
                            TrianglePos -= 45;
                            Triangle.move(0, -45);
                            break;
                        }
                    }
                    else if(evento.key.code == Keyboard::Z) {
                        switch(TrianglePos){
                            case(90):
                                return "Ingenieria Industrial";
                            case(135):
                                return "Ingenieria de la Energia";
                            case(180):
                                return "Ingenieria Civil";
                            case(225):
                                return "Ingenieria Quimica";
                            case(270):
                                return "Ingenieria Electronica";
                            case(315):
                                return "Ingenieria Mecanica";
                            case(360):
                                return "Ingenieria Ambiental";
                            case(405):
                                return "Ciencias de la Computacion";
                            case(450):
                                return "Ingenieria Mecatronica";
                            case(495):
                                return "Bioingenieria";
                        }
                    }
            }

            window.clear();
            window.draw(II);
            window.draw(IEn);
            window.draw(IC);
            window.draw(IQ);
            window.draw(IEl);
            window.draw(IMcnc);
            window.draw(IA);
            window.draw(CS);
            window.draw(IMctr);
            window.draw(BI);
            window.draw(Triangle);
            window.draw(Select);
            window.display();
        }
    }
}

