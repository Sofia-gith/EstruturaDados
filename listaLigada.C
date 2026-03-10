#include <stdio.h>

// Inicialização de uma lista ligada

int InicializarLista(LISTA* l){
    int j;

    for(i=0; i<MAX-1; i++){
        l->A[i].prox = i +1;
    }
    l->A[MAX-1].prox = INVALIDO;
    l->inicio=INVALIDO;
    l->dispo=0;
}