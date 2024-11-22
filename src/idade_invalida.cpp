#include "idade_invalida.h"


const char* idade_invalida::  what() const noexcept{
		return "Idade nao pode ser negativa!";
	}