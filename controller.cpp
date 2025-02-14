#include "sequencial_list.h"
#include <iostream>
#include <fstream>

void processarArquivo(const std::string& arquivoEntrada, const std::string& arquivoSaida, ListaSequencial& lista) {
    std::ifstream entrada(arquivoEntrada);
    std::ofstream saida(arquivoSaida);

    if (!entrada) {
        std::cerr << "Erro ao abrir " << arquivoEntrada << std::endl;
        return;
    }

    char comando;
    int posicao, valor;

    while (entrada >> comando) {
        switch (comando) {
            case 'I': // Inserir elemento
                entrada >> posicao >> valor;
                if (lista.insereElemento(posicao, valor)) {
                    saida << "Elemento " << valor << " inserido na posição " << posicao << std::endl;
                } else {
                    saida << "Falha ao inserir elemento " << valor << " na posição " << posicao << std::endl;
                }
                break;

            case 'P': // Printar elemento
                entrada >> posicao;
                valor = lista.getElemento(posicao);
                if (valor != -1) {
                    saida << "Elemento na posição " << posicao << ": " << valor << std::endl;
                } else {
                    saida << "Posição inválida para obtenção: " << posicao << std::endl;
                }
                break;

            case 'M': // Modificar elemento
                entrada >> posicao >> valor;
                if (posicao > 0 && posicao <= lista.getTamanho()) {
                    lista.setElemento(posicao, valor);
                    saida << "Elemento na posição " << posicao << " modificado para " << valor << std::endl;
                } else {
                    saida << "Posição inválida para modificação: " << posicao << std::endl;
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

            case 'E': // Procurar elemento
                entrada >> valor;
                posicao = lista.procuraElemento(valor);
                if (posicao != -1) {
                    saida << "Elemento " << valor << " encontrado na posição " << posicao << std::endl;
                } else {
                    saida << "Elemento " << valor << " não encontrado na lista" << std::endl;
                }
                break;

            default:
                saida << "Comando inválido: " << comando << std::endl;
                break;
        }
    }

    entrada.close();
    saida.close();
}

int main() {
    ListaSequencial lista(100); // Criando uma lista com capacidade 100

    // Processando os dois arquivos de entrada
    processarArquivo("entrada.txt", "saida_teste.txt", lista);
    processarArquivo("entrada_2.txt", "saida_teste_2.txt", lista);

    return 0;
}
