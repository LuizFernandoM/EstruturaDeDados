#include <stdio.h>

void insertion_sort(int arr[], int n, int *contador_comparacoes) {
    for (int i = 1; i < n; i++) {
        int chave = arr[i];
        int j = i - 1;

        while (j >= 0 && (++(*contador_comparacoes)) && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = chave;
    }
}

int main() {
    int pagamentos[] = {101, 102, 103, 104, 105, 99};
    int n = sizeof(pagamentos) / sizeof(pagamentos[0]);
    int contador_comparacoes = 0;

    printf("Lote original:  ");
    for (int i = 0; i < n; i++)
        printf("%d ", pagamentos[i]);
    printf("\n");

    insertion_sort(pagamentos, n, &contador_comparacoes);

    printf("Lote ordenado:  ");
    for (int i = 0; i < n; i++)
        printf("%d ", pagamentos[i]);
    printf("\n");

    printf("Total de comparacoes: %d\n", contador_comparacoes);

    return 0;
}