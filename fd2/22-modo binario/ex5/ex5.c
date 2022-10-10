/**
 * @file ex5.c
 * @Luiz Fernando Rolim Vieira
 * @brief 
 * @version 0.1
 * @date 2022-05-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*Crie uma estrutura representando um ranking. Essa estrutura deve conter o nome do jogador e sua pontuação. 
Em seguida, escreva um programa que leia os dados de 5 jogadores e os armazene em um arquivo utilizando a técnica de Dados formatados.
*/

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
    char arquivo[21];

//arquivo
printf("digite o nome do arquivo: \n");
fgets(arquivo,20,stdin);
arquivo[strcspn(arquivo,"\n")]='\0';
setbuf(stdin,NULL);

arq = fopen(arquivo,"wb");

for (size_t i = 0; i < 5; i++){
    printf("Digite o Nome do jogador:\n");
    fgets(dados[i].nome,21,stdin);
    dados[i].nome[strcspn(dados[i].nome,"\n")]='\0';
    setbuf(stdin,NULL);

    printf("Digite a pontuacao do jogador");
    scanf("%d",dados[i].pontos);
    setbuf(stdin,NULL);

    printf("\n");

}//dados

for (size_t p = 0; p < 5; p++){
    fprintf(arq, "%s", dados[p].nome);
    fprintf(arq, "%d", dados[p].pontos);

}



fclose(arq);
    return 0;
}