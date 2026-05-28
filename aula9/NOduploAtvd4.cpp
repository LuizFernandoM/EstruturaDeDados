#include <stdio.h>
#include <stdlib.h>

typedef  struct NoDuplo {
    struct NoDuplo *anterior;  // O Retrovisor
    int cpf;                   // A Carga Útil (Payload)
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
        printf("Dado %d: ", atual->cpf);
        if (atual->proximo != NULL) printf(" <==> ");
        ultimo = atual;
        atual = atual->proximo;

        printf("-> ");
    }
    printf(" -> NULL\n\n");

}

void inserirAntes(struct NoDuplo **head, int id_alvo, int novo_id) {
    NoDuplo *atual = *head;

    while (atual != NULL && atual->cpf != id_alvo) {
        atual = atual->proximo;
    }
    if (atual == NULL) {
        printf(">> Erro: CPF [%d] nao encontrado para inserir no meio!\n", id_alvo);
        return;
    }

    NoDuplo *novo = (NoDuplo*) malloc(sizeof(NoDuplo));
    novo->cpf = novo_id;
    novo->proximo = atual->proximo;
    novo->anterior = atual;

    // 3: Se existir alguém na frente, esse alguém precisa soltar o 'atual' e segurar o 'novo' pelo retrovisor
    if (atual->proximo != NULL) {
        atual->proximo->anterior = novo;
    }

    // 4: O alvo original solta quem estava na frente e passa a segurar o novo
    atual->proximo = novo;

    printf(">> [%d] Inserido LOGO APOS o [%d].\n", id_alvo, novo_id);
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
    inserirInicio(&pref, 300);
    inserirInicio(&pref, 123);
    inserirInicio(&pref, 456);
    inserirInicio(&pref, 328);

    inserirAntes(&pref, 300, 67); // Insere o 600 logo após o 500

    printf("lista de chegada alternada \n");
    imprimirDado(pref);


}

