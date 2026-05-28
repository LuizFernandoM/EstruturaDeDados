#include <stdio.h>
#include <stdlib.h>


typedef struct NoDuplo {
    struct NoDuplo *anterior;  // O Retrovisor
    int cpf;                   // A Carga Útil (Payload)
    struct NoDuplo *proximo;   // O Para-brisa
} NoDuplo;

void buscarComVizinhos(struct NoDuplo *head, int cpf_alvo) {
    if (head == NULL) {
        printf ("fila vazia\n");
        return;
    }

    struct NoDuplo *atual = head;


    while (atual != NULL) {
  if (atual->cpf == cpf_alvo) {
      if (atual->anterior != NULL){
            printf("Dado anterior:  %d ", atual->anterior->cpf);
            printf("<==> ");
      }else{

        printf("NULL");
        printf("<==> ");
    }

            printf("Dado %d: ", atual->cpf);

    if (atual->proximo != NULL){
            printf("<==> ");
            printf("Dado proximo: %d ", atual->proximo->cpf);
    }else{
        printf("<==> ");
        printf("NULL");
    }
        }

        atual = atual->proximo;


    }

}

void imprimirCpf(struct NoDuplo *head, int cpf){

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
    int alvo;
    NoDuplo *fila_cras = NULL;
    inserirInicio(&fila_cras,1);
    inserirInicio(&fila_cras,2);
    inserirInicio(&fila_cras,3);
    inserirInicio(&fila_cras,4);
    inserirInicio(&fila_cras,5);
    inserirInicio(&fila_cras,6);

    printf("escolha qual cpf voce deseja buscar \n");
    scanf("%d", &alvo);

    buscarComVizinhos(fila_cras, alvo);







}

