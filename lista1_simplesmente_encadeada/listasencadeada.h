#pragma once

#include <iostream>
#include <fstream>

struct No {
    int valor;
    No* proximo;

    No(int v) : valor(v), proximo(nullptr) {}
};

struct ListaEncadeada {
    No* cabeca;

    ListaEncadeada();
    ~ListaEncadeada();

    void insere(int valor);
    void imprime() const;
    void carregarDeArquivo(const std::string& nomeArquivo);
    void salvarEmArquivo(const std::string& nomeArquivo) const;
    void destruir();
};
