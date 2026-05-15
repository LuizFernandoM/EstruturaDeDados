#include <cstdlib>
#include  <stdio.h>


typedef struct NO {
    int valor; // A carga util (payload)
    struct NO *prox; // O ponteiro para o proximo
};


//funçao de inserçao de dado no inicio o(1)
void inserirInicio(NO **head, int valor) {
    //1 pedindo espaço no heap
    NO *novo_no = (NO*) malloc(sizeof(NO));

    //2. prenchendo valores
    novo_no->valor = valor;

    //3. aponta para o antigo primeiro
    novo_no->prox = *head;

    //4. ensino a lista do novo primeiro
    *head = novo_no;

    printf("Valor inserido com sucesso. [%d] em o(1) \n", valor);
}

// funçao de inserção para inserir no fim
void inserirFim(NO **head, int valor) {
    //1. pede memoria ao heap
    NO *novo_no = (NO*) malloc(sizeof(NO));

    //2. prenche os dados
    novo_no->valor = valor;
    novo_no->prox = NULL;

    //3. verifica se a lista esta vazia
    if (*head == NULL) {
        printf("a lista esta vazia");
        printf("[%d] inserido como primeiro e ultimo nó \n", valor);
        return;
    }
    //4. SE não estiver vazio, varre até o fim;
    NO *atual = *head;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    //5. chegamos no ultimo
    atual->prox = novo_no;
    printf("sucesso! [%d] inserido no fim em O(n) \n", valor);

}

//funcao de remover inicio
void removerInicio(NO **head) {
    if (*head == NULL) {
        printf("a lista esta vazia");
        return;
    }
//1. salvo o nó que vai morrer
NO *no_removido = *head;

//2. o head pula para o proximo da fila
*head = (*head)->prox;

//3. remove do heap
free(no_removido);

    printf("sucesso! [%d] removido \n", (*head)->valor);
}

//remover do fim
void removerFim(NO **head) {
    if (*head == NULL) {
        printf("a lista esta vazia");
        return;
    }
    //1. se tiver só um elemento

    if ((*head)->prox == NULL) {
        printf("sucesso! [%d] removido \n", (*head)->valor);
        free(*head);
        *head = NULL;
        return;
    }
    //2. varrer ate o penultimo
    NO *atual = *head;
    while (atual->prox->prox != NULL) {
        atual = atual->prox;

    }

    //3. fazer a remoçao do ultimo
    NO *no_removido = atual->prox;
    printf("sucesso! [%d] removido do fim \n", (*head)->valor);
    free(no_removido);

    //4. penultimo se torna o ultimo/
    atual->prox = NULL;

}
// Busca Linear - Complexidade: O(n)
void buscaValor(NO *head, int valor) {
    NO *atual = head;
    int posicao = 0;

    while (atual != NULL) {
        if (atual->valor == valor) {
            printf(">> ENCONTRADO! O valor [%d] esta no indice %d (apos %d pulos).\n", valor, posicao, posicao);
            return;
        }
        atual = atual->prox;
        posicao++;
    }

    printf(">> FALHA: O valor [%d] nao existe nesta lista. Vareu O(n) atoa.\n", valor);
}




int main() {
    //inicia a lista vazia
    NO *lista = NULL;
    int opcao, valor;

    // populando a lista com alguns dados
    inserirInicio (&lista, 33);
    inserirInicio (&lista, 22);
    inserirInicio (&lista, 11);

    do {
        printf("===simulador lista encadeada===\n");
        printf("1 inserir no inicio [ o(1) ] \n");
        printf("2 inserir no fim [ o(n) ] \n");
        printf("3 remover no inicio [ o(1) ] \n");
        printf("4 remover no fim [ o(n) ] \n");
        printf("5 buscar valor\n");
        printf("0 sair do programa\n");
        scanf("%d", &opcao);

        system("pause");
        system("cls");

        switch (opcao) {
            case 1:
                printf("Inserir no inicio \n");
                scanf("%d", &valor);
                inserirInicio(&lista, valor);
                break;

            case 2:
                printf("Inserir no fim \n");
                scanf("%d", &valor);
                inserirFim(&lista, valor);
                break;

            case 3:
                removerInicio(&lista);
                break;

            case 4:
                removerFim(&lista);
                break;

            case 5:
                printf("Buscar valor\n");
                scanf("%d", &valor);
                buscaValor(&lista, valor);
                break;

            case 0:
                printf("Sair\n");
                break;

            default:
                printf("opcao invalida\n");

        }

    }while (opcao != 0);
}