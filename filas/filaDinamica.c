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


//retornando numero de elementos

int tamanhoFila(FILA* f){
    int tamanho = 0;
    PONT end = f->inicio;
    while(end != NULL){
        tamanho++;
        end = end->prox;
    }
    return tamanho; 
}

//imprimindo elementos

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

// exclusão de elementos 

bool excluirDaFila(FILA* f, REGISTRO* reg){
    if(f->inicio == NULL) return false;
    PONT excluido = f->inicio;
    *reg = excluido->reg;
    f->inicio = excluido->prox;
    free(excluido);
    if(f->inicio == NULL) f->fim = NULL;
    return true;
}

//reiniciando a fila

void reiniciarFila(FILA* f){
    PONT end = f->inicio;
    while(end != NULL){
        PONT apagar = end;
        end = end->prox;
        free(apagar);
    }
    f->inicio = NULL;
    f->fim = NULL;
}