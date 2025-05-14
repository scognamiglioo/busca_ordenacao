#pragma once

#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct no{
    int valor;
    struct no *prox;
}No;

typedef struct lista{
    No *cabeca;
}Lista;


Lista *inicializar();
void inserir(Lista *lista, int valor);
void gerarListaAleatoria(Lista *lista, int n);
void inserePosicao(Lista *lista, int valor, int posicao);
void swapPosicao(Lista *lista, int posicao1, int posicao2);
void buscaValor(Lista *lista, int valor);
void buscaMenorValor(Lista *lista); 
void imprimeLista(Lista *lista);
void imprimeListaInversa(Lista *lista); 




  



















