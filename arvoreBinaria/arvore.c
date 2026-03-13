#include <stdio.h>
#include <stdlib.h>
 #define true 1
 #define false 0

 typedef int bool;
 typedef int TIPOCHAVE;

 typedef struct aux{
    TIPOCHAVE chave;
    struct aux *esq, *dir;
 } NO;

 typedef NO* PONT;

 // inicializando uma arvore binaria

 PONT inicializa(){
    return NULL;
 }

 int main(){
    PONT raiz = inicializa();
    return 0;
 }