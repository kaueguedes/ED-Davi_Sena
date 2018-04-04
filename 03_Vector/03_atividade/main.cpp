#include <iostream>
#include <vector>

using namespace std;

struct Vetor{
    int * _data;//bloco de dados
    int _capacidade;//tamanho maximo do vetor
    int _size; //quantos elementos estao inseridos

    Vetor(int capacidade){
        this->_capacidade = capacidade;
        this->_size = 0;
//        this->data = (int*) malloc(capacidade * 4);//retorno lixo
        this->_data = new int[capacidade];//retorno zerado
    }
    void push_back(int value){
        if(this->_size == this->_capacidade)
            return;
            //this->reserve(2 * _capacitade);
        this->_data[this->_size] = value;
        this->_size += 1;
    }
    void pop_back(){
        if(this->_size == 0)
            return;
        this->_data[_size] = 0;
        this->_size -= 1;
    }

    //retornar a refencia à variavel dessa posicao
    int& at(int indice){
        if(indice>=this->_size)
            return 0;//tem que ser lançada uma exceção, n sei fazer!!

        return this->_data[indice];
    }

    int& front(){
        if(this->_size != 0){
            return this->_data[0];
        }
        return; //se n for n sei oq retornar
    }
    int& back(){
        if(this->_size != 0){
            return this->_data[this->_size - 1];
            }
        return;// se n for n sei oq retornar
        }
    int * begin(){
        if(this->_size != 0){
            return &this->_data[0];
        }
        return;// see n for n sei oq retornar
    }
    int * end(){
        if(this->_size != 0){
            return &this->_data[this->_size];
        }
        return  begin();
    }
    int size(){
        return this->_size;
    }

    int capacity(){
        return this->_capacidade;
    }

    void reserve(int capacity){
        if(this->_capacidade > this->_size){
            return;
        }
        Vetor<string> vet_novo = new Vetor<string>;
        vet_novo._capacidade = this->_capacidade*2;
        vet_novo._data = this->_data;
        vet_novo._size = this->_size;
        for(int j = 0; j < (this->_capacidade); j++){
            vet_novo._data[j] = _data[j];
        }
        this->Vetor = vet_novo;
//        salva o bloco antigo em algum lugar
//        pede uma novo bloco de dados
    }


};

#include <vector>
int main()
{
    vector<int> v;
    v.push_back(1);//1 elemento, 1 de capacidade
    v.push_back(3);//2 elementos,2 de cap
    v.push_back(5);//3 elementos,4 cap

    v.reserve(100);
    v.size();// 3- elementos
    v.capacity();//100 - capacidade de armazenamento de elementos

    //lvalue
    v.front();//1 -> primeiro valor
    v.back();//5 -> ultimo valor
    v.front() = 6;

    //posicoes - iteradores
    //não são ponteiro, mas se comportam como se fosse
    v.begin();//iterador pro primeiro
    v.end();//iterador pro abismo

    vector<string> frutas(5, "bananas");
    vector<string> f2(frutas);
    list<float> lfloat(10, 0.1f);

//    list<int> list = {3, 2, 5, 4, 3, 6, 8, 6};
//    for(int x : list)
//        cout << x << " ";
//    for(auto it = list.begin(); it != list.end(); it++)
//        cout << *it << " ";

    Vetor pivet(5);
    pivet.push_back(4);
    pivet.push_back(2);
    pivet.push_back(7);
    cout << pivet.at(2)
    pivet.at(2) = 9;

    int x = 3;
    int y = 2;
    x = y;
    int z = x;
    //lvalue & significa referencia
    int& a = x;



    cout << "Hello World!" << endl;
    return 0;
}
