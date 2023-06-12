#include "noAvl.h"
#ifndef AVL_H
#define AVL_H

class Avl {
public:
    Avl();
    Avl(const Avl& orig);
    virtual ~Avl();
    
    noAvl *raiz;
    noAvl *inserir(noAvl *raiz, int valor);
    void preOrdem(noAvl *raiz);
    void menu();
    int *preenche_vetor(noAvl *raiz);
    void quick_sort(int array[], int esquerda, int direita);
    int particionamento(int array[], int esquerda, int direita);
    void preenche_vetor_aux(noAvl *raiz, int *array, int& index);
    
private:

};

#endif

