#include <stdio.h>

struct Cidadao {
    int id;
    char nome[100];
    int idade;
};

void imprimirCidadao(struct Cidadao c) {
    printf("\n Dados do Cidadao \n");
    printf("ID:    %d\n", c.id);
    printf("Nome:  %s\n", c.nome);
    printf("Idade: %d anos\n", c.idade);
 
}

int main() {
    struct Cidadao cidadao;

    printf("Informe o ID: ");
    scanf("%d", &cidadao.id);

    printf("Informe o nome: ");
    scanf(" %[^\n]", cidadao.nome);

    printf("Informe a idade: ");
    scanf("%d", &cidadao.idade);

    imprimirCidadao(cidadao);

    return 0;
}