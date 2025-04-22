#include <iostream>
#include <fstream>
#include <cstdlib> // rand, srand
#include <ctime>   // time
using namespace std;

#include "listacontiguidade.h"

int main()
{
    int n;
    int *lista = nullptr;
    int escolhaInicial;

    cout << "Escolha como criar a lista:" << endl;
    cout << "1 - Carregar lista de um arquivo" << endl;
    cout << "2 - Gerar lista aleatória" << endl;
    cout << "Opcao: ";
    cin >> escolhaInicial;

    if (escolhaInicial == 1)
    {
        if (carregarLista("lista.txt", n, lista))
        {
            cout << "Lista carregada com sucesso:" << endl;
            for (int i = 0; i < n; ++i)
                cout << lista[i] << " ";
            cout << endl;
        }
        else
        {
            cout << "Erro ao carregar a lista" << endl;
            return 1;
        }
    }
    else if (escolhaInicial == 2)
    {
        cout << "Digite o tamanho da lista: ";
        cin >> n;
        cout << "Digite o intervalo dos números (min max): ";
        int min, max;
        cin >> min >> max;
        lista = new int[n];

        srand(static_cast<unsigned int>(time(0))); // Inicializa o gerador de números aleatórios
        for (int i = 0; i < n; i++)
        {
            lista[i] = rand() % (max - min + 1) + min; // rand - para gerar números aleatórios - max - min + 1 - para garantir que o número gerado esteja dentro do intervalo - +min - para garantir que o número gerado comece a partir do valor mínimo
        }

        cout << "Lista aleatória gerada: ";
        for (int i = 0; i < n; i++)
            cout << lista[i] << " ";
        cout << endl;
    }
    else
    {
        cout << "Opção inválida!" << endl;
        return 1;
    }

    int opcao;
    do
    {
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

        switch (opcao)
        {
        case 1: 
        {
            if (lista == nullptr)
            {
                cout << "Lista não criada" << endl;
                break;
            }

            int valor, posicao;
            cout << "Digite o valor a ser inserido: ";
            cin >> valor;
            cout << "Digite a posição (0 a " << n << "): ";
            cin >> posicao;

            if (posicao < 0 || posicao > n)
            {
                cout << "Posição inválida" << endl;
                break;
            }

            int *novaLista = new int[n + 1];
            for (int i = 0; i < posicao; i++)
                novaLista[i] = lista[i];

            novaLista[posicao] = valor;

            for (int i = posicao; i < n; i++)
                novaLista[i + 1] = lista[i];

            delete[] lista;
            lista = novaLista;
            n++;

            cout << "Valor inserido" << endl;
            break;
        }

        case 2: 
        {
            if (lista == nullptr)
            {
                cout << "Lista não criada" << endl;
                break;
            }

            int pos1, pos2;
            cout << "Digite a primeira posição (0 a " << n - 1 << "): ";
            cin >> pos1;
            cout << "Digite a segunda posição (0 a " << n - 1 << "): ";
            cin >> pos2;

            if (pos1 < 0 || pos1 >= n || pos2 < 0 || pos2 >= n)
            {
                cout << "Posições inválidas" << endl;
                break;
            }

            swap(lista[pos1], lista[pos2]);

            cout << "Posições alteradas" << endl;
            break;
        }

        case 3: 
        {
            if (lista == nullptr)
            {
                cout << "Lista não criada" << endl;
                break;
            }

            int valor, cont = 0, posicao = -1;
            cout << "Digite o valor a procurar: ";
            cin >> valor;

            for (int i = 0; i < n; i++)
            {
                cont++; // acessando lista[i]
                if (lista[i] == valor)
                {
                    posicao = i;
                    break;
                }
            }

            if (posicao != -1)
            {
                cout << "Valor encontrado na posição " << posicao << endl;
            }
            else
            {
                cout << "Valor não encontrado" << endl;
            }

            cout << "Número de acessos: " << cont << endl;
            break;
        }

        case 4: 
        {
            cout << "------------ Procurar menor valor ------------ " << endl;

            if (lista == nullptr)
            {
                cout << "Lista não criada" << endl;
                break;
            }

            int menor = lista[0]; // 1 acesso
            int posicao = 0;
            int cont = 1;

            for (int i = 1; i < n; i++)
            {
                cont++; // acesso lista[i]
                if (lista[i] < menor)
                {
                    menor = lista[i]; // +1 acesso
                    posicao = i;
                    cont++; // novo menor atribuído
                }
            }

            cout << "Menor valor encontrado: " << menor << endl;
            cout << "Posição: " << posicao << endl;
            cout << "Número de acessos: " << cont << endl;
            break;
        }

        case 5: 
        {
            if (lista == nullptr)
            {
                cout << "Lista não criada" << endl;
                break;
            }

            cout << "Lista: ";
            for (int i = 0; i < n; i++)
                cout << lista[i] << " ";
            cout << endl;
            break;
        }

        case 6: // Mostrar inversa
        {
            if (lista == nullptr)
            {
                cout << "Lista não criada" << endl;
                break;
            }

            cout << "Lista inversa: ";
            for (int i = n - 1; i >= 0; i--)
                cout << lista[i] << " ";
            cout << endl;
            break;
        }

        case 0:
            cout << "Fim do programa." << endl;
            break;

        default:
            cout << "Opção inválida!" << endl;
        }

    } while (opcao != 0);

    delete[] lista;
    return 0;
}
