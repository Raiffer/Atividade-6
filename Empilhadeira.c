#include <stdio.h>
#include <stdlib.h>

typedef struct caixa{
    int peso;
    int num;
    struct caixa * prox;
}caixa;

caixa * A = NULL;
caixa * B = NULL;
caixa * C = NULL;

void retornar_caixas(){
    caixa * bu = B;
    caixa * aux = C;
    printf("Retornando as Caixas para a Pilha A...\n");
    while (aux != NULL){
        printf("Movendo a Caixa %d da Pilha C para a Pilha A.\n", aux->num);
        C = C->prox;
        aux->prox = A;
        A = aux;
        aux = C;
    }
    while (bu != NULL){
        printf("Movendo a Caixa %d da Pilha B para a Pilha A.\n", aux->num);
        B = B->prox;
        bu->prox = A;
        A = bu;
        bu = B;
    }
}

void mover_caixas(int peso){
    printf("Caixa de peso superior, movendo caixas menores...\n");
    caixa*bu = A;
    while(bu != NULL){
        if (peso == 3){
            if (bu->peso == 3){
                printf("Movendo a caixa %d para a Pilha B.\n", bu->num);
                A = A->prox;
                bu->prox = B;
                B = bu;
                bu = A;
            }
        }else if (peso == 5){
            if (bu->peso == 3){
                printf("Movendo a caixa %d para a Pilha B...\n", bu->num);
                A = A->prox;
                bu->prox = B;
                B = bu;
                bu = A;
            }else if(bu->peso == 5){
                printf("Movendo a caixa %d para a Pilha C...\n", bu->num);
                A = A->prox;
                bu->prox = C;
                C = bu;
                bu = A;
            }
        }
    }


}

void cria_caixa(int peso, int num){

    caixa * novo = malloc(sizeof(caixa));
    novo->peso = peso;
    novo->num = num;
    novo->prox = NULL;

    if (A == NULL)
        A = novo;
    else{
        if (A->peso < novo->peso){
            if (peso == 5)
                mover_caixas(3);
            else if (peso == 7)
                mover_caixas(5);
            novo->prox = A;
            A = novo;
            retornar_caixas();
        }else {
            novo->prox = A;
            A = novo;
        }
    }
}

void imprimir(){
    caixa * aux = A;
    while(aux != NULL){
        printf("Caixa %d, Peso %d.\n", aux->num, aux->peso);
        aux = aux->prox;
    }
    printf("\n");
}

int main(){
    cria_caixa(5, 88);
    cria_caixa(3, 84);
    cria_caixa(3, 81);
    cria_caixa(7, 80);
    imprimir();
}