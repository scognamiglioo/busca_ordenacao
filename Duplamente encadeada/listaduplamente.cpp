#pragma once
#include <stdlib.h>
#include <stdio.h>
#include "listaduplamente.h"


typedef struct no{
    int valor;
    struct no *ant;
    struct no *prox;
}No;

typedef struct lista{
    No *inicio;
    No *fim;
}Lista;     


void inicializar(Lista *l){
    l->inicio = NULL; //inicializa a lista como vazia
    l->fim = NULL; //inicializa a lista como vazia
}

   
void gerarListaAleatoria(Lista *l, int n,int range1, int range2){
    for(int i = 0; i < n; i++){
        insere(l, rand() % (range2 - range1 + 1) + range1); // sorteia entre o range1 e range2
    }       
}


void insere(Lista *l, int valor){
    No *novo = (No*)malloc(sizeof(No)); // alocando para cada nó 
    novo->valor = valor; // valor do nó
    novo->ant = l->fim; // o novo nó aponta para o fim da lista
    novo->prox = NULL; // o novo nó aponta para o próximo nó
    l->fim->prox = novo; // o último nó da lista aponta para o novo nó
    l->fim = novo; // o novo nó se torna o último nó da lista
}   


void inserePosicao(Lista *l, int valor, int posicao){
    No *novo = (No*)malloc(sizeof(No)); // alocando para cada nó 
    novo->valor = valor; // valor do nó
    No *aux = l->inicio; // aux aponta para o início da lista
    for(int i = 0; i < posicao; i++){
        aux = aux->prox;
    }
    novo->ant = aux->ant; // o novo nó aponta para o nó anterior do aux 
    aux->ant->prox = novo; // o nó anterior do aux aponta para o novo nó
    novo->prox = aux; // o novo nó aponta para o aux
    aux->ant = novo; // o aux aponta para o novo nó

    
}   


void swapPosicao(Lista *l, int posicao1, int posicao2){
    No *aux1 = l->inicio; // aux1 aponta para o início da lista
    No *aux2 = l->inicio; // aux2 aponta para o início da lista
    for(int i = 0; i < posicao1; i++){  // loop para achar pos1 
        aux1 = aux1->prox;
    }
    for(int i = 0; i < posicao2; i++){ // loop para achar pos2
        aux2 = aux2->prox;
    }

    //troca aux1 e aux2
    int aux = aux1->valor;
    aux1->valor = aux2->valor;
    aux2->valor = aux;
}   

void buscaValor(Lista *l, int valor){
    No *aux = l->inicio; // aux aponta para o início da lista
    int posicao = 0;
    int acessos = 1; // primeiro acesso ao apontar para l->inicio
    
    while(aux != NULL){ // para cada acesso ao aux e aux->valor
        acessos += 2;
        if(aux->valor == valor){
            printf("Valor %d encontrado na posicao %d\n", valor, posicao);
            printf("Numero de acessos: %d\n", acessos);
            return;
        }
        aux = aux->prox; // mais um acesso ao aux->prox
        acessos++;
        posicao++;
    }
    
    printf("Valor %d nao encontrado na lista\n", valor);
    printf("Numero de acessos: %d\n", acessos);
    return;
}   

void buscarMenorValor(Lista *l){
    No *aux = l->inicio;
    No *menor = l->inicio;
    int posicao = 0;
    int posicaoMenor = 0;
    int acessos = 1; // primeiro acesso 
    
    while(aux != NULL){
        acessos += 2; // acesso ao aux e aux->valor
        if(aux->valor < menor->valor){
            menor = aux;
            posicaoMenor = posicao;
        }
        aux = aux->prox;
        acessos++; // acesso ao aux->prox
        posicao++;
    }

    printf("Menor valor: %d na posicao %d\n", menor->valor, posicaoMenor);
    
    // Mostrar predecessor se não for primeira posição
    if(posicaoMenor > 0){
        acessos += 2; // acesso ao menor->ant e menor->ant->valor
        printf("Predecessor: %d\n", menor->ant->valor);
    } else {
        printf("Nao ha predecessor (primeira posicao)\n");
    }
    
    printf("Numero de acessos: %d\n", acessos);
}

void imprimeLista(Lista *l){
    No *aux = l->inicio; // aux aponta para o início da lista
    while(aux != NULL){
        printf("%d ", aux->valor);
    }
}   

void imprimeListaInversa(Lista *l){
    No *aux = l->fim; // aux aponta para o fim da lista
    while(aux != NULL){
        printf("%d ", aux->valor);
    }
}   



