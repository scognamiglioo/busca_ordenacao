#include <iostream>
#include <fstream>
#include <cstdlib> // para rand e srand
#include <ctime>   // para time
using namespace std;

int main()
{
    int n;
    int *lista = nullptr;

    ifstream arquivo("lista.txt");
    if (arquivo.is_open())
    {
        arquivo >> n;
        lista = new int[n];
        for (int i = 0; i < n; i++)
        {
            arquivo >> lista[i];
        }
        arquivo.close();
    }
    else
    {
        cout << "Erro ao abrir o arquivo." << endl;
    }

    int opcao;
    do
    {
        cout << "\n------------ Operacoes ------------ " << endl;
        cout << "Escolha uma opcao: " << endl;
        cout << "1 - Gerar lista aleatoria" << endl;
        cout << "2 - Inserir um valor em uma posição especifica" << endl;
        cout << "3 - Fazer Swap" << endl;
        cout << "4 - Procurar um valor na lista" << endl;
        cout << "5 - Procurar menor valor" << endl;
        cout << "6 - Mostrar lista" << endl;
        cout << "7 - Mostrar lista inversa" << endl;
        cout << "0 - Sair do programa" << endl;
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
        {
            cout << "------------ Gerar lista aleatoria ------------ " << endl;
            cout << "Digite o tamanho da lista: ";
            cin >> n;
            delete[] lista;
            lista = new int[n];

            srand(time(0));
            for (int i = 0; i < n; i++)
            {
                lista[i] = rand() % 100;
            }

            cout << "Lista aleatória gerada: ";
            for (int i = 0; i < n; i++)
                cout << lista[i] << " ";
            cout << endl;
            break;
        }

        case 2:
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

            cout << "Lista: ";
            for (int i = 0; i < n; i++)
                cout << lista[i] << " ";
            cout << endl;
            break;
        }

        case 3:
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

            cout << "Lista: ";
            for (int i = 0; i < n; i++)
                cout << lista[i] << " ";
            cout << endl;
            break;
        }

        case 4:
        {
            if (lista == nullptr)
            {
                cout << "Lista não criada" << endl;
                break;
            }

            int valor;
            cout << "Digite o valor a procurar: ";
            cin >> valor;

            bool encontrado = false;
            for (int i = 0; i < n; i++)
            {
                if (lista[i] == valor)
                {
                    cout << "Valor encontrado na posição " << i << endl;
                    encontrado = true;
                    break;
                }
            }

            if (!encontrado)
                cout << "Valor não encontrado" << endl;

            break;
        }

        case 5:
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
                cont++; // acesso a lista[i] para comparar
                if (lista[i] < menor)
                {
                    menor = lista[i]; // +1 acesso
                    posicao = i;
                    cont++; // mais um acesso para atribuir novo menor
                }
            }

            cout << "Menor valor encontrado: " << menor << endl;
            cout << "Posição: " << posicao << endl;
            cout << "Número de acessos: " << cont << endl;
            break;
        }

        case 6:
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

        case 7:
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
            cout << "Fim" << endl;
            break;

        default:
            cout << "Opção inválida" << endl;
        }

    } while (opcao != 0);

    delete[] lista;
    return 0;
}
// compilação: g++ -o operacoes operacoes.cpp
// execução: ./operacoes