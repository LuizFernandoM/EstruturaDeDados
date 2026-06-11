#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct Semaforo {
    int id;
    struct Semaforo *prox;
    struct Semaforo *ant;
} Semaforo;

Semaforo* criarSemaforo(int id) {
    Semaforo *novo = (Semaforo*)malloc(sizeof(Semaforo));

    novo->id = id;
    novo->prox = novo;
    novo->ant = novo;

    return novo;
}

void inserirSemaforo(Semaforo **inicio, int id) {

    Semaforo *novo = criarSemaforo(id);

    if (*inicio == NULL) {
        *inicio = novo;
        return;
    }

    Semaforo *ultimo = (*inicio)->ant;

    novo->prox = *inicio;
    novo->ant = ultimo;

    ultimo->prox = novo;
    (*inicio)->ant = novo;
}

void removerSemaforo(Semaforo **inicio, int id) {

    if (*inicio == NULL)
        return;

    Semaforo *atual = *inicio;

    do {

        if (atual->id == id) {

            if (atual->prox == atual) {
                free(atual);
                *inicio = NULL;
                return;
            }

            atual->ant->prox = atual->prox;
            atual->prox->ant = atual->ant;

            if (atual == *inicio)
                *inicio = atual->prox;

            free(atual);
            return;
        }

        atual = atual->prox;

    } while (atual != *inicio);
}

void exibirEstado(int id) {

    printf("\n");
    printf("=================================\n");
    printf("       SEMAFORO %d\n", id);
    printf("=================================\n");

    printf("[🟢] VERDE\n");
    sleep(5);

    printf("[🟡] AMARELO\n");
    sleep(2);

    printf("[🔴] VERMELHO\n");
    sleep(1);

    printf("=================================\n");
}

void mostrarSemaforos(Semaforo *inicio) {

    if (inicio == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    Semaforo *aux = inicio;

    do {
        exibirEstado(aux->id);
        aux = aux->prox;
    } while (aux != inicio);
}


int main() {

    Semaforo *lista = NULL;

    inserirSemaforo(&lista, 1);
    inserirSemaforo(&lista, 2);
    inserirSemaforo(&lista, 3);
    inserirSemaforo(&lista, 4);

    printf("\n======== SISTEMA DE SEMAFOROS ========\n");


    mostrarSemaforos(lista);

    printf("\n>>> Adicionando Semaforo 5...\n");

    inserirSemaforo(&lista, 5);
    mostrarSemaforos(lista);



    printf("\n>>> Removendo Semaforo 3...\n");

    removerSemaforo(&lista, 3);
    mostrarSemaforos(lista);

    return 0;
}