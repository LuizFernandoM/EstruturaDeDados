#include <stdio.h>

int main() {
    int cpfs_inativos[] = {11, 22, 33, 44, 55, 66, 77, 88, 99, 110};
    int tamanho = 10;
    int alvo = 99;



    printf("--------------busca linear------------\n");

    int passos_linear = 0;
    int encontro_linear = 0;

    for (int i = 0; i < tamanho; i++) {
        passos_linear++;

        if (cpfs_inativos[i]== alvo) {
            encontro_linear++;
            break;
        }
    }
    if (encontro_linear == 1){
        printf("Sucesso, o cpf %d foi encontrado em %d passos.\n\n", alvo, passos_linear);
    }

    printf("--------------busca binaria------------\n");

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
        }

        else if (cpfs_inativos[meio] > alvo) {
            //se alvo menor joga metade da direita fora
            fim = meio - 1;
        }

        else {
            //se alvo maior joga metade da esquerda fora
            inicio = meio + 1;
        }

    }
    if (encontro_binaria == 1){
    printf("o alvo %d foi encontrado com %d passos", alvo, passos_binaria);
}
    
    return 0;
}