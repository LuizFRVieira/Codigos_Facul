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

/*Considerando a estrutura atleta do exercício anterior, escreva um programa que leia um arquivo binário contendo os dados de cinco atletas. 
Calcule e exiba o nome do atleta mais alto e do mais velho.*/

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
int a,b;


arq = fopen("aa.dat","rb");

if(arq==NULL){
    printf("arquivo nao encontrado");
    exit(1);
}

//altura
fread(dados,sizeof(atleta),5,arq);
for (size_t i = 0; i < 5; i++){
    if (dados[i].altura > dados[i-1].altura){
        a=i;
    }
    


//idade
if (dados[i].idade > dados[i-1].idade){
    b=i;
}//if
}//for

printf("O atleta mais alto e o %s\n",dados[a].nome);
printf("O alteta mais velho e o %s com  %ianos\n",dados[a].nome,dados[b].idade);


fclose(arq);

return 0;
}