#include <stdio.h>

//exemplo de inserção de elemento na lista
// Lista linear sequencial
// etsa lista, é uma lista composta por um arranjo

bool inserirElemLista(LISTA* l, REGISTRO reg, int){
    int j;
    if((l->nroElem>=TAM_MAX) || (i<0) || (i>l->nroElem)){
        return false;

    }

    for(j=l->nroElem-1; j>=i; j--){
        l->elem[j+1] = l->elem[j];
    }
    l->elem[i] = reg;
    l->nroElem++;
    return true;
}