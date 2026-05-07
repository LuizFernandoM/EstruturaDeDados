#include <stdio.h>

// =========================================
//           INSERTION SORT
// =========================================
void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int chave = arr[i];
        int j     = i - 1;
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = chave;
    }
}

// =========================================
//           QUICK SORT
// =========================================
int particionar(int arr[], int esq, int dir) {
    // Mediana de tres para evitar o pior caso
    int meio = (esq + dir) / 2;
    if (arr[esq] > arr[meio]) { int t = arr[esq]; arr[esq] = arr[meio]; arr[meio] = t; }
    if (arr[esq] > arr[dir])  { int t = arr[esq]; arr[esq] = arr[dir];  arr[dir]  = t; }
    if (arr[meio] > arr[dir]) { int t = arr[meio]; arr[meio] = arr[dir]; arr[dir]  = t; }

    int pivo = arr[dir];
    int i    = esq - 1;

    for (int j = esq; j < dir; j++) {
        if (arr[j] <= pivo) {
            i++;
            int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
        }
    }
    int temp     = arr[i + 1];
    arr[i + 1]   = arr[dir];
    arr[dir]     = temp;
    return i + 1;
}

void quick_sort(int arr[], int esq, int dir) {
    if (esq < dir) {
        int p = particionar(arr, esq, dir);
        quick_sort(arr, esq,     p - 1);
        quick_sort(arr, p + 1,   dir);
    }
}

// =========================================
//           SUPER SORT
// =========================================
void super_sort(int arr[], int tamanho) {
    printf("  [super_sort] tamanho=%d -> ", tamanho);

    if (tamanho < 10) {
        printf("Insertion Sort (array pequeno, zero overhead de recursao)\n");
        insertion_sort(arr, tamanho);
    } else {
        printf("Quick Sort (array grande, O(n log n) com mediana de tres)\n");
        quick_sort(arr, 0, tamanho - 1);
    }
}

// =========================================
//           UTILITARIOS
// =========================================
void imprimir(int arr[], int n) {
    printf("  [");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

void copiar(int origem[], int destino[], int n) {
    for (int i = 0; i < n; i++) destino[i] = origem[i];
}

// =========================================
//           MAIN
// =========================================
int main() {
    // --- Vetor pequeno: 8 posicoes ---
    int pequeno[]  = {34, 7, 89, 12, 45, 67, 23, 56};
    int n_pequeno  = 8;
    int tmp[20];

    printf("================================================\n");
    printf("  TESTE 1 — Vetor de %d posicoes\n", n_pequeno);
    printf("================================================\n");
    copiar(pequeno, tmp, n_pequeno);
    printf("  Antes:  ");  imprimir(tmp, n_pequeno);
    super_sort(tmp, n_pequeno);
    printf("  Depois: ");  imprimir(tmp, n_pequeno);

    printf("\n");

    // --- Vetor grande: 15 posicoes ---
    int grande[]  = {98, 23, 67, 4, 55, 81, 36, 14, 72, 49, 60, 9, 88, 31, 47};
    int n_grande  = 15;

    printf("================================================\n");
    printf("  TESTE 2 — Vetor de %d posicoes\n", n_grande);
    printf("================================================\n");
    copiar(grande, tmp, n_grande);
    printf("  Antes:  ");  imprimir(tmp, n_grande);
    super_sort(tmp, n_grande);
    printf("  Depois: ");  imprimir(tmp, n_grande);

    printf("\n");

    // --- Bonus: na fronteira exata (9 vs 10) ---
    int fronteira_ins[] = {5, 3, 8, 1, 9, 2, 7, 4, 6};          // 9 elementos
    int fronteira_qck[] = {5, 3, 8, 1, 9, 2, 7, 4, 6, 10};      // 10 elementos
    int n_ins = 9, n_qck = 10;

    printf("================================================\n");
    printf("  BONUS — Fronteira do limiar (9 vs 10)\n");
    printf("================================================\n");
    copiar(fronteira_ins, tmp, n_ins);
    printf("  Vetor de %d: ", n_ins); imprimir(tmp, n_ins);
    super_sort(tmp, n_ins);
    printf("  Resultado:  "); imprimir(tmp, n_ins);

    printf("\n");

    copiar(fronteira_qck, tmp, n_qck);
    printf("  Vetor de %d: ", n_qck); imprimir(tmp, n_qck);
    super_sort(tmp, n_qck);
    printf("  Resultado:  "); imprimir(tmp, n_qck);

    printf("================================================\n");

    return 0;
}