#include "sala_privada.h"

// Implementação do construtor
sala_privativa::sala_privativa(int numero, int andar, int capacidade_maxima)
    : sala(numero, andar), capacidade_maxima_de_pessoas(capacidade_maxima) {}

// Implementação do método calcula_preco
double sala_privativa::calcula_preco() const {
    return capacidade_maxima_de_pessoas * 100.0; // Exemplo de cálculo de preço
}

// Implementação dos métodos set e get
void sala_privativa::set_capacidade_maxima(int capacidade) {
    capacidade_maxima_de_pessoas = capacidade;
}

int sala_privativa::get_capacidade_maxima() const {
    return capacidade_maxima_de_pessoas;
}