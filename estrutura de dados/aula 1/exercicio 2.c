#include <stdio.h>
#include <stdlib.h>

int main (){
    int tamvet, *vet,resultado;
    printf("digite o tamanho do vetor \n");
    scanf("%d",&tamvet);

    vet = (int *) malloc(tamvet * sizeof(int));
    system ("clear");
    for (size_t i = 0; i < tamvet; i++){
        printf("informe o valor do vetor %d\n",i);
        scanf("%d",&vet[i]);
        system("clear");
    }

    for (size_t i = 0; i < tamvet; i++){
        resultado += vet[i];
    }

    system("clear");
    printf("O resultado da soma de todos os vetores é %d\n",resultado);
    
    

    free (vet);
    return 0;
}