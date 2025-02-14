#include "sequencial_list.h"
#include <iostream>

ListaSequencial::ListaSequencial(int tamanho) {
    dados = new int[tamanho];
    tamanho_atual = 0;
}

ListaSequencial::~ListaSequencial() {
    delete[] dados;

}

bool ListaSequencial::vazia() {
    if(tamanho_atual == 0) {
        return true;
    } else {
        return false;
    }
}

bool ListaSequencial::cheia() {
    if(tamanho_atual == 100) {
        return true;
    } else {
        return false;
    }
}

int ListaSequencial::getTamanho() {
    return tamanho_atual;
}

int ListaSequencial::getElemento(int pos) {
    if (pos <= 0 || pos > tamanho_atual) {  //Verifica se a posição é válida
        return -1;
    }
    return dados[pos - 1];  
}


void ListaSequencial::setElemento(int pos, int elemento) {
    if (pos > 0 && pos <= tamanho_atual) { //Verifica se a posição é válida
        dados[pos-1] = elemento; 
    }
}


int ListaSequencial::procuraElemento(int elemento) {
    for(int i = 0; i < tamanho_atual; i++) { //Percorre a lista
        if(dados[i] == elemento) {
            return i+1;
        }
    }
    return -1;
}

bool ListaSequencial::insereElemento(int pos, int elemento) {
    if(cheia() || (pos > tamanho_atual+1) || (pos <= 0)) { //Verifica se a lista está cheia ou se a posição é válida
        return false;
    } else {
        for(int i = tamanho_atual; i >= pos; i--) {
            dados[i] = dados[i-1];
        }
        dados[pos-1] = elemento;
        tamanho_atual++;
        return true;
    }
}

bool ListaSequencial::removeElemento(int pos) {
    int dado;
    if(vazia() || (pos > tamanho_atual) || (pos < 1)) { //Verifica se a lista está vazia ou se a posição é válida
        return false;
    } 
    
    dado = dados[pos-1];
    
    for(int i = pos-1; i < tamanho_atual-1; i++) { //Percorre a lista
        dados[i] = dados[i+1];
    }
    tamanho_atual--;
    return true;
    
}
