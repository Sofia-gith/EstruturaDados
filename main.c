#include <stdio.h>
#include <malloc.h>
#define alturaMaxima 225


typedef struct{
    int peso;
    int altura;
} PesoAltura;

int main() {


    
    //agora criando um ponteiro para essa estrutura
    PesoAltura* pessoa1 = (PesoAltura*) malloc(sizeof(PesoAltura));
    pessoa1->peso = 80;
    pessoa1->altura = 185;
    printf("Peso: %i, ALtura %i. ", pessoa1->peso, pessoa1->altura);

    if(pessoa1->altura>alturaMaxima){
        printf("Altura acima da maxima \n");
    }else{
        printf("Altura abaixo da maxima \n");
    }
    
    // printf("Hello, World!\n");
    return 0;
}