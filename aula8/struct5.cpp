#include <stdio.h>
#include <stdlib.h>

struct No {
    int dado;
    struct No *proximo;
};

void removerCpf(struct No **head, int cpf_alvo) {
    struct No *atual = *head;
    struct No *anterior = NULL;

    // caso 1: lista vazia
    if (atual == NULL) return;

    // caso 2: remover o primeiro nó
    if (atual->dado == cpf_alvo) {
        *head = atual->proximo;
        free(atual);
        return;
    }

    // caso 3: remover do meio ou fim
    while (atual != NULL && atual->dado != cpf_alvo) {
        anterior = atual;
        atual = atual->proximo;
    }

    // não encontrou
    if (atual == NULL) return;

    // remove nó encontrado
    anterior->proximo = atual->proximo;
    free(atual);
}

// função auxiliar para imprimir
void imprimirLista(struct No *head) {
    struct No *atual = head;
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

int main() {
    struct No *n1 = (struct No*) malloc(sizeof(struct No));
    struct No *n2 = (struct No*) malloc(sizeof(struct No));
    struct No *n3 = (struct No*) malloc(sizeof(struct No));
    struct No *n4 = (struct No*) malloc(sizeof(struct No));

    n1->dado = 111;
    n2->dado = 222;
    n3->dado = 333;
    n4->dado = 444;

    n1->proximo = n2;
    n2->proximo = n3;
    n3->proximo = n4;
    n4->proximo = NULL;

    struct No *head = n1;

    printf("Antes:\n");
    imprimirLista(head);

    removerCpf(&head, 111); // testa removendo início
    removerCpf(&head, 333); // testa removendo meio
    removerCpf(&head, 444); // testa removendo fim

    printf("Depois:\n");
    imprimirLista(head);

    // liberar memória restante
    struct No *atual = head;
    while (atual != NULL) {
        struct No *temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    return 0;
}