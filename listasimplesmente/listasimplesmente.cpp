#include "listasimplesmente.h"
#include <cstdio> // Added for std::printf
#include <time.h>

using namespace std;

Lista *inicializar(){
    Lista *lista = (Lista*)malloc(sizeof(Lista)); //alocação de memória para a lista
    lista->cabeca = NULL; //inicialização da cabeça da lista
    return lista; //retorna a lista inicializada
}

void inserir(Lista *lista, int valor){
    if(lista->cabeca == NULL){
        No *novo = (No*)malloc(sizeof(No)); //aloca memoria para CADA novo no inserido
        novo->valor = valor; //valor
        novo->prox = NULL; //o novo no aponta para NULL
        lista->cabeca = novo; //o novo no se torna a cabeça da lista
    }
    else{
        No *aux = lista->cabeca; //aux
        while(aux->prox != NULL){ //enquanto o proximo não for NULL
            aux = aux->prox; // no prox 
        }
        No *novo = (No*)malloc(sizeof(No)); //aloca memoria 
        novo->valor = valor; //valor
        novo->prox = NULL; //o novo no aponta para NULL 
        aux->prox = novo; //o novo no se torna o proximo da lista   
    }

}   
void gerarListaAleatoria(Lista *lista, int n,int range1, int range2){
    srand(time(NULL)); // Inicializa gerador de números aleatórios
    for(int i = 0; i < n; i++){
        int valorAleatorio = rand() % (range2 - range1 + 1) + range1; // Gera número entre range1 e range2
        inserir(lista, valorAleatorio);
    }
}
void inserePosicao(Lista *lista, int valor, int posicao){
    if(posicao == 0){
        inserir(lista, valor); //insere no inicio
    }
    else{
        No *aux = lista->cabeca; //aux APONTA para o primeiro 
        for(int i = 0; i < posicao - 1 && aux != NULL; i++){ //percorre a lista até a posicao 
            aux = aux->prox; // aux passa de posição para posição 
        }
        if(aux != NULL){
            No *novo = (No*)malloc(sizeof(No)); //aloca memoria para o novo no
            novo->valor = valor; //valor
            novo->prox = aux->prox; //o novo no aponta para o proximo da lista
            aux->prox = novo; //o novo no se torna o proximo da lista
        }
        else{   
            cout << "Posicao nao pode ser inserida";
        }   
    }
}

void swapPosicao(Lista *lista, int posicao1, int posicao2){
    if(posicao1 == posicao2){ // N precisa trocar
        return;
    }
    No *aux1 = lista->cabeca; 
    No *aux2 = lista->cabeca; //aux1 e aux2 recebem o primeiro nó 
    for(int i = 0; i < posicao1 && aux1 != NULL; i++){ //percorre a lista até a posicao1
        aux1 = aux1->prox; 
    }
    for(int i = 0; i < posicao2 && aux2 != NULL; i++){ //percorre a lista até a posicao2
        aux2 = aux2->prox; 
    }           
    
    int temp = aux1->valor; 
    aux1->valor = aux2->valor; 
    aux2->valor = temp; 

    // std::swap(aux1->valor, aux2->valor);

}

void buscaValor(Lista *lista, int valor){
    No *aux = lista->cabeca; //inicio 
    while(aux != NULL){
        if(aux->valor == valor){ //se o valor for encontrado
            printf("Valor encontrado: %d", valor);
        }
        aux = aux->prox; //aux passa para o proximo nó
    }
    cout << "Valor nao encontrado"; 

}       


void buscaMenorValor(Lista *lista){
    No *aux = lista->cabeca; 
    int menorValor = aux->valor; 
    int posicaoAtual = 0; 
    int posicaoMenorIndice = 0; 
    int numAcessos = 0; // numero de acessos    

    if (lista->cabeca == NULL) { // verificando se a lista está vazia 
        cout << "Lista vazia";  
        cout << "Numero de acessos: " << numAcessos << endl;
        cout << "Predecessor: Nao existe" << endl;
        cout << "Posicao: Nao existe" << endl;
        return;
    }

    // acessando o primeiro nó
    menorValor = lista->cabeca->valor;
    posicaoAtual = 0;
    posicaoMenorIndice = 0;
    numAcessos = 1;
    aux = lista->cabeca;

    while(aux != NULL){
        if(aux->valor < menorValor){ 
            menorValor = aux->valor;
            posicaoMenorIndice = posicaoAtual;
        }
        aux = aux->prox;
        posicaoAtual++;
        numAcessos++;
    }

        No *predecessor = lista->cabeca;
        for(int i = 0; i < posicaoMenorIndice - 1; i++) { // percorre ate o menor indice e retorna o valor do predecessor
            predecessor = predecessor->prox;
        }
        cout << "Predecessor do menor valor: " << predecessor->valor << endl;
    

    cout << "Menor valor: " << menorValor << endl;
    cout << "Posicao: " << posicaoMenorIndice << endl;
    cout << "Numero de acessos: " << numAcessos-1 << endl; // -1 porque roda 1 vez a mais o numAcesoss++


  
}

void imprimeLista(Lista *lista){
    No *aux = lista->cabeca;
    while(aux != NULL){
        cout << aux->valor << " ";
        aux = aux->prox;
    }
}       

void imprimeListaInversa(Lista *lista){
    No *aux = lista->cabeca;
    while(aux != NULL){
        cout << aux->valor << " ";
        aux = aux->prox;
    }
}


