#include <cstdlib>
#include <stdio.h>

struct No {
    int dado;             // Pode ser um CPF, Protocolo ou ID
    struct No *proximo;   // A corrente apontando para o próximo
};

void imprimirObras(struct No *head) {
    //usar outra variavel pra percorrer
    struct No *atual = head;
    printf("=== Protocolos de Obras ===\n");
    while (atual != NULL) {
        printf("PROTOCOLO %d -> ", atual->dado);

        //indo para o proximo
        atual = atual->proximo;
    }

}


int main() {
    //simulando criaçao de 3 obras pra testar
    struct No *Obra1 = (struct No*) malloc(sizeof(struct No));
    struct No *Obra2 = (struct No*) malloc(sizeof(struct No));
    struct No *Obra3 = (struct No*) malloc(sizeof(struct No));

    //inserido dados
    Obra1->dado = 1045;
    Obra2->dado = 2038;
    Obra3->dado = 3012;

    //inserindo correntes(proximos)
    Obra1->proximo = Obra2;
    Obra2->proximo = Obra3;
    Obra3->proximo = NULL;

    //INICIO DA LISTA
    struct No *inicio_da_lista = Obra1;

    //iniciando impressão
    imprimirObras(inicio_da_lista);

    //recomendação BOA PRATICA
    free(Obra1);
    free(Obra2);
    free(Obra3);

    return 0;


}