#pragma once
#include <stdlib.h>
#include <stdio.h>

typedef struct No{
    int valor;
    struct No *ant;
    struct No *prox;
}No;

typedef struct Lista{
    No *inicio;
    No *fim;
}Lista;

void inicializar(Lista *l);
void gerarListaAleatoria(Lista *l, int n, int range1, int range2);
void insere(Lista *l, int valor);
void inserePosicao(Lista *l, int valor, int posicao);
void swapPosicao(Lista *l, int posicao1, int posicao2);
void buscaValor(Lista *l, int valor);
void buscarMenorValor(Lista *l);
void imprimeLista(Lista *l);
void imprimeListaInversa(Lista *l);

