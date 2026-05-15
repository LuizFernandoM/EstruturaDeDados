#include <stdio.h>
#include <stdlib.h>

struct No {
    int dado;
    struct No *proximo;
};

// função para inserir após um nó específico
void inserirApos(struct No *head, int id_alvo, int novo_id) {
    struct No *atual = head;

    while (atual != NULL) {
        if (atual->dado == id_alvo) {
            struct No *novo = (struct No*) malloc(sizeof(struct No));
            novo->dado = novo_id;

            // ordem correta (IMPORTANTE)
            novo->proximo = atual->proximo;
            atual->proximo = novo;

            return;
        }

        atual = atual->proximo;
    }
}

// função só pra mostrar a lista
void imprimirLista(struct No *head) {
    struct No *atual = head;

    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

int main() {
    // criando nós iniciais
    struct No *n1 = (struct No*) malloc(sizeof(struct No));
    struct No *n2 = (struct No*) malloc(sizeof(struct No));
    struct No *n3 = (struct No*) malloc(sizeof(struct No));

    // valores
    n1->dado = 100;
    n2->dado = 500; // alvo
    n3->dado = 900;

    // ligando
    n1->proximo = n2;
    n2->proximo = n3;
    n3->proximo = NULL;

    struct No *head = n1;

    printf("Antes:\n");
    imprimirLista(head);

    // inserindo após o 500
    inserirApos(head, 500, 777);

    printf("Depois:\n");
    imprimirLista(head);

    // liberando memória
    struct No *atual = head;
    while (atual != NULL) {
        struct No *temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    return 0;
}