//--+ Inclusão das bibliotecas necessárias +--//
#include <stdio.h>
#include <stdlib.h>

//--+ Declaração do nó da pilha. Cada nó possui uma variável do tipo 'nó' que aponta para o 'próximo'. +--//
typedef struct no
{
    int num;
    struct no *prox;
}No;

//--+ Declaração de struct Pilha. A pilha possui um 'No' denomidado 'Topo' e uma variável de tamanho. +--//
typedef struct
{
    No *topo;
    int tam;

}Pilha;

//--+ Inicialização da pilha. Inicialmente, o topo da pilha é NULO, e o tamanho é zero. +--//
void inicializarPilha(Pilha *pilha){
  
  pilha->topo = NULL;
  pilha->tam = 0;
  
}

//--+ Função para inserção na pilha, passando a pilha e o número que será inserido no topo da pilha +--//
int push(Pilha *pilha, int num)
{
  
    No *novo = malloc(sizeof(No));
    novo->num = num;
    novo->prox = pilha->topo;
    pilha->topo = novo;
    pilha->tam++;
  
}

//--+ Função para remoção da pilha. A pilha é passada por referência e o número no 'topo' será removido +--//
int pop(Pilha *pilha)
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

//--+ Função principal +--//
int main()
{
    //--+ DEclaração a pilha e outra variáveis +--//
    Pilha pilha;
    int num;
    int fatorial = 1;
    //--+ Inicializa a pilha +--//
    inicializarPilha(&pilha);

    printf("Insira o número que deseja ver o fatorial: ");
    scanf("%d", &num);
        
    //--+ Adiciona o número na lista e o decrementa até que ele seja zero +--//
    while(num != 0){
        push(&pilha, num);
        num--;
    }

    //--+ Remove o topo da pilha e multiplica ele com o fatorial até o topo ser NULO. +--//
    while(pilha.topo){
      fatorial *= pilha.topo->num;
      pop(&pilha);
    }

    //--+ Imprime o faotrial +--//
    printf("Fatorial do número: %d", fatorial);
}
