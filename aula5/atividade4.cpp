#include <stdio.h>

void bubble_sort(int arr[], int n, int *comparacoes, int *trocas) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            (*comparacoes)++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j]     = arr[j + 1];
                arr[j + 1] = temp;
                (*trocas)++;
            }
        }
    }
}

void selection_sort(int arr[], int n, int *comparacoes, int *trocas) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            (*comparacoes)++;
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i) {
            int temp    = arr[i];
            arr[i]      = arr[min_idx];
            arr[min_idx] = temp;
            (*trocas)++;
        }
    }
}

void copiar(int origem[], int destino[], int n) {
    for (int i = 0; i < n; i++)
        destino[i] = origem[i];
}

void imprimir(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int original[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(original) / sizeof(original[0]);
    int vetor[9];

    int b_comp = 0, b_trocas = 0;
    int s_comp = 0, s_trocas = 0;

    printf("Vetor original: ");
    imprimir(original, n);
    printf("\n");

    // --- Bubble Sort ---
    copiar(original, vetor, n);
    bubble_sort(vetor, n, &b_comp, &b_trocas);
    printf("=== Bubble Sort ===\n");
    printf("Vetor ordenado: ");
    imprimir(vetor, n);
    printf("Comparacoes: %d\n", b_comp);
    printf("Trocas:      %d\n", b_trocas);

    printf("\n");

    // --- Selection Sort ---
    copiar(original, vetor, n);
    selection_sort(vetor, n, &s_comp, &s_trocas);
    printf("=== Selection Sort ===\n");
    printf("Vetor ordenado: ");
    imprimir(vetor, n);
    printf("Comparacoes: %d\n", s_comp);
    printf("Trocas:      %d\n", s_trocas);

    printf("\n");

    // --- Comparativo ---
    printf("========================================\n");
    printf("%-20s %10s %10s\n", "Algoritmo", "Comparacoes", "Trocas");
    printf("----------------------------------------\n");
    printf("%-20s %10d %10d\n", "Bubble Sort",    b_comp, b_trocas);
    printf("%-20s %10d %10d\n", "Selection Sort", s_comp, s_trocas);
    printf("========================================\n");

    printf("\nConclusao:\n");
    printf("- Comparacoes: ambos fazem %d (O(n^2) no pior caso)\n", b_comp);
    if (b_trocas > s_trocas)
        printf("- Trocas: Bubble fez %d trocas, Selection fez apenas %d\n",
               b_trocas, s_trocas);

    return 0;
}