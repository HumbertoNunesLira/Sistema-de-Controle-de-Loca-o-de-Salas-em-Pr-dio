#ifndef SALA_COMPARTILHADA
#define SALA_COMPARTILHADA

#include "sala.h"

class sala_compartilhada : public sala {
private:
    int numero_de_estacoes_de_trabalho_disponiveis;

public:
    // Construtor
    sala_compartilhada(int numero, int andar, int estacoes_de_trabalho);

    // Sobrescrita do método calcula_preco
    double calcula_preco() const override;

    // Métodos set e get para numero_de_estacoes_de_trabalho_disponiveis
    void set_estacoes_de_trabalho(int estacoes);
    int get_estacoes_de_trabalho() const;
};


#endif 