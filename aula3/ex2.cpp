#include <stdio.h>

int main() {
    int cpfs_inativos[11] = {11, 22, 33, 44, 55, 66, 77, 88, 99, 110};
    int tamanho = 10;
    int novo = 25;

    // Inserção ordenada
    for (int i = tamanho; i > 2; i--) {
        cpfs_inativos[i] = cpfs_inativos[i - 1];
    }

    cpfs_inativos[2] = novo;
    tamanho++;

    // Mostrando o array atualizado
    printf("Array atualizado:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", cpfs_inativos[i]);
    }

    printf("\n\n--------------busca binaria------------\n");

    int alvo = 25;
    int passos_binaria = 0;
    int encontro_binaria = 0;
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim) {
        passos_binaria++;
        int meio = (inicio + fim) / 2;

        if (cpfs_inativos[meio] == alvo) {
            encontro_binaria++;
            break;
        } else if (cpfs_inativos[meio] > alvo) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }

    if (encontro_binaria == 1) {
        printf("O CPF %d foi encontrado com %d passos\n", alvo, passos_binaria);
    } else {
        printf("CPF nao encontrado\n");
    }

    return 0;
}