<<<<<<< HEAD
#include <stdio.h>
struct GuiaArrecadacao
{
  int numero_documento;
    float valor;
    char status; 
};

int main(){
    struct GuiaArrecadacao guias[3]; 

    for(int i = 0; i < 3; i++){
        printf("\n--- Guia %d ---\n", i + 1);

        printf("Numero do documento: ");
        scanf("%d", &guias[i].numero_documento);

        printf("Valor: ");
        scanf("%f", &guias[i].valor);

        printf("Status (P = Pago, A = Aberto): ");
        scanf(" %c", &guias[i].status); 
        }

         printf("\n===== RELATORIO DO LOTE =====\n");

    for(int i = 0; i < 3; i++){
        printf("\nGuia %d\n", i + 1);
        printf("Numero: %d\n", guias[i].numero_documento);
        printf("Valor: R$ %.2f\n", guias[i].valor);
        printf("Status: %c\n", guias[i].status);
    }

    return 0;
}
=======
#include <stdio.h>
struct GuiaArrecadacao
{
  int numero_documento;
    float valor;
    char status; 
};

int main(){
    struct GuiaArrecadacao guias[3]; 

    for(int i = 0; i < 3; i++){
        printf("\n--- Guia %d ---\n", i + 1);

        printf("Numero do documento: ");
        scanf("%d", &guias[i].numero_documento);

        printf("Valor: ");
        scanf("%f", &guias[i].valor);

        printf("Status (P = Pago, A = Aberto): ");
        scanf(" %c", &guias[i].status); 
        }

         printf("\n===== RELATORIO DO LOTE =====\n");

    for(int i = 0; i < 3; i++){
        printf("\nGuia %d\n", i + 1);
        printf("Numero: %d\n", guias[i].numero_documento);
        printf("Valor: R$ %.2f\n", guias[i].valor);
        printf("Status: %c\n", guias[i].status);
    }

    return 0;
}
>>>>>>> 9308b68bae3aa0a632b5fbe31f382b5a5b96dfa0
