/**
 * @file 5.c
 * @Luiz Fernando Rolim Vieira
 * @brief 
 * @version 0.1
 * @date 2022-05-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*Elabora uma função que receba duas strings como parâmetros e verifique se a segunda string está dentro da primeira.
Para isso, utilize apenas aritmética de ponteiros.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void palavras(char string1[10], char string2[10]);
void limpar_buffer();

int main(){

  char string1[10];
  char string2[10];

  printf("Digite algo: ");
  fgets(string1,10,stdin);
  string1[strcspn(string1,"\n")] ='\0';
  setbuf(stdin, NULL);

  printf("Digite outra coisa: ");
  fgets(string2,10,stdin);
  string2[strcspn(string2,"\n")] ='\0';
  setbuf(stdin, NULL);

  palavras(string1, string2);

  return 0;
}

void palavras(char string1[10], char string2[10]){
  void *ponteiro1 = string1;
  void *ponteiro2 = string2;

  if(ponteiro1 == ponteiro2){
    printf("endereços iguais.\n");
  } else if(ponteiro1 > ponteiro2){
    printf("endereço %p maior que o endereço %p.\n",ponteiro1,ponteiro2);
  } else if(ponteiro2 > ponteiro1){
    printf("endereço %p maior que o endereço %p.\n",ponteiro2,ponteiro1);
  }

  return;
}