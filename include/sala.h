#ifndef SALA_H
#define SALA_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "empresa.h" 

using std::vector;
using std::cout;
using std::endl;

class sala {
protected:
    int numero_da_sala;
    int andar;
    vector<empresa> lista_de_empresas_locatarias;

public:
    // Construtor
    sala(int numero, int andar) ;

    // Métodos set e get para numero_da_sala
    void set_numero(int numero);
    int get_numero() const ;

    // Métodos set e get para andar
    void set_andar(int andar);
    int get_andar() const ;

    // Retorna a lista de empresas associadas à sala
    const vector<empresa>& get_empresas() const ;

    // Ordena as empresas na lista por idade, da mais antiga para a mais nova
    void ordenar_empresas_por_idade();
    
    // Método virtual puro para calcular o preço
    virtual double calcula_preco() const = 0;

    // Sobrecarga do operador <
    bool operator<(const sala& outra) const ;

    // Sobrecarga do operador + para adicionar uma empresa
    sala& operator+(const empresa& nova_empresa) ;

    // Sobrecarga do operador - para remover uma empresa
    sala& operator-(const empresa& empresa_remover) ;
    
    // Destrutor 
    virtual ~sala();
};

#endif 