/*precisa guardar dados de um servidor publico  */

#include<stdio.h>
#include<string.h>
struct Lotacao
{
    char secretaria[50];
    char setor[50];
    int ramal;
};


/*1. Definindo a estrutura de servidor publico*/
struct ServidorPublico
{
    int matricula;
    char nome[50];
    float salario;
    struct Lotacao local_trabalho; //composição
};

int main(){
    //2. inicializando um servidor publico
    struct ServidorPublico servidor1;

    //3. atribuindo valores ao servidor publico
    servidor1.matricula = 12345;
    strcpy(servidor1.nome, "luiz");
    servidor1.salario = 5000.0;

    //3.1 atribuidos valores a lotaçao do servidor publico 
    strcpy(servidor1.local_trabalho.secretaria, "secretaria de educacao");
    strcpy(servidor1.local_trabalho.setor, "setor de recursos humanos");
    servidor1.local_trabalho.ramal = 1234;



    //4. exibindo os dados do servidor publico 
printf("matricula: %d\n", servidor1.matricula);
printf("nome: %s\n", servidor1.nome);
printf("salario: %.2f\n", servidor1.salario);
printf("nome: %s - %s (ramal:%d)\n", servidor1.local_trabalho.secretaria,servidor1.local_trabalho.setor, servidor1.local_trabalho.ramal
);

}

