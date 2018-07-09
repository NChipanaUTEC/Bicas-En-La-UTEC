//
// Created by chip on 23/06/18.
//

#include "BossScreen.h"


int BossScreen::Draw(RenderWindow &window, Event &evento, GenerarPersonaje& gp) {
     srand(time(nullptr));

     SetPena();
     gp.GetDataProta(ProtaData);

     Texture BGTexture;
        BGTexture.loadFromFile("../Scenes/BossScreen/Graphics/auditorioFight.png");
        Sprite Background(BGTexture);
        Background.setScale(5,4.9);
        Background.setPosition(0,0);
     Texture ProtaTextura;
        ProtaTextura.loadFromFile("../Scenes/BossScreen/Graphics/yosuke.png");
     Sprite Protagonista(ProtaTextura);
        Protagonista.setPosition(200,80);

     Texture EnemigoTextura;
        EnemigoTextura.loadFromFile("../Scenes/BossScreen/Graphics/PenaFight.png");
     Sprite Enemigo(EnemigoTextura);
        Enemigo.setPosition(575,130);
        Enemigo.setScale(0.1,0.1);

     CircleShape Triangle(10,3);
        Triangle.rotate(90);
        Triangle.setFillColor(Color::White);
        Triangle.setPosition(TrianglePosX,TrianglePosY);
        Triangle.setScale(1.8,1.8);

        RectangleShape HPProta(Vector2f(20,ProtaData[0]));
        HPProta.setFillColor(Color::Green);
        HPProta.setOutlineColor(Color::White);
        HPProta.setOutlineThickness(3);
        HPProta.setPosition(1000,100);
        HPProta.setScale(2,5);

        RectangleShape HPEnemigo(Vector2f(20,(100*EneData[0])/1000));
        HPEnemigo.setFillColor(Color::Green);
        HPEnemigo.setOutlineColor(Color::Red);
        HPEnemigo.setOutlineThickness(3);
        HPEnemigo.setPosition(1150,100);
        HPEnemigo.setScale(2,5);

        Font Letterfont;
        Letterfont.loadFromFile("../Scenes/BossScreen/Fonts/alterebro-pixel-font.ttf");
        Text Attack;
        StylizeText(Attack,Letterfont,"ATTACK",110,510);
        Text Defend;
        StylizeText(Defend,Letterfont,"ABSORB",110,600);
        Text Run;
        StylizeText(Run,Letterfont,"RUN",410,600);
        Text HPP;
        StylizeText(HPP,Letterfont,to_string(ProtaData[0]),990,5);
        Text HPE;
        StylizeText(HPE,Letterfont,to_string(EneData[0]),1150,5);

        Soundtrack.openFromFile("../Scenes/BossScreen/Sounds/Bicas.ogg");
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
                            ProtaTextura.loadFromFile("../Scenes/BossScreen/Graphics/yosuke.png");
                            Protagonista.setTexture(ProtaTextura);
                            if(TrianglePosY == 550){
                                TrianglePosY += 90;
                                Triangle.move(0,90);
                            }
                        }
                        if(evento.key.code == Keyboard::Up){
                            ProtaTextura.loadFromFile("../Scenes/BossScreen/Graphics/yosuke.png");
                            Protagonista.setTexture(ProtaTextura);
                            if(TrianglePosY == 640 && TrianglePosX != 400){
                                TrianglePosY -= 90;
                                Triangle.move(0,-90);
                            }
                        }
                        if(evento.key.code == Keyboard::Right){
                            ProtaTextura.loadFromFile("../Scenes/BossScreen/Graphics/yosuke.png");
                            Protagonista.setTexture(ProtaTextura);
                            if(TrianglePosX == 100 && TrianglePosY != 550){
                                TrianglePosX += 300;
                                Triangle.move(300,0);
                            }
                        }
                        if(evento.key.code == Keyboard::Left){
                            ProtaTextura.loadFromFile("../Scenes/BossScreen/Graphics/yosuke.png");
                            Protagonista.setTexture(ProtaTextura);
                            if(TrianglePosX == 400){
                                TrianglePosX-= 300;
                                Triangle.move(-300,0);
                            }
                        }
                        if(evento.key.code == Keyboard::Z){
                            ProtaTextura.loadFromFile("../Scenes/BossScreen/Graphics/yosuke_attack.png");
                            Protagonista.setTexture(ProtaTextura);
                            switch(TrianglePosY){
                                case(550):
                                    if(TrianglePosX == 100){
                                        FightRandom = random()%5+5;
                                        EneData[0] -= ProtaData[1]*(FightRandom/10)+EneData[2]*(FightRandom/10);
                                        FightRandom = random()%5+5;
                                        ProtaData[0] -= EneData[1]*(FightRandom/10)-ProtaData[2]*(FightRandom/10);
                                        HPProta.setSize(Vector2f(20,ProtaData[0]));
                                        HPP.setString(to_string(ProtaData[0]));
                                        HPEnemigo.setSize(Vector2f(20,EneData[0]));
                                        HPE.setString(to_string(EneData[0]));
                                        if(EneData[0]<= 0){
                                            XP();
                                            if(LVLUP()){
                                                gp.LVLPersonaje();
                                                Soundtrack.stop();
                                                return 2;
                                            }
                                            else{
                                                gp.UpdatePersonaje(ProtaData);
                                                Soundtrack.stop();
                                                return 0;
                                            }
                                        }
                                        else if(ProtaData[0] <= 0){
                                            Soundtrack.stop();
                                            return 1;
                                        }
                                        break;
                                    }
                                case(640):
                                    if(TrianglePosX == 400){
                                        Soundtrack.stop();
                                        return 0;
                                    }
                                    else{
                                        DefenseRandom = rand()%3;
                                        switch(DefenseRandom){
                                            default:
                                                ProtaData[0] *= 0.8;
                                                break;
                                            case 1:
                                                ProtaData[0] *= 1.8;
                                                break;
                                        }
                                        HPP.setString(to_string(ProtaData[0]));
                                        HPProta.setSize(Vector2f(20,ProtaData[0]));
                                        if(EneData[0]<= 0){
                                            XP();
                                            if(LVLUP()) {
                                                gp.LVLPersonaje();
                                                Soundtrack.stop();
                                                return 0;
                                            }
                                            else{
                                                gp.UpdatePersonaje(ProtaData);
                                                Soundtrack.stop();
                                                return 0;
                                            }
                                        }
                                        else if(ProtaData[0] <= 0){
                                            Soundtrack.stop();
                                            return 1;
                                        }
                                        else if(EneData[0] <= 0){
                                            Soundtrack.stop();
                                            return 2;
                                        }
                                        break;
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
                window.draw(Run);
                window.draw(Enemigo);
                window.draw(HPProta);
                window.draw(HPEnemigo);
                window.draw(HPP);
                window.draw(HPE);
                window.display();
            }
        }
}

void BossScreen::StylizeText(Text &texto,Font& Letterfont,string Text,int x,int y) {
    texto.setFont(Letterfont);
    texto.setFillColor(Color::White);
    texto.setCharacterSize(70);
    texto.setString(Text);
    texto.setPosition(x,y);
}

void BossScreen::XP() {
    ProtaData[5] += (EneData[1]+EneData[2])*2;
}

bool BossScreen::LVLUP() {
    if(ProtaData[5] > ProtaData[6]){
        return true;
    }
    return false;
}

void BossScreen::SetPena() {
    EneData[0] = 10;
    EneData[1] = 10;
    EneData[2] = 100;
    EneData[3] = 100;
    EneData[4] = 10;
}
