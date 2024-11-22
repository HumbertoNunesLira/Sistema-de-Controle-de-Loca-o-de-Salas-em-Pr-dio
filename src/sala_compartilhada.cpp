#include "sala_compartilhada.h"

// Implementação do construtor
sala_compartilhada::sala_compartilhada(int numero, int andar, int estacoes_de_trabalho)
    : sala(numero, andar), numero_de_estacoes_de_trabalho_disponiveis(estacoes_de_trabalho) {}

// Implementação do método calcula_preco
double sala_compartilhada::calcula_preco() const {
    return numero_de_estacoes_de_trabalho_disponiveis * 50.0; // Exemplo de cálculo de preço
}

// Implementação dos métodos set e get
void sala_compartilhada::set_estacoes_de_trabalho(int estacoes) {
    numero_de_estacoes_de_trabalho_disponiveis = estacoes;
}

int sala_compartilhada::get_estacoes_de_trabalho() const {
    return numero_de_estacoes_de_trabalho_disponiveis;
}