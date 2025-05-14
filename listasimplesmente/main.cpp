#include "listasimplesmente.h"

using namespace std;


int main(){

    //Lista *lista = inicializar();
    


    /* 
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

    */

    int escolhaInicial;
    cout << "Escolha como criar a lista:" << endl;
    cout << "1 - Inserir lista " << endl;
    cout << "2 - Gerar lista aleatória" << endl;
    cout << "Opcao: ";
    cin >> escolhaInicial;

    Lista *lista = inicializar();  

    if(escolhaInicial == 1){
       int valor;
    cin >> valor;
    int n1;
    
    

    //ler lista 
    for(int i = 0; i < valor; i++){
        cin >> n1;
        inserir(lista, n1);  
    }

    
    }
    int n;
    if(escolhaInicial == 2){

        cout << "Digite o tamanho da lista: ";
        cin >> n;
        cout << "Digite o intervalo dos números (min max): ";
        int min, max;
        cin >> min >> max;
        
        
        

        gerarListaAleatoria(lista, n, min, max);
        cout << "Lista aleatória gerada: ";
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
                    inserePosicao(lista, valor, posicao);
                    break;
                case 2:
                    int pos1, pos2;
                    cout << "Digite as posições para fazer o swap: ";
                    cin >> pos1 >> pos2;
                    swapPosicao(lista, pos1, pos2);
                    break; 
                case 3:
                    int valorProcurado;
                    cout << "Digite o valor a ser procurado: ";
                    cin >> valorProcurado;
                    buscaValor(lista, valorProcurado);
                    break;
                case 4:
                    buscaMenorValor(lista);
                    break;
                case 5:
                    imprimeLista(lista);
                    break;
                case 6:
                    imprimeListaInversa(lista);
                    break;
                case 0:
                    cout << "Saindo do programa..." << endl;
                    break;
                default:
                    cout << "Opção inválida. Tente novamente." << endl;
                
            }
        }while(opcao != 0);
} 
   






    


    
    
    



   

