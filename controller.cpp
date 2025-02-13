#include "sequencial_list.h"
#include <iostream>
#include <fstream>

int main() {
    ListaSequencial lista(100); // Criando uma lista com capacidade 100
    std::ifstream entrada("entrada.txt");
    std::ofstream saida("saida_teste.txt");

    if (!entrada) {
        std::cerr << "Erro ao abrir entrada.txt" << std::endl;
        return 1;
    }

    char comando;
    int posicao, valor;

    while (entrada >> comando) {
        switch (comando) {
            case 'I': // Inserir
                entrada >> posicao >> valor;
                if (lista.insereElemento(posicao, valor)) {
                    saida << "Elemento " << valor << " inserido na posição " << posicao << std::endl;
                } else {
                    saida << "Falha ao inserir elemento " << valor << " na posição " << posicao << std::endl;
                }
                break;

            case 'P': // Printar elemento
                entrada >> posicao;
                if (lista.getElemento(posicao) != -1) {
                    saida << "Elemento na posição " << posicao << ": " << lista.getElemento(posicao) << std::endl;
                } else {
                    saida << "Posição inválida para obtenção: " << posicao << std::endl;
                }
                break;

            case 'R': // Remover elemento
                entrada >> posicao;
                if (lista.removeElemento(posicao)) {
                    saida << "Elemento na posição " << posicao << " removido" << std::endl;
                } else {
                    saida << "Falha ao remover elemento na posição " << posicao << std::endl;
                }
                break;

            case 'T': // Tamanho da lista
                saida << "Tamanho atual da lista: " << lista.getTamanho() << std::endl;
                break;

            case 'F': // Verificar se está cheia
                saida << "Lista cheia? " << (lista.cheia() ? "Sim" : "Não") << std::endl;
                break;

            case 'V': // Verificar se está vazia
                saida << "Lista vazia? " << (lista.vazia() ? "Sim" : "Não") << std::endl;
                break;

            default:
                saida << "Comando inválido: " << comando << std::endl;
                break;
        }
    }

    entrada.close();
    saida.close();
    
    return 0;
}
