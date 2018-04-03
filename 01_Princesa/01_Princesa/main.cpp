#include <iostream>
#include <list>

using namespace std;



void rodar (list<int> &candidatos){
    candidatos.push_back(candidatos.front());
    candidatos.pop_front();
}

int main()
{
    int qtd = 0;
    int primeiro = 0;
    int saltos = 0 ;

    cout << "Total de loucos pela princesa????" << endl;
    cin >> qtd;

    cout << "Qual louco começa com a espada?? " << endl;
    cin >> primeiro;

    cout << "Quantos saltos pra alguem ser morto?? " << endl;
    cin >> saltos;


    list<int> candidatos;

    //Enumera
    for (int i = 1; i <= qtd; i++)
      candidatos.push_back(i);




    while (candidatos.front() != primeiro)
        rodar(candidatos);

    //Matadoro
    while (candidatos.size() > 1){
        for(int cont = 1; cont<=saltos; cont++ )
            rodar(candidatos);
            candidatos.pop_front();
        }

    cout << "Sobrevivente do massacre :" << endl << candidatos.front() << endl;

    return 0;
}

