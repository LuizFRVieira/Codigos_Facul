/**
 * @file ex1.c
 * @Luiz Fernando Rolim Vieira
 * @brief 
 * @version 0.1
 * @date 2022-05-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
//Elabore um programa que leia um arquivo binário contendo 100 números. Mostre na tela a soma desses números.

#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
FILE *arq;
int numeros[100];
int resultado=0;

arq=fopen("aa.dat","rb");

if (arq==NULL)
{
  printf("erro ao abrir o arquivo");
  exit(1);
}

  fread(numeros,sizeof(int),100,arq);

for (int i = 0; i < 100; i++) {
 resultado=resultado+numeros[i];
}

printf("a soma dos numero e %d",numeros);

    fclose(arq);
    return 0;
}