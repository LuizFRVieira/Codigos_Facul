/**
 * @file ex1.c
 * @Luiz Fernando Rolim Vieira
 * @brief 
 * @version 0.1
 * @date 2022-05-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*Escreva um programa que leia do usuário o nome de um arquivo texto. Em seguida, mostre na tela quantas linhas esse arquivo possui.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    FILE *arq;
    char nome[20];
    char aux;
    int i = 1 ;

    printf("digite o nome do arquivo:\n");
    fgets(nome,20,stdin);
    nome[strcspn(nome,"\n")] = '\0';
    setbuf(stdin,NULL);


//abre arquivo
arq = fopen(nome,"r");
//caso de erro
if (arq=NULL)
{
    printf("arquivo inexistente");
    exit(1);
}

//confere o numero de linhas
while((aux = fegetc(arq))!=EOF){
    if((aux = fegetc(arq))=='\n'){
        i++;
    }
}
fclose(arq);
printf("o arquivo possui %d linhas",i);
    return 0;
}