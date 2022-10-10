/**
 * @file 6.c
 * @Luiz Fernando Rolim Vieira
 * @brief 
 * @version 0.1
 * @date 2022-05-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*Considere a seguinte declaração:
   int a, *b, **c, ***d;
   Escreva um programa que receba o valor de a, calcule e exiba:

O dobro do valor a, utilizando o ponteiro b
O triplo do valor a, utilizando o ponteiro c
O quadruplo do valor a, utilizando o ponteiro d*/

#include <stdio.h>
#include <stdlib.h>

int main(){

  int a;

  printf("Digite um valor: ");
  scanf("%d",&a);

  int *b   = &a;
  int **c  = &b;
  int ***d = &c;

  printf("Valor inicial: %d\n",a);

  *b = *b * 2;
  printf("Dobro do valor inicial: %d\n",*b);

  **c = **c * 3;
  printf("Triplo do valor inicial: %d\n",**c);

  ***d = ***d * 4;
  printf("Quádruplo do valor inicial: %d\n",***d);

  return 0;
}
