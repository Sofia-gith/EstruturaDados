#include <stdio.h>

// inicializando

void InicializarListaCircular(LISTA* l){
    l-> cabeca = (PONT) malloc(sizeof(ELEMENTO));
    l-> cabeca->prox = l-> cabeca;
}

//retornando numero de elementos

int tamanho(LISTA* l){
    PONT end = l->cabeca->prox;
    int tamanho = 0;
    while(end != l->cabeca){
        tamanho++;
        end = end->prox;
    }
    return tamanho;
}

//exibição

void exibirLista(LISTA* l){
    PONT end = l->cabeca->prox;
    printf("lista: ");
    while(end != l->cabeca){
        printf("%i ", end->reg.chave);
        end = end->prox;
    }
    printf("\n");
}

// Busca sequencial 

PONT buscaSentinela(LISTA* l, int chave){
    PONT end = l->cabeca->prox;
    l->cabeca->reg.chave = chave;
    while(pos->reg.chave != chave) pos = pos->prox;
    if (pos != l->cabeca) return pos;
    return NULL;
}

// Inserção de um elemento

PONT buscaSeqExc(LISTA* l, TIPOCHAVE ch, PONT* ant){
    *ant = l ->cabeca;
    PONT atual = l->cabeca->prox;
    l->cabeca->reg.chave = ch;
    while(atual->reg.chave < ch){
        *ant = atual;
        atual = atual->prox;
    }
    if(atual != l-> cabeca && atual->reg.chave == ch) return atual;
    return NULL;
}

        // desse modo, apenas necessita de verificação caso o atual endereço seja diferente do nó cabeça
        // se for igual, então a chave não foi encontrada
        


//excluindo elemento

bool excluirElemLista(LISTA* l, TIPOCHAVE ch){
    PONT ant, i;
    if(i == NULL) return false;
    *ant ->PROX = i->prox;
    free(i);
    return true;
}
 