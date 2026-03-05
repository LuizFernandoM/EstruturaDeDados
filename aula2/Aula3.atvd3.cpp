#include <stdio.h>
#include <stdlib.h>

int main() {

    int *protocolo_urgente;

    protocolo_urgente = (int*) malloc(sizeof(int));

    *protocolo_urgente = 999;

    printf("Valor do protocolo urgente: %d\n", *protocolo_urgente);

    free(protocolo_urgente);

    return 0;
}