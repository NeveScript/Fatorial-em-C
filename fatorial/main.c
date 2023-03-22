#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int num;
    struct no *prox;
}No;

typedef struct
{
    No *topo;
    int tam;
}Pilha;

int push(Pilha *pilha, int num)
{
    No *novo = malloc(sizeof(No));
    novo->num = num;
    novo->prox = pilha->topo;
    pilha->topo = novo;
    pilha->tam++;
}

int pop(Pilha *)
{
    if(pilha->topo)
    {
        No *remover = malloc(sizeof(No));
        remover = pilha->topo;
        pilha->topo = remover->prox;
        pilha->tam--;
        free(remover);
    } else{
        printf("Pilha vazia!\n\n");
    }
}
int main()
{
    int num;
    printf("Insira o número que deseja ver o f")
    return 0;
}
