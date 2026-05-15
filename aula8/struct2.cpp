#include <stdio.h>
#include <stdlib.h>

struct No {
    int dado;             // Pode ser um CPF, Protocolo ou ID
    struct No *proximo;   // A corrente apontando para o próximo
};
int contarFila(struct No *head) {
    int contador = 0;

    struct No *atual = head;

    while (atual != NULL) {
        //printf("PROTOCOLO %d -> ", atual->dado);
        atual = atual->proximo;
        contador++;
    }

    return contador;
}


int main() {
    struct No *n1 = (struct No *)malloc(sizeof(struct No));
    struct No *n2 = (struct No *)malloc(sizeof(struct No));
    struct No *n3 = (struct No *)malloc(sizeof(struct No));
    struct No *n4 = (struct No *)malloc(sizeof(struct No));

    //inserido dados
    n1->dado = 10;
    n2->dado = 20;
    n3->dado = 30;
    n4->dado = 40;

    //montando correntes
    n1->proximo = n2;
    n2->proximo = n3;
    n3->proximo = n4;
    n4->proximo = NULL;

    struct No *inicio_da_lista = n1;
    int total = contarFila(inicio_da_lista);
    printf("EXISTEM %d ALUNOS NA FILA  \n", total);

    free(n1);
    free(n2);
    free(n3);

}

