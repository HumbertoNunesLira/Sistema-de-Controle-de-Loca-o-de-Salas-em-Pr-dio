#include "sala.h"

// Construtor
sala::sala(int numero, int andar) : numero_da_sala(numero), andar(andar) {}

// Destrutor virtual
sala::~sala(){}

// Métodos set e get para numero_da_sala
void sala::set_numero(int numero) { numero_da_sala = numero; }
int sala::get_numero() const { return numero_da_sala; }

// Métodos set e get para andar
void sala::set_andar(int andar) { this->andar = andar; }
int sala::get_andar() const { return andar; }

// Retorna a lista de empresas associadas à sala
const vector<empresa>& sala::get_empresas() const { return lista_de_empresas_locatarias; }

// Ordena as empresas na lista por idade, da mais antiga para a mais nova
void sala::ordenar_empresas_por_idade() {
    std::sort(lista_de_empresas_locatarias.begin(), lista_de_empresas_locatarias.end());
}

// Sobrecarga do operador < para comparar salas pelo andar
bool sala::operator<(const sala& outra) const {
    return andar < outra.andar;
}

// Sobrecarga do operador + para adicionar uma empresa 
sala& sala::operator+(const empresa& nova_empresa) {
    lista_de_empresas_locatarias.push_back(nova_empresa);
    ordenar_empresas_por_idade();
    return *this;
}

// Sobrecarga do operador - para remover uma empresa 
sala& sala::operator-(const empresa& empresa_remover) {
    auto it = std::find_if(lista_de_empresas_locatarias.begin(), lista_de_empresas_locatarias.end(),
        [&empresa_remover](const empresa& emp) {
            return emp.get_nome() == empresa_remover.get_nome();
        });

    if (it != lista_de_empresas_locatarias.end()) {
        lista_de_empresas_locatarias.erase(it);
    }
    return *this;
}

