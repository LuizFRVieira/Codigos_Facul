/**
 * @file 1.c
 * @author luiz fernando rolim vieira
 * @version 0.1
 * @date 2022-05-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*Elabore um programa que leia do usuário o tamanho de um vetor a ser lido. 
Em seguida, faça a alocação dinâmica desse vetor. Por fim, leia o vetor do usuário e o imprima.*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    int tam;
    int *vet;

    printf("Digite o tamanho do vetor\n");
    scanf("%d",&tam);

    vet = (int*) malloc(tam*sizeof(int));

    for (size_t i = 0; i < tam; i++)
    {
        printf("digite o numero do vetor %d:",i+1);
        scanf("%d",&vet[i]);

    }
    
    for (size_t i = 0; i < tam; i++)
    {
        printf("o valor salvo no vetor %d e de %d\n",i+1,vet[i]);
    }
    
    free(vet);


    return 0;
}