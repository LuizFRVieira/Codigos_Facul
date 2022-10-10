/**
 * @file ex1.c
 * @Luiz Fernando Rolim Vieira
 * @brief 
 * @version 0.1
 * @date 2022-05-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*Crie uma função que retorne x*y através de operação de soma. A função recebe x e y por parâmetro
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int fatorial(int num);

int main(){
  setlocale(LC_ALL,"");

  int num;

  printf("Digite um número: ");
  scanf("%d",&num);

  int fat = fatorial(num);

  printf("A fatorial de %d é %d.\n",num,fat);

  return 0;
}//main

int fatorial(int num){
  if(num == 0){//caso recursivo
    return 1;
  } else if(num > 0){//caso base
    return num*fatorial(num - 1);
  }
}//fatorial