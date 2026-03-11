#include <stdio.h>
#include <malloc.h>
#define true 1
#define false 0
typedef int bool;

typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
} REGISTRO;

typedef struct {
    REGISTRO A[MAX];
    int topo;
}PILHA;

//nomes de inserção e exclusão geralmente push e pop
//push é inserção e pop é exclusão


// INICIALIZAÇÂO DA PILHA

void inicilizarPilha(PILHA* p){
    p->topo = -1;
}

//RETORNANDO NUMERO DE ELEMENTOS 

int tamanho(PILHA* p){
    return p->topo + 1;
}

//IMPRESSÃO

void exibirPilha(PILHA* p){
    printf("Pilha: ");
    for(int i=p->topo; i>=0; i--){
        printf("%i ", p->A[i].chave);
    }
    printf("\n");
}

//inserção de elementos (push)

bool push(PILHA* p, REGISTRO reg){
    if(p->topo == MAX-1) return false;
    p->topo++;
    p->A[p->topo] = reg;
    return true;
}


