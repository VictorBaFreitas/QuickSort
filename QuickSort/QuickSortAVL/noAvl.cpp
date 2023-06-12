#include "noAvl.h"
#include <cstdlib>
#include <iostream>

using namespace std;

noAvl::noAvl() {   
    this->direita = this->esquerda = NULL;
}
noAvl::noAvl(int valor) {
    this->dado = valor;
    this->direita = this->esquerda = NULL;
}

noAvl::~noAvl() { 
}