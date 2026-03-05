#include <stdio.h>

struct Processo
{
    int numeroProtocolo;
    int status;
};

void atualizarStatus(struct Processo *p, int novoStatus){
       p->status = novoStatus;
};
int main(){
    struct Processo processo1;
    processo1.numeroProtocolo = 7799;
    processo1.status = 0;

    printf("Antes da atualização:\n");
    printf("Protocolo: %d\n", processo1.numeroProtocolo);
    printf("Status: %d\n", processo1.status);

   
    atualizarStatus(&processo1, 1);

    printf("\nDepois da atualização:\n");
    printf("Protocolo: %d\n", processo1.numeroProtocolo);
    printf("Status: %d\n", processo1.status);

    return 0;

}