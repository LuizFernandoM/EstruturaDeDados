#include <stdio.h>

int comparacoes  = 0;
int chamadas     = 0;

void imprimir(int arr[], int esq, int dir, int profundidade) {
    for (int p = 0; p < profundidade; p++) printf("  ");
    printf("[");
    for (int i = esq; i <= dir; i++) {
        printf("%d", arr[i]);
        if (i < dir) printf(", ");
    }
    printf("]");
}

int particionar(int arr[], int esq, int dir) {
    int pivo = arr[dir]; // sempre o ultimo elemento
    int i    = esq - 1;

    for (int j = esq; j < dir; j++) {
        comparacoes++;
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
        chamadas++;

        imprimir(arr, esq, dir, profundidade);
        printf(" pivo=%d\n", arr[dir]);

        int pos_pivo = particionar(arr, esq, dir);

        // PROBLEMA: pivo ja e o maior elemento do subvetor.
        // Ele vai para a ultima posicao, e o lado DIREITO fica vazio.
        // O lado ESQUERDO tem (n-1) elementos — sem divisao real!
        // Resultado: n chamadas em cadeia em vez de log(n) niveis.
        // Cada chamada percorre quase todo o subvetor restante.
        // Total de comparacoes: (n-1) + (n-2) + ... + 1 = n*(n-1)/2 → O(n²)

        quick_sort(arr, esq,         pos_pivo - 1, profundidade + 1); // lado esquerdo: n-1 elementos
        quick_sort(arr, pos_pivo + 1, dir,          profundidade + 1); // lado direito:  0 elementos (nunca executa)
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("=====================================\n");
    printf("  QUICK SORT - PIOR CASO (O(n^2))\n");
    printf("=====================================\n");
    printf("Vetor: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n\n--- Arvore de recursao ---\n\n");

    quick_sort(arr, 0, n - 1, 0);

    printf("\n--- Fim ---\n");
    printf("Vetor ordenado: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);

    printf("\n\n=====================================\n");
    printf("  RELATORIO\n");
    printf("=====================================\n");
    printf("Chamadas recursivas: %d\n", chamadas);
    printf("Comparacoes:         %d\n", comparacoes);
    printf("Esperado O(n log n): ~%d comparacoes\n", (int)(n * 3.32));
    printf("Esperado O(n^2):     ~%d comparacoes\n", n * (n - 1) / 2);
    printf("=====================================\n");


    return 0;
}