#ifndef SEQUENCIAL_LIST_H
#define SEQUENCIAL_LIST_H

#include <iostream>

class ListaSequencial {
    private:
        int* dados;
        int tamanho_atual;
    public:
        ListaSequencial(int tamanho); //Construtor
        ~ListaSequencial(); //Destrutor

        bool vazia(); //Verifica se a lista está vazia
        bool cheia(); //Verifica se a lista está cheia
        int getTamanho(); //Retorna o tamanho da lista
        int getElemento(int pos); //Retorna o elemento na posição passada
        void setElemento(int pos, int elemento); //Modifica o elemento na posição passada
        int procuraElemento(int elemento); //Procura um elemento na lista
        bool insereElemento(int pos, int elemento); //Insere um elemento na posição passada
        bool removeElemento(int pos); //Remove um elemento na posição passada
        
};

#endif