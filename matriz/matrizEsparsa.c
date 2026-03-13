#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct tempNo{
    float valor;
    int coluna;
    float valor;
    struct tempNo* prox;
}NO;

typedef NO* PONT;

typedef struct{
    PONT* A;
    int linhas;
    int colunas;
}MATRIZ;


// INICIALIZANDO MATRIZ ESPARSA

void inicializarMatrizEsparsa(MATRIZ* m, int linhas, int colunas){
    m->linhas = linhas;
    m->colunas = colunas;
    m->A = (PONT*) malloc(linhas*sizeof(PONT));
    int i;
    for(i=0;i<linhas;i++) m->A[i] = NULL;
}

// Atribuindo um valor- busca

bool AtribuirMatriz(MATRIZ* m, int linha, int coluna, float valor){
    if(linha<0 || linha>=m->linhas || coluna<0 || coluna>=m->colunas) return false;
    PONT ant = NULL;
    PONT atual = m->A[linha];
    while(atual != NULL && atual->col<colunaL){
        ant = atual;
        atual = atual->prox;

    }

    //atribuindo valor, nó existe
    if(atual != NULL && atual->col == coluna){
       if(valor == 0){
           if(ant == NULL){
               m->A[linha] = atual->prox;
           }
           else{
               ant->prox = atual->prox;
           }
           free(atual);
       }else{
        PONT novo = (PONT) malloc(sizeof(NO));
        novo->coluna = coluna;
        novo->valor = valor;
        novo->prox = atual;
        if(ant == NULL){
            m->A[linha] = novo;
        }
        else{
            ant->prox = novo;
        }
       }
       return true;
    }

}

// Acessando valor

float acessarMatriz(MATRIZ* m, int linha, int coluna){
    if(linha<0 || linha>=m->linhas || coluna<0 || coluna>=m->colunas) return false;
    PONT atual = m->A[linha];
    while(atual != NULL && atual->col<coluna){
        atual = atual->prox;
    }
    if(atual != NULL && atual->col == coluna){
        return atual->valor;
    }
    else{
        return 0;
    }
}
