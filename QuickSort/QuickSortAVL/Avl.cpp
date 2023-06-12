#include "noAvl.h"
#include "Avl.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Avl::Avl() {
    this->raiz = NULL;
}

Avl::Avl(const Avl& orig) {
}

Avl::~Avl() {
}

noAvl* Avl::inserir(noAvl* raiz, int valor){
    if(raiz == NULL){
        raiz = new noAvl(valor);  
        raiz->esquerda = NULL;
        raiz->direita = NULL;
    }else{ 
        if(valor < raiz->dado)
            raiz->esquerda = inserir(raiz->esquerda, valor);
        else
            raiz->direita = inserir(raiz->direita, valor);
    }
    return raiz;
}

void Avl::preOrdem(noAvl *raiz){
    if(raiz != NULL){
        cout << "ELEMENTO: " << raiz->dado << endl;
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

void Avl::menu(){
    int opcao, valor, cont = 0;
    bool decisao = true;
    int* array = nullptr;

    while(decisao){
        cout << "TABELA DE OPÇÕES -> 1- INSERIR\n"
                "                 -> 2- LISTAR PRÉ ORDEM\n"
                "                 -> 3- QUICK SORT\n";
        cin >> opcao;
        switch(opcao){
            case 1:
                cout << "\nINFORME O VALOR: ";
                cin >> valor;
                raiz = inserir(raiz, valor);
                cont++;
                break;
            case 2:
                preOrdem(raiz);
                break;
            case 3:
                delete[] array;
                array = preenche_vetor(raiz);
                quick_sort(array, 0, cont - 1);
                cout << "ELEMENTOS ORDENADOS: ";
                for (int i = 0; i < cont; i++){
                    cout << array[i] << " ";
                }
                cout << endl;
                delete[] array;
                array = nullptr;
                break;
            default:
                cout << "\nINFORME UM NÚMERO VÁLIDO! ";
                break;
        }
        cout << "\nDESEJA CONTINUAR?\n"
                "0 - NÃO\n"
                "1 - SIM\n";
        cin >> opcao;
        if (opcao == 0){
            decisao = false;
        }
    }
}

int* Avl::preenche_vetor(noAvl* raiz) {
    int* array = new int[10]; // Alocação dinâmica do vetor
    int index = 0;
    preenche_vetor_aux(raiz, array, index);
    return array;
}

void Avl::preenche_vetor_aux(noAvl* raiz, int* array, int& index) {
    if (raiz != NULL) {
        array[index++] = raiz->dado;
        preenche_vetor_aux(raiz->esquerda, array, index);
        preenche_vetor_aux(raiz->direita, array, index);
    }
}

int Avl::particionamento(int array[], int esquerda, int direita){
    int auxiliar; //AUXILIAR DE TROCA
    int contador = esquerda; //CONTADOR "RECURSIVO"
    for (int i = esquerda + 1; i <= direita; i++){
        if (array[i] < array[esquerda]){ //COMPARAÇÃO
            contador++;
            auxiliar = array[i]; //ATRIBUIÇÃO NO AUXILIAR
            array[i] = array[contador]; //TROCA DE ENDEREÇOS
            array[contador] = auxiliar; //TROCA DE ENDEREÇOS
        }
    }
    //TROCA FINAL
    auxiliar = array[esquerda]; //ATRIBUIÇÃO NO AUXILIAR
    array[esquerda] = array[contador]; //TROCA DE ENDEREÇOS
    array[contador] = auxiliar; //TROCA DE ENDEREÇOS
    return contador; //LIMITADOR RECURSIVO, POSIÇÃO DO VETOR
}

//MÉTODO QUICK SORT
void Avl::quick_sort(int array[], int esquerda, int direita) {
    if (esquerda < direita) {
        int posicao = particionamento(array, esquerda, direita);
        quick_sort(array, esquerda, posicao - 1);
        quick_sort(array, posicao + 1, direita);
    }
}


