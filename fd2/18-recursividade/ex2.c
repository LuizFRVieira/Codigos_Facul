/**
 * @file ex2.c
 * @Luiz Fernando Rolim Vieira
 * @brief 
 * @version 0.1
 * @date 2022-05-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */
/*Crie uma função que retorne x elevado a y através de operação de multiplicação. A função recebe x e y por parâmetro*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int multip(int x, int y);

int main(){
  setlocale(LC_ALL,"");

  int x;
  int y;

  printf("Digite dois números: ");
  scanf("%d""%d",&x,&y);

  int resultado =  multip(x,y);

  printf("Resultado da multiplicação: %d\n",resultado);

  return 0;
}//main

int multip(int x, int y){
  if(x == 0 || y == 0){
    return 0;
  } else{
    return x+multip(x,y-1);
  }
}//multip