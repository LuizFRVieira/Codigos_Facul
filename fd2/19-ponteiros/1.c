/**
 * @file ponteiros.c
 * @Luiz Fernando Rolim Vieira
 * @brief 
 * @version 0.1
 * @date 2022-05-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*Escreva um programa que contenha duas variáveis inteiras. 
Compare os endereços e exiba o endereço e o conteúdo do maior endereço.
*/
#include <stdio.h>
#include <stdlib.h>


int main(){

  int var1;
  int var2;

  int *ptr1 = &var1;
  int *ptr2 = &var2;

  if(ptr1 == ptr2){
    printf("endereços iguais.\n");
  } else if(ptr1 > ptr2){
    printf("endereço %p maior que o endereço %p.\n",ptr1,ptr2);
  } else if(ptr2 > ptr1){
    printf("endereço %p maior que o endereço %p.\n",ptr2,ptr1);
  }

  return 0;
}