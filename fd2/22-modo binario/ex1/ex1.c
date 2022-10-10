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
/*Faça um programa que gere 100 números aleatórios. 
Esse programa deverá, em seguida,armazenar esses números em um arquivo binário.*/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *arq;
    char nome [20];
    int numeros[100];
    
    printf("digite o nome do arquivo:\n");
    fgets(nome,20,stdin);
    nome[strcspn(nome,"\n")]='\0';
    setbuf(stdin,NULL);

    arq = fopen(nome,"wb");

    for (size_t i = 0; i <100 ; i++){
    numeros[i]=rand() % 100;
  }

fwrite(numeros,sizeof(int),100,arq); 

  fclose(arq);
    
    return 0;
}