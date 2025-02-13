#include "sequencial_list.h"
#include <iostream>
#include <fstream>

int main() {

    ListaSequencial lista(100);  // Cria uma lista com 100 elementos

    std::ifstream entrada("entrada.txt");  // Lê comandos de um arquivo
    if (!entrada) {
        std::cerr << "Erro ao abrir entrada.txt" << std::endl;
        return 1;
    }

    char comando;
    int posicao, valor;

    while (entrada >> comando) {
        if (comando == 'I') {  // Inserir
            entrada >> posicao >> valor;
            lista.insereElemento(posicao, valor);
        } else if (comando == 'P') {  // Printar elemento
            entrada >> posicao;
            std::cout << "Elemento " << posicao << ": " << lista.procuraElemento(posicao) << std::endl;
        } else if (comando == 'R') {  // Remover
            entrada >> posicao;
            lista.removeElemento(posicao);
        }
    }

    entrada.close();
    return 0;
}
