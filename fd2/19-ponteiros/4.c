/**
 * @file 4.c
 * @Luiz Fernando Rolim Vieira
 * @brief 
 * @version 0.1
 * @date 2022-05-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*Crie um programa que contenha um vetor de inteiros de tamanho 5.
Utilizando aritmética de ponteiros, leia os dados do teclado e exiba seus valores multiplicado por 2.
Em seguida, exiba o endereço de memória das posições que contém valores pares.*/

#include <stdio.h>
#include <stdlib.h>

int main(){

  int vetor[5];

  for(int i = 0; i < 10; i++){
    vetor[i] = *(vetor + i) * 2;
    if(vetor[i] % 2 == 0){
      printf("%p endereço de memória com valor par.\n",*(vetor + i));
    }
  }

  return 0;
}