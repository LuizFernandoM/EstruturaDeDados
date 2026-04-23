#include <stdio.h>

int main() {
    int array[] = {89, 6, 33, 67, 13, 3, 77, 53, 43, 110};

    int tamanho = sizeof(array) / sizeof(array[0]);

    int aux = 0;

    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - 1 - i; j++) {

            if (array[j] > array[j + 1]) {
                aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
            }

        }
    }

    printf("\nArray atualizado:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}