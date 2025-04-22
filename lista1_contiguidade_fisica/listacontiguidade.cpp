
#include "listacontiguidade.h"
#include <iostream>
#include <fstream>

using namespace std;

bool carregarLista(const std::string& nomeArquivo, int& n, int*& lista) {
    ifstream arquivo(nomeArquivo);
    if (arquivo.is_open()) {
        arquivo >> n;
        lista = new int[n];
        for (int i = 0; i < n; ++i) {
            arquivo >> lista[i];
        }
        arquivo.close();
        return true;
    } else {
        cout << "Erro ao abrir o arquivo: " << nomeArquivo << endl;
        return false;
    }
}
