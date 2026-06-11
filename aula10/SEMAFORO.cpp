#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct Semaforo {
    char via[50];
    struct Semaforo *prox;
} Semaforo;

// Cria um novo semáforo
Semaforo* criarSemaforo(char via[]) {
    Semaforo *novo = (Semaforo*) malloc(sizeof(Semaforo));

    strcpy(novo->via, via);
    novo->prox = NULL;

    return novo;
}

// Insere uma via na lista circular
void inserirVia(Semaforo **inicio, char via[]) {

    Semaforo *novo = criarSemaforo(via);

    if (*inicio == NULL) {
        *inicio = novo;
        novo->prox = novo;
        return;
    }

    Semaforo *ultimo = *inicio;

    while (ultimo->prox != *inicio) {
        ultimo = ultimo->prox;
    }

    ultimo->prox = novo;
    novo->prox = *inicio;
}

// Avança para o próximo semáforo
Semaforo* avancarSemaforo(Semaforo *atual) {
    return atual->prox;
}

// Exibe o estado do semáforo atual
void exibirSemaforo(char via[]) {

    printf("\n");
    printf("=========================================\n");
    printf("          SMART CITY - ROTATORIA\n");
    printf("=========================================\n");
    printf(" VIA LIBERADA: %s\n", via);
    printf("=========================================\n");

    printf("[🟢] VERDE\n");
    sleep(2);

    printf("[🟡] AMARELO\n");
    sleep(1);

    printf("[🔴] VERMELHO\n");
    sleep(1);

    printf("=========================================\n");
}

// Mostra a estrutura da lista circular
void mostrarRotatoria(Semaforo *inicio) {

    if (inicio == NULL)
        return;

    Semaforo *aux = inicio;

    printf("\nESTRUTURA DA ROTATORIA:\n\n");

    do {
        printf("[%s]", aux->via);

        aux = aux->prox;

        if (aux != inicio)
            printf(" -> ");

    } while (aux != inicio);

    printf(" -> (inicio)\n");
}

int main() {

    Semaforo *rotatoria = NULL;

    inserirVia(&rotatoria, "Avenida Principal");
    inserirVia(&rotatoria, "Rua Norte");
    inserirVia(&rotatoria, "Rua Sul");
    inserirVia(&rotatoria, "Avenida Central");

    Semaforo *atual = rotatoria;

    printf("=========================================\n");
    printf("      SISTEMA DE CONTROLE DE TRAFEGO\n");
    printf("=========================================\n");

    mostrarRotatoria(rotatoria);

    printf("\nIniciando simulacao...\n");

    while (1) {

        exibirSemaforo(atual->via);

        atual = avancarSemaforo(atual);

        sleep(1);
    }

    return 0;
}