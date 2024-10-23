#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int valor;     
    int quantidade;
    struct node *esquerdo;
    struct node *direito;
} node;

node *cria_node(int valor){
    node *temp = malloc(sizeof(node));
    temp->valor = valor;
    temp->quantidade = 1;
    temp->direito = NULL;
    temp->esquerdo = NULL;

    return temp;
}

void adiciona_node(node *novo, node **atual){
    if(*atual == NULL){
        *atual = novo;
        return;
    }
    if(novo->valor > (*atual)->valor){
        adiciona_node(novo, &(*atual)->direito);
        return;
    }
    if(novo->valor < (*atual)->valor){
        adiciona_node(novo, &(*atual)->esquerdo);
        return;
    }
    if(novo->valor == (*atual)->valor){
        (*atual)->quantidade += 1;
        return;
    }
}

void printa_infixo(node *atual){
    if(atual == NULL){
        return;
    }
    printa_infixo(atual->esquerdo);
    printf("%i", atual->valor);
    if(atual->quantidade > 1){
        printf("(%i)", atual->quantidade);
    }
    printf(" ");
    printa_infixo(atual->direito);
}

void printa_prefixo(node *atual){
    if(atual == NULL){
        return;
    }
    printf("%i", atual->valor);
    if(atual->quantidade > 1){
        printf("(%i)", atual->quantidade);
    }
    printf(" ");
    printa_prefixo(atual->esquerdo);
    printa_prefixo(atual->direito);
}

void printa_posfixo(node *atual){
    if(atual == NULL){
        return;
    }
    printa_posfixo(atual->esquerdo);
    printa_posfixo(atual->direito);
    printf("%i", atual->valor);
    if(atual->quantidade > 1){
        printf("(%i)", atual->quantidade);
    }
    printf(" ");
}

int busca_valor(int valor, node *atual){
    if(atual == NULL){
        return 0;
    }
    if(atual->valor == valor){
        return 1;
    }
    if(valor < atual->valor){
        return busca_valor(valor, atual->esquerdo);
    }
    if(valor > atual->valor){
        return busca_valor(valor, atual->direito);
    }
    return 0;
}

int conta_nodes(node *atual){
    if(atual == NULL){
        return 0;
    }
    int esquerda = conta_nodes(atual->esquerdo);
    int direita = conta_nodes(atual->direito);
    return direita + esquerda + 1;
}

int conta_altura(node *atual){
    if(atual == NULL){
        return -1;
    }
    int esquerda = conta_altura(atual->esquerdo);
    int direita = conta_altura(atual->direito);
    if(esquerda > direita){
        return esquerda + 1;
    }
    else{
        return direita + 1;
    }
}

int encontra_predecessor(node **atual){
    if((*atual)->direito == NULL){ // Está no predecessor.
        int valor_predecessor = (*atual)->valor;
        node *temp = *atual;
        if((*atual)->esquerdo == NULL){
            *atual = NULL;
        }
        else{
            *atual = (*atual)->esquerdo;
        }
        free(temp);
        return valor_predecessor;
    }
    else{ // Não está no predecessor.
        return encontra_predecessor(&(*atual)->direito);
    }
    return 0;
}

void deleta_node(node **atual, int valor){
    if(*atual == NULL){
        return;
    }
    if(valor < (*atual)->valor){
        deleta_node(&(*atual)->esquerdo, valor);
        return;
    }
    if(valor > (*atual)->valor){
        deleta_node(&(*atual)->direito, valor);
        return;
    }
    if(valor == (*atual)->valor){
        // Mais de um do valor
        if((*atual)->quantidade > 1){
            (*atual)->quantidade -= 1;
            return;
        }
        node *temp = *atual; // Guarda node que será liberado.

        // Node tem 1 ou 0 filhos
        if((*atual)->esquerdo == NULL){
            *atual = (*atual)->direito;
            free(temp);
        }
        else if((*atual)->direito == NULL){
            *atual = (*atual)->esquerdo;
            free(temp);
        }
        // Nó tem 2 filhos
        else{
            (*atual)->valor = encontra_predecessor(&(*atual)->esquerdo);
        }

    }

}

int main(){
    node *raiz = NULL;

    adiciona_node(cria_node(5), &raiz);
    adiciona_node(cria_node(10), &raiz);
    adiciona_node(cria_node(5), &raiz);
    adiciona_node(cria_node(4), &raiz);
    printa_posfixo(raiz);
    printf("\n");
    printf("%i\n", busca_valor(5, raiz));
    printf("%i\n", busca_valor(4, raiz));
    printf("%i\n", busca_valor(10, raiz));
    printf("%i\n", busca_valor(3, raiz));
    printf("%i\n", busca_valor(7, raiz));
    printf("%i\n", conta_nodes(raiz));
    printf("%i\n", conta_altura(raiz));
    adiciona_node(cria_node(7), &raiz);
    printf("%i\n", conta_altura(raiz));
    printa_infixo(raiz);
    printf("\n");
    deleta_node(&raiz, 5);
    deleta_node(&raiz, 5);
    printa_infixo(raiz);
    printf("\n");
    deleta_node(&raiz, 7);
    printa_infixo(raiz);
    printf("\n");

    return 0;
}