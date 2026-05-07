#include <stdio.h>


void imprimir(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int particionar(int arr[], int esq, int dir) {
    int pivo = arr[dir];
    int i    = esq - 1;

    for (int j = esq; j < dir; j++) {
        if (arr[j] <= pivo) {
            i++;
            int temp = arr[i];
            arr[i]   = arr[j];
            arr[j]   = temp;
        }
    }

    int temp   = arr[i + 1];
    arr[i + 1] = arr[dir];
    arr[dir]   = temp;

    return i + 1;
}

void quick_sort(int arr[], int esq, int dir, int profundidade) {
    if (esq < dir) {
        // Indentacao visual para mostrar a profundidade da recursao
        for (int p = 0; p < profundidade; p++) printf("  ");
        printf("-> Chamada: [");
        for (int i = esq; i <= dir; i++) {
            printf("%d", arr[i]);
            if (i < dir) printf(", ");
        }
        printf("] pivo=%d\n", arr[dir]);

        int pos_pivo = particionar(arr, esq, dir);

        for (int p = 0; p < profundidade; p++) printf("  ");
        printf("   Pivo %d fixado no indice %d\n", arr[pos_pivo], pos_pivo);

        quick_sort(arr, esq, pos_pivo - 1, profundidade + 1);
        quick_sort(arr, pos_pivo + 1, dir, profundidade + 1);
    }
}

int main() {
    int cpfs[] = {4321, 1111, 9999, 3333, 7777, 2222, 5555};
    int n = sizeof(cpfs) / sizeof(cpfs[0]);

    printf("==============================\n");
    printf("   QUICK SORT - CPFs\n");
    printf("==============================\n");
    printf("CPFs originais: ");
    imprimir(cpfs, n);
    printf("\n--- Recursao ---\n\n");

    quick_sort(cpfs, 0, n - 1, 0);

    printf("\n--- Fim ---\n");
    printf("CPFs ordenados: ");
    imprimir(cpfs, n);
    printf("==============================\n");

    return 0;
}