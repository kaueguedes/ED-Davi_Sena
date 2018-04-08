#include <lib/pen.h>



void floquinho(Pen &p, int lado){

    float ang = 72;
    float dec = 0.38;

    if(lado < 1){
        return;
    }

    for(int i = 0; i < 5; i++){
       p.walk(lado);
       floquinho(p, lado*dec);
       p.walk(-lado);
       p.right(ang);
    }



}

void triangulo(Pen &p, int lado){
    if(lado < 50)
        return;
    for(int i = 0; i < 3; i++){
        p.walk(lado);
        p.left(120);
        triangulo(p, lado/2);
    }
}


void trigo(Pen& p, int lado, int t){
    if(lado<1){
           return;
       }
    float ang = 35;
    float dec = 0.30;
    int ramos = t;

    for(int r = 0; r < ramos; r++){
        p.walk(lado);
        p.right(ang);
        trigo(p, lado * dec, t);
        p.left(ang*2);
        trigo(p, lado * dec, t);
        p.right(ang);
    }
    p.walk(-lado*ramos);
}

void embuarvore(Pen& p, int lado){
    p.setSpeed(120);
    float ang = 35;
    float dec = 0.75;
   //lado -= (p.rand() % 7 - 3);
    if(lado < 10)
        return;
    //p.setColor(rand() % 255, rand() % 255, rand() % 255);
    p.walk(lado);
    p.right(ang);
    embuarvore(p, lado * dec);
    p.left(ang);
    embuarvore(p, lado * dec);
    p.left(ang);
    embuarvore(p, lado * dec);
    p.right(ang);
    p.walk(-lado);
}
void reflorestamento(Pen& p, int x, int tam){
    if(tam < 30){
        return;
    }
    p.setSpeed(60);
    p.setXY(x,500);
    embuarvore(p, tam);
    reflorestamento(p, (x - 130), (tam - 25));
    reflorestamento(p, (x + 130), (tam - 25));

}

void fractal(){
    Pen p(800, 600);
    p.setThickness(1);
    //coloca o pincel na posicao x 300 y 500
    int x = 400;
    int y = 300;
    int tam = 80;
    p.setXY(x, y);

    //faz o pincel apontar pra direita
    p.setHeading(90);
    p.setSpeed(40);
    //se speed = 0 entao ele faz o mais rapido possivel
    //se foi a partir de 1 ele controla a velocidade

    //FLOQUINHO
    p.setColor(sf::Color::Cyan);
    floquinho(p, tam);

    p.wait(2);

    p.clear();

    p.wait(2);
    //TRIGO
    p.setXY(400, 500);
    p.setColor(sf::Color::Yellow);
    for(int t = 1; t <= 4;t++){
        p.setHeading(90);
        trigo(p, tam, t);
        p.setHeading(35);
        trigo(p, tam, t);
        p.setHeading(145);
        trigo(p, tam, t);
    }
    p.wait(2);

    p.clear();

    p.wait(2);
    //ARVORE
    p.setColor(sf::Color::Green);
    p.setHeading(90);
    p.setSpeed(80);

    embuarvore(p, tam);
    reflorestamento(p, x, tam);


    p.wait();
}

int main(){
    fractal();
    return 0;
}
