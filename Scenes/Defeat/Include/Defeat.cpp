//
// Created by chip on 08/07/18.
//

#include "Defeat.h"

int Defeat::Draw(RenderWindow &window, Event &evento) {

    Soundtrack.openFromFile("../Scenes/Defeat/Sounds/Better Luck Next Time (VA-11 HALL-A).ogg");
        Soundtrack.play();

    Texture UPCTexture;
        UPCTexture.loadFromFile("../Scenes/Defeat/Graphics/UPC.png");
    Sprite UPC(UPCTexture);
        UPC.setPosition(400,300);

    Font LetterFont;
        LetterFont.loadFromFile("../Scenes/Defeat/Fonts/alterebro-pixel-font.ttf");
    Text Talento;
        StylizeText(Talento,LetterFont,"Trasladas tu talento?",500,100);
    Text Continuar;
        StylizeText(Continuar,LetterFont,"Intenta de nuevo   Presiona Z",450,500);


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
            window.draw(UPC);
            window.draw(Talento);
            window.draw(Continuar);
            window.display();
        }
    }
}

void Defeat::StylizeText(Text &texto, Font &Letterfont, string Text, int x, int y) {
    texto.setFont(Letterfont);
    texto.setFillColor(Color::White);
    texto.setCharacterSize(70);
    texto.setString(Text);
    texto.setPosition(x,y);
}
