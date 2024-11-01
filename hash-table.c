#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Tamanho de elementos na tabela.
#define tamanho_tabela 1001 

// Struct armazenada na tabela hash.
typedef struct dado{
    char strg[50];
    int num;
    struct dado *proximo;
} dado;

// Array de ponteiros para a struct criada.
dado *tabela_hash[tamanho_tabela];

// Inicializa todas as posições da tabela como NULL.
void inicia_tabela(){
    for(int i = 0; i < tamanho_tabela; i++){
        tabela_hash[i] = NULL;
    }
}

// Calcula o valor hash do ponteiro passado com base nos seus atributos.
int valor_hash(dado *novo_dado){
    int valor_hash = 0;
    int tamanho_string = strnlen(novo_dado->strg, 50);
    for(int i = 0; i < tamanho_string; i++){
        valor_hash += (novo_dado->strg[i] * 31);
        valor_hash = valor_hash % tamanho_tabela;
    }
    valor_hash += (novo_dado->num * 17);
    valor_hash = valor_hash % tamanho_tabela;
    
    return valor_hash;
}

// Função para encontrar último elemento da lista encadeada caso haja uma colisão de índices.
void encontra_posicao(dado *adicionado, dado **posicao_atual){
    if(*posicao_atual == NULL){
        *posicao_atual = adicionado;
        return;
    }
    encontra_posicao(adicionado, &(*posicao_atual)->proximo);
}

// Função principal para adicionar um ponteiro ao seu índice correspondente.
void adiciona_na_tabela(dado *adicionado){
    int index = valor_hash(adicionado);
    if(tabela_hash[index] == NULL){
        tabela_hash[index] = adicionado;
    }
    else{
        encontra_posicao(adicionado, &tabela_hash[index]->proximo);
    }
}

// Função para printar a lista encadeada de cada índice. Caso hajam colisões, mais de um elemento será printado.
void printa_lista_encadeada(dado *atual){
    if(atual == NULL){
        return;
    }
    printf("\t%s", atual->strg);
    printa_lista_encadeada(atual->proximo);
}

// Percorre a tabela hash e printa o conteúdo de cada índice.
void printa_tabela(){
    for(int i = 0; i < tamanho_tabela; i++){
        if(tabela_hash[i] == NULL){
            printf("%i\t---\n", i);
        }
        else{
            printf("%i", i);
            printa_lista_encadeada(tabela_hash[i]);
            printf("\n");
        }
    }
    printf("\n");
}

int main(){
    inicia_tabela();
    dado temp = {.strg = "Vapo", .num = 10, .proximo = NULL};
    dado temp1 = {.strg = "Leite", .num = 89, .proximo = NULL};
    dado temp2 = {.strg = "Café", .num = 90, .proximo = NULL};
    dado temp3 = {.strg = "Açúcar", .num = 91, .proximo = NULL};
    dado temp4 = {.strg = "Arroz", .num = 92, .proximo = NULL};
    dado temp5 = {.strg = "Feijão", .num = 93, .proximo = NULL};
    dado temp6 = {.strg = "Macarrão", .num = 94, .proximo = NULL};
    dado temp7 = {.strg = "Óleo", .num = 95, .proximo = NULL};
    dado temp8 = {.strg = "Sal", .num = 96, .proximo = NULL};
    dado temp9 = {.strg = "Farinha", .num = 97, .proximo = NULL};
    dado temp10 = {.strg = "Milho", .num = 98, .proximo = NULL};
    dado temp11 = {.strg = "Ervilha", .num = 99, .proximo = NULL};
    dado temp12 = {.strg = "Lentilha", .num = 100, .proximo = NULL};
    dado temp13 = {.strg = "Amendoim", .num = 101, .proximo = NULL};
    dado temp14 = {.strg = "Castanha", .num = 102, .proximo = NULL};
    dado temp15 = {.strg = "Aveia", .num = 103, .proximo = NULL};
    dado temp16 = {.strg = "Cenoura", .num = 104, .proximo = NULL};
    dado temp17 = {.strg = "Batata", .num = 105, .proximo = NULL};
    dado temp18 = {.strg = "Tomate", .num = 106, .proximo = NULL};
    dado temp19 = {.strg = "Cebola", .num = 107, .proximo = NULL};
    dado temp20 = {.strg = "Alho", .num = 108, .proximo = NULL};
    dado temp21 = {.strg = "Alface", .num = 109, .proximo = NULL};
    dado temp22 = {.strg = "Aveia", .num = 103, .proximo = NULL};
    adiciona_na_tabela(&temp);
    adiciona_na_tabela(&temp1);
    adiciona_na_tabela(&temp2);
    adiciona_na_tabela(&temp3);
    adiciona_na_tabela(&temp4);
    adiciona_na_tabela(&temp5);
    adiciona_na_tabela(&temp6);
    adiciona_na_tabela(&temp7);
    adiciona_na_tabela(&temp8);
    adiciona_na_tabela(&temp9);
    adiciona_na_tabela(&temp10);
    adiciona_na_tabela(&temp11);
    adiciona_na_tabela(&temp12);
    adiciona_na_tabela(&temp13);
    adiciona_na_tabela(&temp14);
    adiciona_na_tabela(&temp15);
    adiciona_na_tabela(&temp16);
    adiciona_na_tabela(&temp17);
    adiciona_na_tabela(&temp18);
    adiciona_na_tabela(&temp19);
    adiciona_na_tabela(&temp20);
    adiciona_na_tabela(&temp21);
    adiciona_na_tabela(&temp22);
    printa_tabela();

    return 0;
}