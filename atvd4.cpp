#include <stdio.h>

int main() {
    
    
    int id_servidor;
    float salario;
    char turno;


    id_servidor = 101;
    salario = 3500.50;
    turno = 'M';

    
    printf("Valores das variaveis:\n");
    printf("ID do servidor: %d\n", id_servidor);
    printf("Salario: %.2f\n", salario);
    printf("Turno: %c\n\n", turno);

    
    printf("Enderecos de memoria:\n");
    printf("Endereco de id_servidor: %p\n", (void*)&id_servidor);
    printf("Endereco de salario: %p\n", (void*)&salario);
    printf("Endereco de turno: %p\n", (void*)&turno);

    return 0;
}