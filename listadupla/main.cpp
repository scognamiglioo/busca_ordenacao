#include <stdio.h>
#include <stdlib.h>
#include "listaduplamente.h"
#include <iostream>

using namespace std;

int main(){

    Lista *l = (Lista*)malloc(sizeof(Lista));
    inicializar(l);

    /*int valor;
    // cin >> valor;
    // int n1;
    

    //ler lista 
    //for(int i = 0; i < valor; i++){
        //cin >> n1;
        //insere(l, n1);  
    //}

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
    
    Lista *listaAleatoria = (Lista*)malloc(sizeof(Lista));
    inicializar(listaAleatoria);

    gerarListaAleatoria(listaAleatoria, elementos, range1, range2);
    imprimeLista(listaAleatoria);

   //busca menor valor
   buscarMenorValor(listaAleatoria);

   //imprime lista inversa
   imprimeListaInversa(listaAleatoria);

   */

  
    int escolhaInicial;
    cout << "Escolha como criar a lista:" << endl;
    cout << "1 - Inserir lista " << endl;
    cout << "2 - Gerar lista aleatória" << endl;
    cout << "Opcao: ";
    cin >> escolhaInicial;

    if(escolhaInicial == 1){
       int valor;
    cin >> valor;
    int n1;
    

    //ler lista 
    for(int i = 0; i < valor; i++){
        cin >> n1;
        insere(l, n1);  
    }

     
    }
    int n;
    if(escolhaInicial == 2){

        cout << "Digite o tamanho da lista: ";
        cin >> n;
        cout << "Digite o intervalo dos números (min max): ";
        int min, max;
        cin >> min >> max;
        
        

        gerarListaAleatoria(l, n, min, max);
        cout << "Lista aleatória gerada!" << endl;

    }

        int opcao;

        do{
            cout << "\n------------ Operacoes ------------ " << endl;
            cout << "1 - Inserir um valor em uma posição especifica" << endl;  // operação 
            cout << "2 - Fazer Swap" << endl;
            cout << "3 - Procurar um valor na lista" << endl;
            cout << "4 - Procurar menor valor" << endl; // operação 6
            cout << "5 - Mostrar lista" << endl; // operação 7
            cout << "6 - Mostrar lista inversa" << endl; // operação 8
            cout << "0 - Sair do programa" << endl;
            cout << "Opçao: ";
            cin >> opcao;

            switch(opcao){
                case 1:
                    int valor, posicao;
                    cout << "Digite o valor e a posição: ";
                    cin >> valor >> posicao;
                    inserePosicao(l, valor, posicao);
                    break;
                case 2:
                    int pos1, pos2;
                    cout << "Digite as posições para fazer o swap: ";
                    cin >> pos1 >> pos2;
                    swapPosicao(l, pos1, pos2);
                    break; 
                case 3:
                    int valorProcurado;
                    cout << "Digite o valor a ser procurado: ";
                    cin >> valorProcurado;
                    buscaValor(l, valorProcurado);
                    break;
                case 4:
                    buscarMenorValor(l);
                    break;
                case 5:
                    imprimeLista(l);
                    break;
                case 6:
                    imprimeListaInversa(l);
                    break;
                case 0:
                    cout << "Saindo do programa..." << endl;
                    break;
                default:
                    cout << "Opção inválida. Tente novamente." << endl;
                
            }
        }while(opcao != 0);
    } 
   





