#pragma once

#include "listasimplesmente.h"

using namespace std;


int main(){

    Lista *lista = inicializar();
    
    // entrada = 10 / 8 1 3 4 3 6 10 8 9 1
    int valor;
    cin >> valor;
    int entrada;
    while(valor != 0){
        inserir(lista, entrada); //insere o valor na lista
        cin >> entrada;
        valor--;  
    }
    // testes 
    imprimeLista(lista); 

    // INSERIR NA POSICAO-valor 11-10  2-4 7-0
    inserePosicao(lista, 11, 10);
    inserePosicao(lista, 2, 4);
    inserePosicao(lista, 7, 0);


    imprimeLista(lista);   

    // PROCURAR valores com números de acessos (10,8,12) 
    buscaValor(lista, 10);
    buscaValor(lista, 8);
    buscaValor(lista, 12);

    //FAZER SWAP DE POSICOES (3-4) (0,6) (6,12)
    swapPosicao(lista, 3, 4);
    swapPosicao(lista, 0, 6);
    swapPosicao(lista, 6, 12);

    imprimeLista(lista);


    //BUSCAR MENOR VALOR
    buscaMenorValor(lista);

    imprimeLista(lista);

    //imprimir lista inversa

    imprimeListaInversa(lista);


    // LISTA ALEATORIA

    cout << "Digite o tamanho da lista aleatoria: " << endl;
    int tamanho;
    cin >> tamanho;
    
    Lista *listaAleatoria = inicializar();
    gerarListaAleatoria(listaAleatoria, tamanho);

    imprimeLista(listaAleatoria);
    
    // buscar menor valor
    buscaMenorValor(listaAleatoria);

    // imprimir lista inversa
    imprimeListaInversa(listaAleatoria);

    


    
    
    



   
    




}
