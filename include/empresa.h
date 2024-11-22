#ifndef EMPRESA_H
#define EMPRESA_H

#include <iostream>
#include <string>
#include <stdexcept>

using std::string;
using std::cout;
using std:: endl;
using std:: invalid_argument;


class empresa{

private:
    string nome;
    int idade;


public:

    empresa(const string& n, int i);

    ~empresa() noexcept; 
    
    void set_nome(const string& novo_nome) noexcept;

    void set_idade(const int nova_idade);

    string get_nome() const noexcept;

    int get_idade() const noexcept;

    friend bool operator<(const empresa& a, const empresa& b) noexcept;

};
#endif // CAMPEONATO_H