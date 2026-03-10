#include <stdio.h>

int BuscaSequencial(LISTA*l, TIPOCHAVE ch){
    int i = l->inicio;
    while(i!= INVALIDO&& l->A[i].reg.chave< ch)
        i = l->A[i].prox;
    if (i != INVALIDO && l->A[i].reg.chave == ch)
        return i;
    else
        return INVALIDO;
}