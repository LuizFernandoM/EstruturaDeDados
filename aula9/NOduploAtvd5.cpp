#include <stdio.h>
#include <stdlib.h>

typedef struct NoDuplo {
    struct NoDuplo *anterior;
    int cpf;
    struct NoDuplo *proximo;
} NoDuplo;

// INSERIR NO INÍCIO
void inserirInicio(NoDuplo **head, int cpf) {
    NoDuplo *novo = (NoDuplo*) malloc(sizeof(NoDuplo));

    novo->cpf = cpf;
    novo->anterior = NULL;
    novo->proximo = *head;

    if (*head != NULL) {
        (*head)->anterior = novo;
    }

    *head = novo;

    printf(">> [%d] inserido no inicio.\n", cpf);
}

// IMPRIMIR LISTA
void imprimirLista(NoDuplo *head) {
    if (head == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    NoDuplo *atual = head;

    printf("\nLISTA:\n");

    while (atual != NULL) {
        printf("%d", atual->cpf);

        if (atual->proximo != NULL) {
            printf(" <==> ");
        }

        atual = atual->proximo;
    }

    printf("\n\n");
}

// REMOVER CPF
void removerCpf(NoDuplo **head, int cpf_alvo) {

    if (*head == NULL) {
        printf("Fila vazia!\n");
        return;
    }

    NoDuplo *atual = *head;

    // procura o cpf
    while (atual != NULL && atual->cpf != cpf_alvo) {
        atual = atual->proximo;
    }

    // nao encontrou
    if (atual == NULL) {
        printf("CPF [%d] nao encontrado.\n", cpf_alvo);
        return;
    }

    // conecta o anterior ao proximo
    if (atual->anterior != NULL) {
        atual->anterior->proximo = atual->proximo;
    } else {
        // se era o primeiro da lista
        *head = atual->proximo;
    }

    // conecta o proximo ao anterior
    if (atual->proximo != NULL) {
        atual->proximo->anterior = atual->anterior;
    }

    printf("CPF [%d] removido da fila.\n", cpf_alvo);

    free(atual);
}

int main() {

    NoDuplo *fila = NULL;

    inserirInicio(&fila, 100);
    inserirInicio(&fila, 200);
    inserirInicio(&fila, 300);
    inserirInicio(&fila, 400);
    inserirInicio(&fila, 500);

    imprimirLista(fila);

    removerCpf(&fila, 300);

    imprimirLista(fila);

    removerCpf(&fila, 500);

    imprimirLista(fila);

    removerCpf(&fila, 100);

    imprimirLista(fila);

    return 0;
}