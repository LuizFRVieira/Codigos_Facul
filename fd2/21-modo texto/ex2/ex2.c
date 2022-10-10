/**
 * @file ex2.c
 * @Luiz Fernando Rolim Vieira
 * @brief 
 * @version 0.1
 * @date 2022-05-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*Escreva um programa que leia do usuário os nomes de dois arquivos texto. 
Crie um terceiro arquivo texto com o conteúdo dos dois primeiros juntos (o conteúdo do primeiro seguido do conteúdo do segundo)*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    FILE *arq1;
    FILE *arq2;
    FILE *arq3;
    char nome1[20];
    char nome2[20];

    char t1[50];
    char t2[50];

   
    printf("digite o nome do primeiro arquivo:\n");
    fgets(nome1,20,stdin);
    nome1[strcspn(nome1,"\n")] = '\0';
    setbuf(stdin,NULL);

     printf("digite o nome do segundo arquivo:\n");
    fgets(nome2,20,stdin);
    nome2[strcspn(nome2,"\n")] = '\0';
    setbuf(stdin,NULL);

//abre os arquivos
    arq1= fopen(nome1,"r");
    arq2= fopen(nome2,"r");
    arq3= fopen("arq3.txt","w");
///em caso de erro
if (arq1==NULL){
    printf("Não foi possivel encontar o arquivo");
    exit(1);
}
if (arq2==NULL){
    printf("Não foi possivel encontar o arquivo");
    exit(1);
}
if (arq3==NULL){
    printf("Não foi possivel criar o arquivo");
    exit(1);
}
//junta as 2 strings
fgets(t1,50,arq1);
fgets(t2,50,arq2);
strcat(t1,t2);

fputs(t1,arq3);

fclose(arq1);
fclose(arq2);
fclose(arq3);

printf("O arquivo foi gerado");

    return 0;
}