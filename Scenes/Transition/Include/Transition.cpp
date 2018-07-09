//
// Created by chip on 08/07/18.
//

#include "Transition.h"

int Transition::Draw(RenderWindow &window, Event &evento) {
    srand(time(nullptr));
    Font LetterFont;
        LetterFont.loadFromFile("../Scenes/Transition/Fonts/alterebro-pixel-font.ttf");

    Text Loading;
        StylizeText(Loading,LetterFont);
        Loading.setString("LOADING");
        Loading.setPosition(525,500);

    Text Quote;
    Text Author;
        StylizeText(Quote,LetterFont);
        StylizeText(Author,LetterFont);
        Quote.setPosition(200,250);
        Author.setPosition(600,300);
        StringRandom = rand()%4;
        switch (StringRandom){
            default:
                Quote.setString("Las preguntas estan en el Zemansky");
                Author.setString("-Pena 20XX");
                break;
            case 1:
                Quote.setString("Al susti con fe !");
                Author.setString("-Cachimbo que jalo con 10");
                break;
            case 2:
                Quote.setString("Chicos entendieron? Claro profe");
                Author.setString("-Cachimbo que no entendio");
                break;
            case 3:
                Quote.setString("Profe puedo ir al bano ?");
                Author.setString("-Cachimbo perdido");
                break;
        }
    while (window.isOpen()) {
        while (window.pollEvent(evento)) {
            switch(evento.type){
                case Event::KeyPressed:
                    if(evento.key.code == Keyboard::Z)
                        return 0;
            }
            window.clear();
            window.draw(Loading);
            window.draw(Quote);
            window.draw(Author);
            window.display();
        }
    }
}

void Transition::StylizeText(Text &text, Font& LetterFont) {
    text.setFont(LetterFont);
    text.setFillColor(Color::White);
    text.setCharacterSize(80);
}
