#include <stdio.h>

int main() {
    int cpfs_inativos[20] = {11, 22, 33, 44, 55, 66, 77, 88, 99, 110};
    int tamanho = 10;
    int novo;
//aqui é inserido o novo valor
    printf("Digite o novo CPF a ser inserido: ");
    scanf("%d", &novo);

    // 1. Descobrir a posição correta
    int pos = 0;
    while (pos < tamanho && cpfs_inativos[pos] < novo) {
        pos++;
    }

    // 2. Empurrar os elementos pra direita
    for (int i = tamanho; i > pos; i--) {
        cpfs_inativos[i] = cpfs_inativos[i - 1];
    }

    // 3. Inserir o novo valor
    cpfs_inativos[pos] = novo;
    tamanho++;

    // Mostrar o array atualizado
    printf("\nArray atualizado:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", cpfs_inativos[i]);
    }

    // 🔎 Busca binária
    printf("\n\n--------------busca binaria------------\n");

    int alvo = novo;
    int inicio = 0, fim = tamanho - 1;
    int passos = 0, encontrou = 0;

    while (inicio <= fim) {
        passos++;
        int meio = (inicio + fim) / 2;

        if (cpfs_inativos[meio] == alvo) {
            encontrou = 1;
            break;
        } else if (cpfs_inativos[meio] > alvo) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }

    if (encontrou) {
        printf("CPF %d encontrado em %d passos\n", alvo, passos);
    } else {
        printf("CPF nao encontrado\n");
    }

    return 0;
}