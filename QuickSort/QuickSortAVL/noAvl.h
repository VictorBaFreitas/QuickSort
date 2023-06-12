#ifndef NOAVL_H
#define NOAVL_H

class noAvl {
public:
    noAvl();
    noAvl(int valor);
    virtual ~noAvl();
    
    int dado;
    noAvl *esquerda, *direita;
private:

};

#endif