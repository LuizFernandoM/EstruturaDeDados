#include <stdio.h>
#include <stdlib.h>

struct No {
    int dado;             // Pode ser um CPF, Protocolo ou ID
    struct No *proximo;   // A corrente apontando para o próximo
};

int buscarCidadão(struct No *head, int cpf_buscado) {
    struct No *atual = head;
    while (atual != NULL) {
    if (atual->dado == cpf_buscado) {
        return 1;
    }
        atual = atual->proximo;

}
return 0;
}
int main() {
    struct No *P1 = (struct No*) malloc(sizeof(struct No));
    struct No *P2 = (struct No*) malloc(sizeof(struct No));
    struct No *P3 = (struct No*) malloc(sizeof(struct No));

    P1-> dado = 1;
    P2-> dado = 044;
    P3-> dado = 3;

    P1->proximo = P2;
    P2->proximo = P3;
    P3->proximo = NULL;

    struct No *inicio_da_lista = P1;


    int resultado = buscarCidadão(inicio_da_lista, 96);
    if (resultado == 1) {
        printf("cpf encontrado");
    }else{
        printf("cpf nao encontrado");
    }


}