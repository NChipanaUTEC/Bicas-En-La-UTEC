//
// Created by chip on 09/07/18.
//

#include "Win.h"

int Win::Draw(RenderWindow &window, Event &evento) {

    Soundtrack.openFromFile("../Scenes/Win/Sounds/Victory.ogg");
    Soundtrack.play();

    Font LetterFont;
    LetterFont.loadFromFile("../Scenes/Win/Fonts/alterebro-pixel-font.ttf");
    Text Talento;
    StylizeText(Talento,LetterFont,"LO HAS LOGRADO CACHIMBO!",500,100);
    Text Continuar;
    StylizeText(Continuar,LetterFont,"IZIca se pasa solo!!",450,500);


    while (window.isOpen()) {
        while (window.pollEvent(evento)) {
            switch(evento.type){
                case Event::KeyPressed:
                    if(evento.key.code == Keyboard::Z){
                        Soundtrack.stop();
                        return 0;
                    }
            }
            window.clear();
            window.draw(Talento);
            window.draw(Continuar);
            window.display();
        }
    }
}

void Win::StylizeText(Text &texto, Font &Letterfont, string Text, int x, int y) {
    texto.setFont(Letterfont);
    texto.setFillColor(Color::White);
    texto.setCharacterSize(70);
    texto.setString(Text);
    texto.setPosition(x,y);
}
