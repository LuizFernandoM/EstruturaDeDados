#include <stdio.h>

int main() {
    int array[] = {89, 6, 33, 67, 13, 3, 77, 53, 43, 110};
    int tamanho = sizeof(array) / sizeof(array[0]);

    for (int i = 1; i < tamanho; i++) {
        int chave = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > chave) {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = chave;
    }

    printf("\nArray atualizado:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}