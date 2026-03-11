#include <stdio.h>
#include <malloc.h>


typedef int TIPOCHAVE;


typedef struct{
    TIPOCHAVE chave;
} REGISTRO;

typedef struct aux{
    REGISTRO reg;
    struct aux* prox;
}ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct {
    PONT topo;
}PILHA;


//inicializando a pilha
void inicializarPilha(PILHA* p){
    p->topo = NULL;
}

//retornando numero de elementos

int tamanho(PILHA* p){
   PONT end = p->topo;
   int cont = 0;
   while(end != NULL){
       cont++;
       end = end->prox;
   }
   return cont;
}

///impressão da pilha
void exibirPilha(PILHA* p){
    PONT end = p->topo;
    printf("Pilha: ");
    while(end != NULL){
        printf("%i ", end->reg.chave);
        end = end->prox;
    }
    printf("\n");
}


// Inserção de elementos (push)

bool push(PILHA* p, REGISTRO reg){
    PONT novo = (PONT) malloc(sizeof(ELEMENTO));
    if(novo == NULL) return false;
    novo->reg = reg;
    novo->prox = p->topo;
    p->topo = novo;
    return true;
} 

//exclusão do elemento (pop)

bool pop(PILHA* p, REGISTRO* reg){
    if(p->topo == NULL) return false;
   * reg = p->topo->reg;
   PONT apagar = p->topo;
   p->topo = p->topo->prox;
   free(apagar);
   return true;
}

// reinicializando a pilha

void reinicializarPilha(PILHA* p){
    PONT apagar;
    PONT posicao = p->topo;
    while(posicao != NULL){
        apagar = posicao;
        posicao = posicao->prox;
        free(apagar);
    }
    p->topo = NULL;
}
