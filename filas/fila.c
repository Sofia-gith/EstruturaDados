 #include <stdio.h>
#include <malloc.h>

#define MAX 50

typedef int bool;
typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
} REGISTRO;

typedef struct{
    REGISTRO A[MAX];
    int inicio;
    int nroElem;
}FILA;

// inicializando a fila
void inicializarFila(FILA* f){
    f->inicio = 0;
    f->nroElem = 0;
}

//retornando numero de elementos

int tamanhoFila(FILA* f){
    return f->nroElem;
}

// impressão 

void exibirFila(FILA* f){
    int i = f->inicio;
    printf("Fila: ");
    int tempo;
    for(tempo = 0; tempo< f->nroElem; tempo++){
        printf("%i ", f->A[i].chave);
        i = (i+1) % MAX;
    }
    printf("\n");
}


// inserção de elementos

bool inserirFila(FILA* f, REGISTRO reg){
    if(f->nroElem >= MAX) return false;
    int pocicao = (f->inicio + f->nroElem) % MAX;
    f->A[pocicao] = reg;
    f->nroElem++;
    return true;
}

// exclusão de elementos

bool excluirFila(FILA* f, REGISTRO* reg){
    if(f->nroElem == 0) return false;
    *reg = f->A[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->nroElem--;
    return true;
}

//reiniciando as filas estaticas

void reinicializarFila(FILA* f){
    f->inicio = 0;
    f->nroElem = 0;
}
        // outra forma

void reinicializarFila2(FILA* f){
    inicializarFila(f);
}
