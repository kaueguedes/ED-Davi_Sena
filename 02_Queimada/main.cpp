#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;


const int nc = 60;
const int nl = 20;

void mostrar(vector<string>& mat){
    cout << string(50, '\n');
    for(string s : mat)
        cout << s << endl;
    getchar();
}
//Constroi struct
struct Par{
    int l, c;
    Par (int l = 0, int c = 0){
        this->l = l;
        this->c = c;
    }
};
// pegar a vizinhança
vector <Par> getNeib(Par p){
    vector<Par> v;
    v.push_back(Par {p.l, p.c + 1});
    v.push_back(Par {p.l, p.c - 1});
    v.push_back(Par {p.l + 1, p.c});
    v.push_back(Par {p.l - 1, p.c});
    return v;
}

vector<Par> misturar(vector<Par> vet){
    for(int i  = 0; i < (int) vet.size(); i++){

        int aleat = rand() % vet.size();

        std::swap(vet[i], vet[aleat]);
    }
    return vet;
}



int queimar(vector<string> &mat, int l, int c, int contagem){
    if(l < 0 || l >= nl)
        return 0;
    if(c < 0 || c >= nc)
        return 0;
    if(mat[l][c] != '#')
        return 0;

    int cont = 0;

    mat[l][c] = '0' + contagem%10;
    cont = cont +1;

    mostrar(mat);

    for(Par p : misturar(getNeib(Par(l, c)))){
        cont = cont + queimar(mat, p.l, p.c, contagem + 1);
    }
    mat[l][c] = '_';

    mostrar(mat);

    return cont;
}


int main()
{
    srand(time(NULL));
    //os containers tem uma construção padrao
    //container<tipo> nome(qtd, elemento_default)
    //cria um vetor de string
    //com nl elementos da string default
    //a string default sao 30 char ' '
    vector<string> mat(nl, string(nc, ' '));
    int narvores = nl * nc * 1.5;
    //insere varias arvores em lugares aleatorios
    //muitas serao superpostas
    for(int i = 0; i < narvores; i++){
        mat[rand() % nl][rand() % nc] = '#';
    }

    mostrar(mat);
    int total = queimar(mat, 0, 0, 0);
    cout << total << " arvores queimaram\n";

    return 0;
}
