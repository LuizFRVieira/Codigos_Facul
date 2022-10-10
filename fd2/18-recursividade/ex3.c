/**
 * @file ex3.c
 * @Luiz Fernando Rolim Vieira
 * @brief 
 * @version 0.1
 * @date 2022-05-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*Crie uma função que retorne o fatorial de um número passado por parâmetro.

fatorial(n):

=1 se n=0

= n x fatorial (n-1) se n>0*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int potencia(int x, int y);

int main(){
  setlocale(LC_ALL,"");

  int x;//base
  int y;//potência

  printf("Digite dois números que são base e potência: ");
  scanf("%d""%d",&x,&y);

  int resultado = potencia(x,y);

  printf("Resultado da potência: %d\n", resultado);

  return 0;
}

int potencia(int x, int y){
  if(y == 0){//caso base
    return 1;
  } else {//caso recursivo
    return x*(potencia(x, y-1));
  }
}