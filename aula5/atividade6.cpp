#include <stdio.h>

void merge(int arr[], int esq, int meio, int dir) {
    int n_esq = meio - esq + 1;
    int n_dir = dir - meio;

    int temp_esq[n_esq], temp_dir[n_dir];

    for (int i = 0; i < n_esq; i++)
        temp_esq[i] = arr[esq + i];
    for (int j = 0; j < n_dir; j++)
        temp_dir[j] = arr[meio + 1 + j];

    int i = 0, j = 0, k = esq;

    while (i < n_esq && j < n_dir) {
        if (temp_esq[i] <= temp_dir[j])
            arr[k++] = temp_esq[i++];
        else
            arr[k++] = temp_dir[j++];
    }

    while (i < n_esq) arr[k++] = temp_esq[i++];
    while (j < n_dir) arr[k++] = temp_dir[j++];
}

void merge_sort(int arr[], int esq, int dir) {
    if (esq < dir) {
        int meio = (esq + dir) / 2;

        printf("Dividindo... [");
        for (int i = esq; i <= dir; i++) {
            printf("%d", arr[i]);
            if (i < dir) printf(", ");
        }
        printf("] -> esq:%d meio:%d dir:%d\n", esq, meio, dir);

        merge_sort(arr, esq, meio);
        merge_sort(arr, meio + 1, dir);

        merge(arr, esq, meio, dir);

        printf("Juntando... [");
        for (int i = esq; i <= dir; i++) {
            printf("%d", arr[i]);
            if (i < dir) printf(", ");
        }
        printf("]\n");
    }
}

void imprimir(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int matriculas[] = {44, 21, 98, 12, 55, 73, 31, 8};
    int n = sizeof(matriculas) / sizeof(matriculas[0]);

    printf("Matriculas originais: ");
    imprimir(matriculas, n);
    printf("\n--- Inicio do Merge Sort ---\n\n");

    merge_sort(matriculas, 0, n - 1);

    printf("\n--- Fim do Merge Sort ---\n");
    printf("Matriculas ordenadas: ");
    imprimir(matriculas, n);

    return 0;
}