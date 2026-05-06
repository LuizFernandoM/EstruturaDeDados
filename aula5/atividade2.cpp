#include <stdio.h>

void selection_sort(int arr[], int n, int *contador_trocas) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
            (*contador_trocas)++;
        }
    }
}

int main() {
    int multas[] = {500, 130, 880, 195, 290, 880};
    int n = sizeof(multas) / sizeof(multas[0]);
    int contador_trocas = 0;

    printf("Multas originais: ");
    for (int i = 0; i < n; i++)
        printf("%d ", multas[i]);
    printf("\n");

    selection_sort(multas, n, &contador_trocas);

    printf("Multas ordenadas: ");
    for (int i = 0; i < n; i++)
        printf("%d ", multas[i]);
    printf("\n");

    printf("Total de trocas realizadas: %d\n", contador_trocas);

    return 0;
}