#include <stdio.h>

#include <stdio.h>

int main() {

    int senhas_atendimento[5];
    int i;

   
    for(i = 0; i < 5; i++){
        senhas_atendimento[i] = 101 + i;
    }

 
    printf("Senhas:\n");
    for(i = 0; i < 5; i++){
        printf("%d\n", senhas_atendimento[i]);
    }

   
    printf("\nEndereco da primeira posicao: %p\n", (void*)&senhas_atendimento[0]);
    printf("Endereco da segunda posicao: %p\n", (void*)&senhas_atendimento[1]);

   

    return 0;
}