#include <stdio.h>
#include <stdlib.h>

int main() {

    int qtd;
    int *matriculas;

  
    printf("Quantidade de alunos: ");
    scanf("%d", &qtd);

    
    matriculas = (int*) malloc(qtd * sizeof(int));

    
    if (matriculas == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    
    for (int i = 0; i < qtd; i++) {
        matriculas[i] = 1000 + i;
    }

    
    printf("\nMatriculas dos alunos:\n");
    for (int i = 0; i < qtd; i++) {
        printf("%d\n", matriculas[i]);
    }

    
    free(matriculas);

    return 0;
}