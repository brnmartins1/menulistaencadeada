#include <iostream>
#include <new>
#include <string>
#include <stdlib.h>

using namespace std;

void limpa(){
    system("CLS");
    }

struct pessoa{
    int rg;
    string nome;
    struct pessoa *proximo;
    };

int retornatam(pessoa *ponteiroen){
if(ponteiroen->nome ==""){
    return 0;
}
int tamanho = 0;

//  Cursor auxiliar
    pessoa *p = ponteiroen;

while(p != NULL){

    p = p->proximo;

    tamanho++;
}
    return tamanho;

}

void imprimir(pessoa *ponteiroen){
if(retornatam(ponteiroen)== 0){

    cout<<"Lista v�zia\n\n";
}else{
    int i;
    pessoa *p = ponteiroen;

    while(p != NULL){
        cout<<"Nome:"<<p->nome<<", RG:"<<p->rg<<"\n\n";

        p = p->proximo;
    }
}

}

void adccomeco(pessoa *&ponteiroen, string nome, int rg){

    pessoa *novoValor = new pessoa;
    novoValor->nome = nome;
    novoValor->rg = rg;
    novoValor->proximo = ponteiroen;

//    Verifica se a lista est� vazia
    if(ponteiroen->nome == ""){
        novoValor->proximo = NULL;
    }else{
        novoValor->proximo = ponteiroen;
    }

    ponteiroen = novoValor;
}

void adcfim(pessoa *&ponteiroen, string nome, int rg){

    pessoa *novoValor = new pessoa;

    novoValor->nome = nome;
    novoValor->rg = rg;
    novoValor->proximo = NULL;

    pessoa *p = ponteiroen;

    while(p != NULL){
    if(p->proximo == NULL){

        p->proximo = novoValor;
        return;
}
    p = p->proximo;
}
}

void adcposicao(pessoa *&ponteiroen, string nome, int rg, int posicao){

    pessoa *novoValor = new pessoa;

    novoValor->nome = nome;
    novoValor->rg = rg;
    novoValor->proximo = NULL;

    pessoa *p = ponteiroen;

    int cont = 0;

    while(cont <= posicao){
//       Para de percorrer a lista auando chega na posi��o anterior � desejada
        if(cont == posicao - 1){

//            Auxiliar
        pessoa *aux = new pessoa;

//        Armazena o proximo valor
        aux->proximo = p->proximo;

//        Coloca o novo valor como o proximo
        p->proximo = novoValor;

//        Faz com que o novo valor aponte para o proximo
        novoValor->proximo = aux->proximo;



        }

    p = p->proximo;
    cont ++;

    }

}

void removeinicio(pessoa *&ponteiroen){
if(ponteiroen->proximo == NULL){

    pessoa *novoValor = new pessoa;

    novoValor->nome = "";
    novoValor->rg = 0;
    novoValor->proximo = NULL;

    ponteiroen = novoValor;

}else{
     ponteiroen = ponteiroen->proximo;
}
}

void removefim(pessoa *&ponteiroen){


        pessoa *p = new pessoa;
        pessoa *aux = new pessoa;

        p = ponteiroen;

//      Percorre a lista
        while(p->proximo != NULL){
        aux = p;
        p = p->proximo;

}

//      Muda o final da lista para o penultimo elemento
        aux->proximo = NULL;

}

void removeposicao(pessoa *&ponteiroen, int posicao){

pessoa *p = ponteiroen;

int cont = 0;

while(cont <= posicao){
    if(cont == posicao -1){

//        Cria um auxiliar
        pessoa *aux = new pessoa;

//       Auxiliar recebe o valor que sera descartado
        aux = p->proximo;

//        Faz com que o pr�ximo pule um elemento;
        p->proximo = aux->proximo;

        free(aux);




    }
//        Realiza uma movimenta��o
        p = p->proximo;
        cont++;

}

}

string buscarg(pessoa *&ponteiroen, int rg){

//    Caso n�o exista nenhum nome ligado ao rg procurado
    string nome ="N�o encontrado";

    pessoa *p = ponteiroen;
//    Percorre a lista � procura do nome ligado ao rg
    while(p != NULL){
    if(p->rg == rg){

        nome = p->nome;

        return nome;

    }

    p = p->proximo;
}

    return nome;

}

int main(){

setlocale(LC_ALL,"");

int funcaodesejada = 1;


    pessoa *ponteiroen = new pessoa;
    ponteiroen->nome = "";
    ponteiroen->rg = 0;
    ponteiroen->proximo = NULL;

   //Cria o primeiro valor
    pessoa *novoprivalor = new pessoa;
    novoprivalor->nome = "Jo�o";
    novoprivalor->rg = 123;
    novoprivalor->proximo = NULL;

    //Transforma o ponteiro do inicio da lista no novo valor
    ponteiroen = novoprivalor;

    //Cria o segundo valor.

    pessoa *novosegvalor = new pessoa;
    novosegvalor->nome = "Jos�";
    novosegvalor->rg = 312;
    novosegvalor->proximo = NULL;

    novoprivalor->proximo = novosegvalor;



    while(funcaodesejada < 9 && funcaodesejada > 0){


        cout <<"\t\t\nOpera��es \n\n";
        cout <<"1 - Inser��o de um node no in�cio da lista.\n";
        cout <<"2 - Inser��o de um node no fim da lista.\n";
        cout <<"3 - Inser��o de um node na posi��o desejada.\n";
        cout <<"4 - Remo��o do node no in�cio da lista.\n";
        cout <<"5 - Remo��o do node no fim da lista.\n";
        cout <<"6 - Remo��o do node na posi��o desejada.\n";
        cout <<"7 - Procurar um node pelo campo RG.\n";
        cout <<"8 - Imprimir a lista.\n";
        cout <<"9 - Sair do sistema.\n";
        cout <<"\n\nTamanho �tual: "<<retornatam(ponteiroen)<<"\n\n\n";
        cout <<"Escolha uma op��o e aperte ENTER.\n";
        cin >> funcaodesejada;




        limpa();


        int rg, posicao;
        string nome;

        switch(funcaodesejada){
        case 1:
            cout <<"Fun��o escolhida: 1 - Inser��o de um node no in�cio da lista.\n\n";
            cout <<"Insira o nome:";
            cin >>nome;
            cout <<"Insira o rg:";
            cin >>rg;
            adccomeco(ponteiroen, nome, rg);

            break;
        case 2:
            cout <<"Fun��o escolhida: 2 -   Inser��o de um node no fim da lista.\n\n";
            cout <<"Insira o nome:";
            cin >>nome;
            cout <<"Insira o rg:";
            cin >>rg;
            if(retornatam(ponteiroen) == 0){

            adccomeco(ponteiroen, nome, rg);
            }
            else{
            adcfim(ponteiroen, nome, rg);
            }
            break;
        case 3:
            cout <<"Fun��o escolhida: 3 -   Inser��o de um node na posi��o desejada.\n\n";
            cout<<"\nInsira a posi��o desejada:";
            cin>>posicao;
            cout <<"\nInsira o nome:";
            cin >>nome;
            cout <<"\nInsira o rg:";
            cin >>rg;
            if(posicao == 0){

                adccomeco(ponteiroen,nome,rg);
            }
            else if(posicao == retornatam(ponteiroen) -1){

                    adcfim(ponteiroen,nome,rg);
                }
            else{
                    adcposicao(ponteiroen,nome,rg,posicao);
                    }
            break;
        case 4:
            cout <<"Fun��o escolhida: 4 -   Remo��o do node no in�cio da lista.\n\n";
                    removeinicio(ponteiroen);
            break;
        case 5:
            cout <<"Fun��o escolhida: 5 -   Remo��o do node no fim da lista.\n\n";
                   if(retornatam(ponteiroen)== 1){
                    removeinicio(ponteiroen);
                   }else{
                       removefim(ponteiroen);
                   }
            break;
        case 6:
            cout <<"Fun��o escolhida: 6 -   Remo��o do node na posi��o desejada.\n\n";
                    cout<<"Insira a posi��o do node que deseja remover:";
                    cin>>posicao;
                    if(posicao== 0){
                    removeinicio(ponteiroen);
                   }else if(posicao ==retornatam(ponteiroen)- 1){
                       removefim(ponteiroen);
                   }else{
                        removeposicao(ponteiroen, posicao);
                    }
            break;
        case 7:
            cout <<"Fun��o escolhida: 7 -   Procurar um node pelo campo RG.\n\n";
                    cout <<"Insira o rg que deseja procurar:";
                    cin >>rg;
                    cout<<"\n\nO nome do portador do rg � "<<buscarg(ponteiroen, rg)<<"\n\n";
            break;

        case 8:
            cout <<"Fun��o escolhida: 8 - Imprimir a lista.\n\n";
                imprimir(ponteiroen);

            break;

            }
    }

return 0;
}
