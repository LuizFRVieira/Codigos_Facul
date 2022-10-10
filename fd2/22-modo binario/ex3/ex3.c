/**
 * @file exe3.c
 * @Luiz Fernando Rolim Vieira
 * @brief 
 * @version 0.1
 * @date 2022-05-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*Crie uma estrutura representando um atleta. Essa estrutura deve conter o nome do atleta, seu esporte, idade e altura. 
Agora, escreva um programa que leia os dados de c inco atletas e os armazene em um arquivo binário*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//atleta
typedef struct{
char nome [21];
char esporte[21];
int idade;
float altura;
}atleta;

int main(){

atleta dados[5];
FILE *arq;
char arquivo[21];

printf("digite o nome do arquivo");
fgets(arquivo,20,stdin);
arquivo[strcspn(arquivo,"\n")]='\0';
setbuf(stdin,NULL);

arq = fopen(arquivo,"wb");

for (int i = 0; i < 5; i++){
printf("digite o nome do atleta :\n");
fgets(dados[i].nome,20,stdin);
dados[i].nome[strcspn(dados[i].nome,"\n")]='\0';
setbuf (stdin,NULL);

printf("digite o esporte que ele pratica:\n");
fgets(dados[i].esporte,20,stdin);
dados[i].esporte[strcspn(dados[i].esporte,"\n")]='\0';
setbuf (stdin,NULL);

printf("digite a idade do atleta:\n");
scanf("%i",&dados[i].idade);
setbuf (stdin,NULL);

printf("digite a altura do atleta:\n");
scanf("%f",&dados[i].altura);
setbuf (stdin,NULL);
}//salva os dados do atleta

//abrir arquivo


fwrite(&dados,sizeof(atleta),5,arq);

fclose(arq);
return 0;
}