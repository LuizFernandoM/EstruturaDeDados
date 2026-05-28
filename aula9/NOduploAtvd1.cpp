#include <stdio.h>
#include <cstdio>
#include <cstdlib>

typedef struct NoDuplo {
    struct NoDuplo *anterior;  // O Retrovisor
    int dado;                   // A Carga Útil (Payload)
    struct NoDuplo *proximo;   // O Para-brisa
} NoDuplo;

void imprimirDado(NoDuplo *head) {
    if (head == NULL) {
        printf ("fila vazia\n");
        return;
    }

    NoDuplo *atual = head;
    NoDuplo *ultimo = NULL;

    while (atual != NULL) {
        printf("Dado %d: ", atual->dado);
        if (atual->proximo != NULL) printf(" <==> ");
            ultimo = atual;
            atual = atual->proximo;

        printf("-> ");
    }
    while (ultimo != NULL) {
        printf("Dado %d: ", ultimo->dado);
    if (ultimo->anterior != NULL) printf(" <==> ");

        ultimo = ultimo->anterior;

    }
    printf(" -> NULL\n\n");

}

void inserirInicio(NoDuplo **head, int dado) {
    NoDuplo *novo = (NoDuplo*) malloc(sizeof(NoDuplo));
    novo->dado = dado;
    novo->anterior = NULL; // Como é o primeiro, ninguém está atrás
    novo->proximo = *head; // O para-brisa aponta pro antigo primeiro

    // Se a fila não estava vazia, o antigo primeiro precisa olhar para trás e ver o novo nó
    if (*head != NULL) {
        (*head)->anterior = novo;
    }

    *head = novo; // O sistema reconhece o novo Head
    printf(">> [%d] Inserido no INICIO.\n", dado);
}

int main() {
    NoDuplo *fila = NULL;
    inserirInicio(&fila, 1);
    inserirInicio(&fila, 2);
    inserirInicio(&fila, 3);


    imprimirDado(fila);
}

