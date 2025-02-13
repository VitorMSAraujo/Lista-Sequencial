#ifndef SEQUENCIAL_LIST_H
#define SEQUENCIAL_LIST_H
#define MAX 100

#include <iostream>

class ListaSequencial {
    private:
        int elementos[MAX];
        int tamanho;
        int 
    public:
        ListaSequencial();
        ~ListaSequencial();
        bool vazia();
        bool cheia();
        int getTamanho();
        int getElemento(int posicao);
        void setElemento(int posicao, int elemento);
        
};

#endif