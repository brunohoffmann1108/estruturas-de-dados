#include <stdio.h>
#include <stdlib.h>

int tamanho = 0;

typedef struct node{
    int valor;
    int quantidade;
    struct node *maior;
    struct node *menor;
} node;

void menu(){
    printf("\n");
    printf("1\tInserir um elemento\n");
    printf("2\tBuscar um elemento\n");
    printf("3\tExibir elementos em ordem\n");
    printf("4\tRemover um elemento\n");
    printf("5\tMostrar a altura da arvore\n");
    printf("6\tEncerrar\n");
    printf("Escolha: ");
}

node *cria_node(int valor){
    node *temp = malloc(sizeof(node));
    temp->maior = NULL;
    temp->menor = NULL;
    temp->valor = valor;
    temp->quantidade = 1;
    
    return temp;
}

void adiciona_node(node *novo, node **posicao_atual){
    if(*posicao_atual == NULL){
        *posicao_atual = novo;
        tamanho += 1;
    }
    else if((*posicao_atual)->valor == novo->valor){
        (*posicao_atual)->quantidade += 1;
    }
    else if(novo->valor < (*posicao_atual)->valor){
        adiciona_node(novo, &(*posicao_atual)->menor);
    }
    else if(novo->valor > (*posicao_atual)->valor){
        adiciona_node(novo, &(*posicao_atual)->maior);
    }
}

void printa_em_ordem(node *node_printado){
    if(node_printado == NULL){
        return;
    }
    printa_em_ordem(node_printado->menor);
    printf("%i(%i) ", node_printado->valor, node_printado->quantidade);
    printa_em_ordem(node_printado->maior);
}

void busca_elemento(node *node_atual, int valor){
    if(node_atual == NULL){
        printf("Valor nao esta nesta arvore\n");
        return;
    }
    if(node_atual->valor == valor){
        printf("Valor esta na arvore\n");
        return;
    }
    else if(valor < node_atual->valor){
        if(node_atual->menor == NULL){
            printf("Valor nao esta nesta arvore\n");
            return;
        }
        busca_elemento(node_atual->menor, valor);
    }
    else if(valor > node_atual->valor){
        if(node_atual->maior == NULL){
            printf("Valor nao esta nesta arvore\n");            
            return;
        }
        busca_elemento(node_atual->maior, valor);
    }
}

int calcula_altura(node *node_atual){
    if(node_atual == NULL){
        return -1;
    }
     int altura_esquerda = calcula_altura(node_atual->menor);
     int altura_direita = calcula_altura(node_atual->maior);

     if(altura_esquerda > altura_direita){
        return altura_esquerda + 1;
     }
     else{
        return altura_direita + 1;
     }
}

int main(){
    node *raiz = NULL;
    int opcao;
    while(opcao != 6){
        menu();
        scanf("%i", &opcao);
        while(getchar() != '\n');
        printf("\n");

        switch(opcao){
            case 1:{
                int valor;
                printf("Insira o valor adicionado: ");
                scanf("%i", &valor);
                while(getchar() != '\n');
                adiciona_node(cria_node(valor), &raiz);
                break;
            }

            case 2:{
                if(tamanho > 0){
                    int valor;
                    printf("Insira o valor buscado: ");
                    scanf("%i", &valor);
                    while(getchar() != '\n');
                    busca_elemento(raiz, valor);
                }
                break;
            }

            case 3:{
                if(tamanho > 0){
                    printa_em_ordem(raiz);
                }
                break;
            }

            case 4:{

                break;
            }

            case 5:{
                if(tamanho > 0){
                    int altura = calcula_altura(raiz);
                    printf("Altura: %i\n", altura);
                }
                break;
            }

        }
    }

    return 0;
}