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

//retornando numero de elementos
        // do inicio para o fim
int tamanho(DEQUE* d){
    PONT end = d->cabeca->prox;
    int cont = 0;
    while(end != d->cabeca){
        cont++;
        end = end->prox;
    }
    return cont;
}

        // do fim para o inicio
int tamanhoInverso(DEQUE* d){
    PONT end = d->cabeca->ant;
    int cont = 0;
    while(end != d->cabeca){
        cont++;
        end = end->ant;
    }
    return cont;
}


// impressão de elementos

void exibirDeque(DEQUE* d){
    PONT end = d->cabeca->ant;
    printf("Deque partindo do fim: ");
    while(end != d->cabeca){
        printf("%i ", end->reg.chave);
        end = end->ant;
    }
    printf("\n");
}

//inserção em deque

bool inserirInicio(DEQUE* d, REGISTRO reg){
    PONT novo = (PONT) malloc(sizeof(ELEMENTO));
    if(novo == NULL) return false;
    novo->reg = reg;
    novo->ant = d->cabeca;
    novo->prox = d->cabeca->prox;
    d->cabeca->prox->ant = novo;
    d->cabeca->prox = novo;
    return true;
}

//exclusão de um elemento do deque

bool excluirInicio(DEQUE* d, REGISTRO* reg){
    if(d->cabeca->prox == d->cabeca) return false;
    PONT excluido = d->cabeca->prox;
    *reg = excluido->reg;
    d->cabeca->prox = excluido->prox;
    excluido->prox->ant = d->cabeca;
    free(excluido);
    return true;
}

//reiniciando o deque

void reinicializarDeque(DEQUE* d){
    PONT end = d->cabeca->prox;
    while(end != d->cabeca){
        PONT excluido = end;
        end = end->prox;
        free(excluido);
    }
    d->cabeca->prox = d->cabeca;
    d->cabeca->ant = d->cabeca;
}