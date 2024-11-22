#ifndef IDADE_INVALIDA_H
#define IDADE_INVALIDA_H

#include <iostream>
#include <string>
#include <stdexcept>

using std:: string;
using std:: cout;
using std:: endl;
using std:: exception;

class idade_invalida: public exception {

public:
    const char* what() const noexcept override;
};
#endif 