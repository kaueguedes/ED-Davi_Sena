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


    p.wait();
}

int main(){
    fractal();
    return 0;
}
