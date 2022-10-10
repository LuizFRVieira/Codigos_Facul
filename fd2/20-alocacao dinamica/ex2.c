/**
 * @file 2.c
 * @author luiz fernando rolim vieira
 * @brief 
 * @version 0.1
 * @date 2022-05-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*Escreva uma função que receba um valor inteiro positivo N por parâmetro e retorne o ponteiro para um vetor de tamanho N alocado dinamicamente. 
Se N for negativo ou igual a zero, um ponteiro nulo deverá ser retornado*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//cabecalho de função
int* funcao(int);
///
int main(){
int n;
int* meuvetor;
printf("digite o qual sera o tamnho do vetor");
scanf("%d",&n);

meuvetor=funcao(n);
 for (size_t i = 0; i < n; i++)
 {
    printf("digite o vetor[%zu]:",i);
    scanf("%d",&meuvetor[i]);
 }

 for (size_t i = 0; i < n; i++)
 {
     printf("vetor[%d]: %d\n",i+1,meuvetor[i]);
 }
 
 free(meuvetor);
 
    return 0;
}

int* funcao(int n){
    int* vet;

    vet= (int*)malloc(n*sizeof(int));
return vet;
}//função