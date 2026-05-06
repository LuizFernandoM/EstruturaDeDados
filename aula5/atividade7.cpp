#include <stdio.h>

void imprimir(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int particionar(int arr[], int n) {
    int pivo  = arr[n - 1];
    int i     = -1;

    printf("Pivo escolhido: %d\n\n", pivo);
    printf("Vetor inicial:  ");
    imprimir(arr, n);
    printf("\n");

    for (int j = 0; j < n - 1; j++) {
        printf("  j=%d | arr[j]=%d ", j, arr[j]);

        if (arr[j] <= pivo) {
            i++;
            int temp = arr[i];
            arr[i]   = arr[j];
            arr[j]   = temp;
            printf("(<= %d) -> troca arr[%d] com arr[%d]", pivo, i, j);
        } else {
            printf("(> %d)  -> nenhuma troca", pivo);
        }

        printf("\n         vetor: ");
        imprimir(arr, n);
    }

    // Coloca o pivo na posicao definitiva
    int temp   = arr[i + 1];
    arr[i + 1] = arr[n - 1];
    arr[n - 1] = temp;

    printf("\nPivo %d colocado na posicao definitiva: indice %d\n", pivo, i + 1);

    return i + 1;
}

int main() {
    int subsidios[] = {300, 150, 800, 200, 900, 500};
    int n = sizeof(subsidios) / sizeof(subsidios[0]);

    printf("==============================\n");
    printf("   PARTICAO DO QUICK SORT\n");
    printf("==============================\n\n");

    int pos_pivo = particionar(subsidios, n);

    printf("\n==============================\n");
    printf("Vetor apos particao: ");
    imprimir(subsidios, n);
    printf("\n  Esquerda (< 500): ");
    for (int i = 0; i < pos_pivo; i++)
        printf("%d ", subsidios[i]);
    printf("\n  Pivo:              %d (indice %d)\n", subsidios[pos_pivo], pos_pivo);
    printf("  Direita  (> 500): ");
    for (int i = pos_pivo + 1; i < n; i++)
        printf("%d ", subsidios[i]);
    printf("\n==============================\n");

    return 0;
}