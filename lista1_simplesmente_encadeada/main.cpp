#include <iostream>
#include <cstdlib>
#include <ctime>
#include "listasencadeada.h"
using namespace std;

int main() {
    ListaEncadeada lista;
    int escolhaInicial;

    cout << "Escolha como criar a lista:\n";
    cout << "1 - Carregar lista de um arquivo\n";
    cout << "2 - Gerar lista aleatória\n";
    cout << "Opção: ";
    cin >> escolhaInicial;

    if (escolhaInicial == 1) {
        lista.carregarDeArquivo("lista.txt");
    } else if (escolhaInicial == 2) {
        int n, min, max;
        cout << "Digite o tamanho da lista: ";
        cin >> n;
        cout << "Digite o intervalo dos números (min max): ";
        cin >> min >> max;

        srand(static_cast<unsigned int>(time(0)));
        for (int i = 0; i < n; ++i) {
            int valor = rand() % (max - min + 1) + min;
            lista.insere(valor);
        }

        lista.salvarEmArquivo("lista.txt");  // opcional: salva a lista
    } else {
        cout << "Opção inválida!" << endl;
        return 1;
    }

    cout << "Lista resultante: ";
    lista.imprime();

    return 0;
}
