#include <stdio.h>


#define MAX 50

typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
} REGISTRO;

typedef struct{
    REGISTRO A[MAX];
    int topo1;
    int topo2;
} PILHADUPLA;


// Inicializando

void inicializarPilhaDupla(PILHADUPLA* p){
    p->topo1 =-1;
    p->topo2= MAX;
}

// exibindo elementos

bool exibirUmaPilha(PILHADUPLA* p, int pilha){
    if(pilha<1 || pilha>2) return false;
    printf("Pilha %i: ", pilha);
    int i
    if(pilha == 1) for(i=p->topo1;i>=0;i++) printf("%i ", p->A[i].chave);

    printf("\n");
    return true;
}

//Inserindo elementos dentro da pilha(push)

bool inserirElementoPiljha(PILHADUPLA* p, int pilha, REGISTRO reg){
    if(pilha<1 || pilha>2) return false;
    if(p->topo1+1 == p->topo2) return false;
    if(pilha == 1){ 
        p->topo1 = p->topo1+1;
        p->A[p->topo1] = reg; 
    }
    else{
        p->topo2 = p->topo2-1;
        p->A[p->topo2] = reg; 
    }
    return true;
}

// Excluindo elementos da pilhas(pop)


bool excluirElementoPilha(PILHADUPLA* p, int pilha, REGISTRO* reg){
    if(pilha<1 || pilha>2) return false;
    if(pilha == 1){
        if(p->topo1 == -1) return false;
        *reg = p->A[p->topo1];
        p->topo1 = p->topo1-1;
    }
    else{
        if(p->topo2 == MAX) return false;
        *reg = p->A[p->topo2];
        p->topo2 = p->topo2+1;
    }
    return true;
}

// reiniciando a pilha

void reiniciarPilhaDuplha(PILHADUPLA* p){
    p->topo1=-1;
    p->topo2=MAX;
}

void exibirDuasPilhas(PILHADUPLA* p){
   reinicializarPilhaDupla(p);
}