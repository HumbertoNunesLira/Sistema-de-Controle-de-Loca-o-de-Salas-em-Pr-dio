#ifndef SALA_PRIVADA
#define SALA_PRIVADA

#include "sala.h"

class sala_privativa : public sala {
private:
    int capacidade_maxima_de_pessoas;

public:
    // Construtor
    sala_privativa(int numero, int andar, int capacidade_maxima);

    // Sobrescrita do método calcula_preco
    double calcula_preco() const override;

    // Métodos set e get para capacidade_maxima_de_pessoas
    void set_capacidade_maxima(int capacidade);
    int get_capacidade_maxima() const;
};


#endif 