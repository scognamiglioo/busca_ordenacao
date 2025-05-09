#include "listasencadeada.h"

ListaEncadeada::ListaEncadeada() {
    cabeca = nullptr;
}

ListaEncadeada::~ListaEncadeada() {
    destruir();
}

void ListaEncadeada::insere(int valor) {
    No* novo = new No(valor);

    if (cabeca == nullptr) {
        cabeca = novo;
    } else {
        No* atual = cabeca;
        while (atual->proximo != nullptr) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
}

void ListaEncadeada::imprime() const {
    No* atual = cabeca;
    while (atual != nullptr) {
        std::cout << atual->valor << " ";
        atual = atual->proximo;
    }
    std::cout << std::endl;
}

void ListaEncadeada::carregarDeArquivo(const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo) {
        std::cerr << "Erro ao abrir o arquivo: " << nomeArquivo << std::endl;
        return;
    }

    int valor;
    while (arquivo >> valor) {
        insere(valor);
    }
}

void ListaEncadeada::salvarEmArquivo(const std::string& nomeArquivo) const {
    std::ofstream arquivo(nomeArquivo);
    if (!arquivo) {
        std::cerr << "Erro ao salvar no arquivo: " << nomeArquivo << std::endl;
        return;
    }

    No* atual = cabeca;
    while (atual != nullptr) {
        arquivo << atual->valor << "\n";
        atual = atual->proximo;
    }
}

void ListaEncadeada::destruir() {
    No* atual = cabeca;
    while (atual != nullptr) {
        No* temp = atual;
        atual = atual->proximo;
        delete temp;
    }
    cabeca = nullptr;
}
