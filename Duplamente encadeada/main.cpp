#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "listaduplamente.h"
#include <iostream>

using namespace std;

int main(){

    Lista *l;
    inicializar(l);

    int valor;
    cin >> valor;
    int n1;
    

    //ler lista 
    for(int i = 0; i < valor; i++){
        cin >> n1;
        insere(l, n1);  
    }

    imprimeLista(l);


    // Inserir valor na posicao valor-posicao (11-10)(2-4)(7-0)
    inserePosicao(l, 11, 10);
    inserePosicao(l, 2, 4);
    inserePosicao(l, 7, 0);

    imprimeLista(l);

    // Buscar valor 10,8,12     - mostrando numeros de acessos
    buscaValor(l, 10);
    buscaValor(l, 8);
    buscaValor(l, 12);


    // Swap de posição  3-4,0-6,6-12
    swapPosicao(l, 3, 4);
    swapPosicao(l, 0, 6);
    swapPosicao(l, 6, 12);

    imprimeLista(l);

    // Buscar menor valor
    buscarMenorValor(l);

    //Lista inversa
    imprimeListaInversa(l);


    // LISTA ALEATORIA 

    cout << "Digite x de elementos e range sendo n até m ";
    int elementos, range1, range2;
    cin >> elementos;
    cin >> range1;
    cin >> range2;
    
    Lista *listaAleatoria;
    inicializar(listaAleatoria);

    gerarListaAleatoria(listaAleatoria, elementos, range1, range2);
    imprimeLista(listaAleatoria);

   //busca menor valor
   buscarMenorValor(listaAleatoria);

   //imprime lista inversa
   imprimeListaInversa(listaAleatoria);

  
    
    
    
    
    
    
    
    

}




