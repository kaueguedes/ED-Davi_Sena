#include <lib/pen.h>


void embuarvore(Pen& p, int lado){
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
    if(tam < 50){
        return;
    }
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
    int y = 500;
    int tam = 100;
    p.setXY(x, y);

    //faz o pincel apontar pra direita
    p.setHeading(90);
    //se speed = 0 entao ele faz o mais rapido possivel
    //se foi a partir de 1 ele controla a velocidade
    p.setSpeed(1000);
    p.setColor(sf::Color::Green);
    embuarvore(p, tam);
    reflorestamento(p, x, tam);


    //espera clicar no botao de fechar
    p.wait();
}

int main(){
    fractal();
    return 0;
}
