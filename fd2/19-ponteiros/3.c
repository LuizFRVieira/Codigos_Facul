/**
 * @file 3.C
 * @Luiz Fernando Rolim Vieira
 * @brief 
 * @version 0.1
 * @date 2022-05-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*Crie um programa que contenha uma matriz (3x3) de float. Imprima o endereço de cada posição dessa matriz.*/
#include <stdio.h>
#include <stdlib.h>

int main(){

  float matriz[3][3];

  for(int l = 0; l < 3; l++){
    printf("%p é um endereço de memória da matriz.\n",*(matriz + l));
    printf("\n");
    for(int c = 0; c < 3; c++){
      printf("%p é um endereço de memória da matriz.\n",*(matriz + c));
      printf("\n");
    }
  }

  return 0;
}