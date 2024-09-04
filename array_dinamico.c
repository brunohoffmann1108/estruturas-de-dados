// Array dinâmico - att de estrutura de dados.
#include <stdlib.h>
#include <stdio.h>
unsigned int quantidade_elementos = 0;
int *elementos = NULL;

void adiciona_novo_elemento(){
    int valor_adicionado;
    printf("Insira o valor do elemento: ");
    scanf("%i", &valor_adicionado);
    while(getchar() != '\n');
    printf("\n");
    elementos = realloc(elementos, (quantidade_elementos + 1) * sizeof(int));
    elementos[quantidade_elementos] = valor_adicionado;
    quantidade_elementos += 1;
}

void printa_lista(){
    if(quantidade_elementos == 0){
        return;
    }
    for(unsigned int i = 0; i < quantidade_elementos; i++){
        printf("%i ", elementos[i]);
    }
    printf("\n\n");
}

void muda_lista(){
    unsigned int index;
    int novo_valor;
    printf("Insira o endereco a ser modificado: ");
    scanf("%i", &index);
    if(index >= quantidade_elementos){
        printf("Endereco indisponivel.");
        printf("\n\n");
        return;
    }
    printf("Insira o novo valor do endereco: ");
    scanf("%i", &novo_valor);
    printf("\n");

    elementos[index] = novo_valor;
}

void limpa_lista(){
    free(elementos);
    elementos = NULL;
    quantidade_elementos = 0;
}

void remove_em_endereco(){
    unsigned int endereco_do_valor;
    printf("Insira o endereco do valor a ser removido: ");
    scanf("%i", &endereco_do_valor);
    if(endereco_do_valor >= quantidade_elementos){
        printf("Endereco indisponivel.");
        printf("\n\n");
        return;
    }
    for(unsigned int i = endereco_do_valor; i < quantidade_elementos - 1; i++){
        elementos[i] = elementos[i + 1];
    }
    elementos = realloc(elementos, (quantidade_elementos - 1) * sizeof(int));
    quantidade_elementos -= 1;
}

void menu(){
    int opcao;
    do{
        printf("1. Adicionar elemento\n");
        printf("2. Mostrar lista de elementos\n");
        printf("3. Mudar valor em um endereco\n");
        printf("4. Limpar lista\n");
        printf("5. Remover em um endereco\n");
        printf("Escolha: ");
        scanf("%i", &opcao);
        while(getchar() != '\n');
        printf("\n");
        switch(opcao){
            case 1: {
                adiciona_novo_elemento();
                break;
            }
            case 2: {
                printa_lista();
                break;
            }
            case 3: {
                if(quantidade_elementos == 0){
                    break;
                }
                muda_lista();
                break;
            }
            case 4: {
                limpa_lista();
                break;
            }
            case 5: {
                if(quantidade_elementos == 0){
                    break;
                }
                remove_em_endereco();
                break;
            }
        }
    } while(opcao != 0);

}

int main(){
    menu();
    return 0;
} 
