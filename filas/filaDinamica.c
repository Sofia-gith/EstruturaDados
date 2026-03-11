#include <stdio.h>
#include <malloc.h>


typedef int bool;
typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
} REGISTRO;

typedef struc auxE{
    REGISTRO reg;
    struct auxE* prox;
}ELEMENTO, *PONT;

typedef struct{
    PONT inicio;
    PONT fim;
}FILA;


// inicializando a fila
void inicializarFila(FILA* f){
    f->inicio = NULL;
    f->fim = NULL;
}

//exibição/impressão

void exibirFila(FILA* f){
    PONT end = f->inicio;
    printf("Fila: ");
    while(end != NULL){
        printf("%i ", end->reg.chave);
        end = end->prox;
    }
    printf("\n");
}

//inserindo elementos

bool inserirFila(FILA* f, REGISTRO reg){
    PONT novo = (PONT) malloc(sizeof(ELEMENTO));
    if(novo == NULL) return false;
    novo->reg = reg;
    novo->prox = NULL;
    if(f->inicio == NULL) f->inicio = novo;
    else f->fim->prox = novo;
    f->fim = novo;
      
    return true;
}