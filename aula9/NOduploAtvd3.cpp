#include <stdio.h>
#include <stdlib.h>

typedef struct NoDuplo {
    struct NoDuplo *anterior;  // O Retrovisor
    int cpf;                   // A Carga Útil (Payload)
    struct NoDuplo *proximo;   // O Para-brisa
} NoDuplo;

int verificarIntegridade(NoDuplo *head) {
    if (head == NULL) {
        printf("fila vazia\n");
        return 0;
    }

    struct NoDuplo *atual = head;
    struct NoDuplo *ultimo = NULL;

    while (atual != NULL) {
        if (atual->proximo != NULL) {
            if (atual->proximo->anterior == atual) {
                return 1;
        }
        }
        ultimo = atual;
        atual = atual->proximo;

    }
    return 0;
}

void inserirInicio(NoDuplo **head, int cpf) {
    NoDuplo *novo = (NoDuplo*) malloc(sizeof(NoDuplo));
    novo->cpf = cpf;
    novo->anterior = NULL; // Como é o primeiro, ninguém está atrás
    novo->proximo = *head; // O para-brisa aponta pro antigo primeiro

    // Se a fila não estava vazia, o antigo primeiro precisa olhar para trás e ver o novo nó
    if (*head != NULL) {
        (*head)->anterior = novo;
    }

    *head = novo; // O sistema reconhece o novo Head
    printf(">> [%d] Inserido no INICIO.\n", cpf);
}

int main() {
    NoDuplo *pref = NULL;

    printf("--- INICIANDO OS TESTES DA LISTA DUPLA ---\n");

    inserirInicio(&pref, 500);
    /*inserirInicio(&pref, 300);
    inserirInicio(&pref, 123);
    inserirInicio(&pref, 456);
    inserirInicio(&pref, 328);*/

    int resultado = verificarIntegridade(pref);
    if (resultado == 1) {
        printf("esta correta a tabela");
    }else {
        printf("esta incorreta a lista");
    }

}