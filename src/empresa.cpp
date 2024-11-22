#include "empresa.h"
#include "idade_invalida.h"

empresa::empresa(const string& n, int i) : nome(n) {
    if (i < 0) {
        throw idade_invalida();
    } else {
        idade = i;
    }
}

empresa::~empresa() noexcept {}

void empresa::set_nome(const string& novo_nome) noexcept {
    nome = novo_nome;
}

void empresa::set_idade(const int nova_idade) {
    if (nova_idade < 0) {
        throw idade_invalida();
    }
    idade = nova_idade;
}

string empresa::get_nome() const noexcept {
    return nome;
}

int empresa::get_idade() const noexcept {
    return idade;
}

bool operator<(const empresa& a, const empresa& b) noexcept {
    return a.get_idade() < b.get_idade();
}

