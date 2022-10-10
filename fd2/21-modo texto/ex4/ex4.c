/**
 * @file ex4.c
 * @Luiz Fernando Rolim Vieira
 * @brief 
 * @version 0.1
 * @date 2022-05-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*Crie um programa para calcular e exibir o número de palavras contido em um arquivo texto. O usuário deverá informar o nome do arquivo*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    FILE *arq;
    char p;
    char nome[20];
    int i = 0;

    printf("Digite o nome do arquivo:\n");
    fgets(nome,20,stdin);
    nome[strcspn(nome,"\n")]='\0';
    setbuf(stdin,NULL);

arq = fopen(nome,"r");
//mensagem de erro
    if (arq==NULL){
        printf("Arquivo nao encontrado");
        exit(1);
    }
    //conta as palavras
    do{
        if(p ==' '||p=='\n'){
            i++;
        }
    }while((p= fgetc(arq))!=EOF);
    
    printf("O arquivo %s tem %d palavras",nome,i);

    fclose(arq);
    return 0;
}