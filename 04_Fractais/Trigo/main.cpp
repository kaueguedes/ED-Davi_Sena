#include <lib/pen.h>



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

void fractal(){
    Pen p(800, 600);
    p.setThickness(1);
    //coloca o pincel na posicao x 300 y 500
    int x = 400;
    int y = 590;
    int tam = 80;
    p.setXY(x, y);

    //faz o pincel apontar pra direita
    //p.setHeading(90);
    //se speed = 0 entao ele faz o mais rapido possivel
    //se foi a partir de 1 ele controla a velocidade
    p.setSpeed(50);
    p.setColor(sf::Color::Yellow);
//    embuarvore(p, tam);
//    reflorestamento(p, x, tam);
    for(int t = 1; t <= 4;t++){
        p.setHeading(90);
        trigo(p, tam, t);
        p.setHeading(35);
        trigo(p, tam, t);
        p.setHeading(145);
        trigo(p, tam, t);
        //triangulo(p, 400);
        //espera clicar no botao de fechar

    }
    p.wait();
}

int main(){
    fractal();
    return 0;
}
