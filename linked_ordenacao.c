#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int valor;
    struct node *proximo;

} node;

void menu(){
    printf("\n");
    printf("1\tInserir valor\n");
    printf("2\tExcluir valor\n");
    printf("3\tMostrar lista\n");
    printf("4\tOrdenar lista\n");
    printf("5\tSair\n");
    printf("Escolha: ");
}

node *cria_node(int valor){
    node *temp = malloc(sizeof(node));
    temp->valor = valor;
    temp->proximo = NULL;
    return temp;
}

void adiciona_valor(node *novo, node **head){
    if(*head == NULL){
        *head = novo;
        return;
    }
    novo->proximo = *head;
    *head = novo;
}

void printa_lista(node *head){
    printf("\n");
    while(head != NULL){
        printf("%i ", head->valor);
        head = head->proximo;
    }
    printf("\n");
}

void remove_valor(int valor, node **head){
    if((*head)->valor == valor){
        node *temp = *head;
        *head = (*head)->proximo;
        free(temp);
        return;
    }
    while((*head)->proximo != NULL){
        if((*head)->proximo->valor == valor){
            node *temp = (*head)->proximo;
            (*head)->proximo = (*head)->proximo->proximo;
            free(temp);
            return;
        }
        head = &(*head)->proximo;
    }
}

void bubble_sort(node *atual){
    node *ultimo = NULL;
    node *primeiro = atual;
    while(ultimo != primeiro){
        while(atual->proximo != ultimo){
            if(atual->valor > atual->proximo->valor){
                int temp = atual->valor;
                atual->valor = atual->proximo->valor;
                atual->proximo->valor = temp;
            }
            atual = atual->proximo;
        }
        ultimo = atual;
        atual = primeiro;
    }    
}

int main(){
    node *head = NULL;
    int opcao;
    do{
        menu();
        scanf("%i", &opcao);
        while(getchar() != '\n');

        switch(opcao){
            case 1:{
                int valor;
                printf("Insira o valor inserido: ");
                scanf("%i", &valor);
                adiciona_valor(cria_node(valor), &head);
                break;
            }
            case 2:{
                if(head != NULL){
                    int valor;
                    printf("Insira o valor deletado: ");
                    scanf("%i", &valor);
                    remove_valor(valor, &head);
                }
                    break;
            }
            case 3:{
                printa_lista(head);
                break;
            }
            case 4:{
                if(head != NULL){
                    bubble_sort(head);
                }
                break;
            }
        }
    } while(opcao != 5);


    return 0;
}