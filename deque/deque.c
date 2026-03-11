#include <stdio.h>
#include <malloc.h>
typedef int bool;

typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
} REGISTRO;

typedef struct auxElem{
    REGISTRO reg;
    struct auxElem* prox;
    struct auxElem* ant;
} ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct {
    PONT cabeca;
}DEQUE;

// Inicializando o deque

void inicializarDeque(DEQUE* d){
    d->cabeca = (PONT) malloc(sizeof(ELEMENTO));
    d->cabeca->ant = d->cabeca;
    d->cabeca->prox =  d->cabeca;
}
