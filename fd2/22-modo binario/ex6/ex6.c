/**
 * @file ex6.c
 * @Luiz Fernando Rolim Vieira
 * @brief 
 * @version 0.1
 * @date 2022-05-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*Considerando a estrutura ranking do exercício anterior, escreva um programa que leia o arquivo gerado contendo os dados dos 5 jogadores*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    char nome[21];
    int pontos;
}jogador;

int main(){
    FILE *arq;
    jogador dados[5];

    arq = fopen("aa.dat","rb");

    if (arq==NULL){
        printf("programa nao encontrado");
        exit(1);
    }

for (size_t i = 0; i < 5; i++){
    fscanf(arq,"%s",dados[i].nome);
    fscanf(arq, "%s", dados[i].pontos);
}

for (size_t p = 0; p < 5; p++){
    printf("Jogador %d: %s",p+1,dados[p].nome);
    printf("Pontos do jogador %d: %d",p+1,dados[p].pontos);
    printf("\n");
}

fclose(arq);
    
    return 0;
}