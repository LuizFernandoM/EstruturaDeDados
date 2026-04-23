#include <stdio.h>

int main() {
    int array[] = {89, 6, 33, 67, 13, 3, 77, 53, 43, 110};
    int tamanho = sizeof(array) / sizeof(array[0]);

    int aux;

    for (int i = 0; i < tamanho - 1; i++) {
        int menor = i;

        for (int j = i + 1; j < tamanho; j++) {
            if (array[j] < array[menor]) {
                menor = j;
            }
        }

        if (menor != i) {
            aux = array[i];
            array[i] = array[menor];
            array[menor] = aux;
        }

    }

    printf("\nArray atualizado:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}