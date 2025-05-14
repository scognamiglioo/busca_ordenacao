#include "listaduplamente.h"
#include <stdlib.h>
#include <stdio.h>

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
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->ant = l->fim;
    novo->prox = NULL;
    if (l->fim == NULL) { // Lista vazia
        l->inicio = novo;
        l->fim = novo;
    } else {
        l->fim->prox = novo;
        l->fim = novo;
    }
}   


void inserePosicao(Lista *l, int valor, int posicao){
    if (l->inicio == NULL && posicao == 0) { // Inserção na lista vazia
        insere(l, valor);
        return;
    }
    No *aux = l->inicio;
    int i = 0;
    while (aux != NULL && i < posicao) {
        aux = aux->prox;
        i++;
    }
    if (aux == NULL && i == posicao) { // Inserção no final
        insere(l, valor);
        return;
    }
    if (aux == NULL) { // Posição inválida
        printf("Posição inválida para inserção!\n");
        return;
    }
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->ant = aux->ant;
    novo->prox = aux;
    if (aux->ant != NULL)
        aux->ant->prox = novo;
    else
        l->inicio = novo;
    aux->ant = novo;
}   


void swapPosicao(Lista *l, int posicao1, int posicao2){
    if (posicao1 == posicao2) return;
    No *aux1 = l->inicio;
    No *aux2 = l->inicio;
    int i = 0;
    while (aux1 != NULL && i < posicao1) {
        aux1 = aux1->prox;
        i++;
    }
    i = 0;
    while (aux2 != NULL && i < posicao2) {
        aux2 = aux2->prox;
        i++;
    }
    if (aux1 == NULL || aux2 == NULL) {
        printf("Posição inválida para swap!\n");
        return;
    }
    int aux = aux1->valor;
    aux1->valor = aux2->valor;
    aux2->valor = aux;
}   

void buscaValor(Lista *l, int valor){
    No *aux = l->inicio; // aux aponta para o início da lista
    int posicao = 0;
    int acessos = 0; // primeiro acesso ao apontar para l->inicio
    
    while(aux != NULL){ // para cada acesso ao aux e aux->valor
        acessos += 1;
        if(aux->valor == valor){
            printf("Valor %d encontrado na posicao %d\n", valor, posicao);
            printf("Numero de acessos: %d\n", acessos);
            return;
        }
        aux = aux->prox; // mais um acesso ao aux->prox
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
    int acessos = 0; // primeiro acesso 
    
    while(aux != NULL){
        acessos += 1; // acesso ao aux e aux->valor
        if(aux->valor < menor->valor){
            menor = aux;
            posicaoMenor = posicao;
        }
        aux = aux->prox;
         // acesso ao aux->prox
        posicao++;
    }

    printf("Menor valor: %d na posicao %d\n", menor->valor, posicaoMenor);
    
    // Mostrar predecessor se não for primeira posição
    if(posicaoMenor > 0){
    // acesso ao menor->ant e menor->ant->valor
        printf("Predecessor: %d\n", menor->ant->valor);
    } else {
        printf("Nao ha predecessor (primeira posicao)\n");
    }
    
    printf("Numero de acessos: %d\n", acessos);
}

void imprimeLista(Lista *l){
    No *aux = l->inicio;
    while(aux != NULL){
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}   

void imprimeListaInversa(Lista *l){
    No *aux = l->fim;
    while(aux != NULL){
        printf("%d ", aux->valor);
        aux = aux->ant;
    }
    printf("\n");
}   



