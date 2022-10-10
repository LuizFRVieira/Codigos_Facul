/**
 * @file 2.c
 * @Luiz Fernando Rolim Vieira
 * @brief 
 * @version 0.1
 * @date 2022-05-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/* Crie um programa que contenha um vetor float (tamanho 10). Imprima o endereço de cada posição desse vetor.*/
#include <stdio.h>
#include <stdlib.h>

int main(){

  float vetor[10];

  for(int i = 0; i < 10; i++){
    printf("%p é um endereço de memória do vetor.\n",*(vetor + i));
  }

  return 0;
}