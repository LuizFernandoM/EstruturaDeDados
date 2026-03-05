#include<stdio.h> 

int main(){
/*tipos primitivos*/
int inteiro = 10;
float decimal = 3.14;
char caractere = 'A';
bool booleano = true;

/*tipos derivados ou compostos*/
int vetor[5] = {1, 2, 3, 4, 5};

//matriz 3x3
int matriz[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};
struct Pessoa
{
    char nome[50];
    int idade;
};
/*tipos de ponteiro*/
int*  ponteiroInteiro = &inteiro; //ponteiro para inteiro

/*TADs - Tipos Abstratos de Dados*/

    return 0;
}