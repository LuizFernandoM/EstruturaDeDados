#include <stdio.h>

void merge(int esq[], int n_esq, int dir[], int n_dir, int resultado[]) {
    int i = 0, j = 0, k = 0;

    while (i < n_esq && j < n_dir) {
        if (esq[i] <= dir[j])
            resultado[k++] = esq[i++];
        else
            resultado[k++] = dir[j++];
    }

    while (i < n_esq)
        resultado[k++] = esq[i++];

    while (j < n_dir)
        resultado[k++] = dir[j++];
}

void imprimir(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int norte[] = {20, 40, 60};
    int sul[]   = {10, 30, 50, 70};
    int n_norte = 3, n_sul = 4;
    int resultado[7];

    printf("Escola Norte: ");
    imprimir(norte, n_norte);

    printf("Escola Sul:   ");
    imprimir(sul, n_sul);

    merge(norte, n_norte, sul, n_sul, resultado);

    printf("\nVetor mesclado: ");
    imprimir(resultado, n_norte + n_sul);

    return 0;
}