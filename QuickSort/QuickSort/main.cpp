#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

//MÉTODO PARTICIONAMENTO DO VETOR
int particionamento(int vetor[], int esquerda, int direita){
    int auxiliar; //AUXILIAR DE TROCA
    int contador = esquerda; //CONTADOR "RECURSIVO"
    for (int i = esquerda + 1; i <= direita; i++){
        if (vetor[i] < vetor[esquerda]){ //COMPARAÇÃO
            contador++;
            auxiliar = vetor[i]; //ATRIBUIÇÃO NO AUXILIAR
            vetor[i] = vetor[contador]; //TROCA DE ENDEREÇOS
            vetor[contador] = auxiliar; //TROCA DE ENDEREÇOS
        }
    }
    //TROCA FINAL
    auxiliar = vetor[esquerda]; //ATRIBUIÇÃO NO AUXILIAR
    vetor[esquerda] = vetor[contador]; //TROCA DE ENDEREÇOS
    vetor[contador] = auxiliar; //TROCA DE ENDEREÇOS
    return contador; //LIMITADOR RECURSIVO, POSIÇÃO DO VETOR
}

//MÉTODO QUICK SORT
void quick_sort(int vetor[], int esquerda, int direita){
    int posicao; //LIMITADOR RECURSIVO, POSIÇÃO DO VETOR
    if (esquerda < direita){ //COMPARAÇÃO
        posicao = particionamento(vetor, esquerda, direita); //ATRIBUIÇÃO DA POSIÇÃO
        quick_sort(vetor, esquerda, posicao - 1); //CHAMADA RECURSIVA ALTERANDO A DIRETIA DO VETOR
        quick_sort(vetor, posicao + 1, direita); //CHAMADA RECURSIVA ALTERANDO A ESQUERDA DO VETOR
    }
}

int main(int argc, char** argv) {
    int vetor[] = {5,10,15};

    quick_sort(vetor, 0, 2);
    
    cout << endl;
    
    for(int i = 0; i <= 2; i++){
        cout << vetor[i] << " ";
    }
    cout << "\n" << vetor[0];
    return 0;
}