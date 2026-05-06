#include <stdio.h>

void imprimirvetor(int senhas[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", senhas[i]);
    }
}

void bublesort(int senhas[], int tamanho) {


printf("\nestado inicial:\n");
imprimirvetor(senhas, tamanho);

    for (int i = 0; i < tamanho - 1; i++) {

        for (int j = 0; j < tamanho - 1 - i; j++) {

            if (senhas[j] > senhas[j + 1]) {
                int aux = senhas[j];
                senhas[j] = senhas[j + 1];
                senhas[j + 1] = aux;
            }

        }
        printf("\n senhas:");
        imprimirvetor(senhas, tamanho);
    }
}



int main() {
    int senhas_atendimentos[] = {82, 45, 12, 78, 23};
    int tamanho = 5;

    bublesort(senhas_atendimentos, tamanho);


}