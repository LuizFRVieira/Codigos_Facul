/**
 * @file ex3.c
 * @Luiz Fernando Rolim Vieira
 * @brief 
 * @version 0.1
 * @date 2022-05-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*Escreva um programa para converter o conteúdo de um arquivo texto em caracteres maiúsculos. 
O programa deverá ler do usuário o nome do arquivo a ser convertido e o nome do arquivo a ser salvo*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int main()
{
    FILE *arq1;
    FILE *arq2;

    char e[50];
    char s[50];

    char i;

    printf("digite o nome do arquivo analisado:\n");
    fgets(e, 50, stdin);
    e[strcspn(e, "\n")] = '\0';
    setbuf(stdin, NULL);

    printf("digite o nome do arquiv que sera criado em letras maiusculas:\n");
    fgets(s, 50, stdin);
    s[strcspn(s, "\n")] = '\0';
    setbuf(stdin, NULL);

    // le o arquivo original
    arq1 = fopen(e, "r");
    // mensagem de erro
    if (arq1 == NULL)
    {
        printf("Arquivo nao encontrado");
        exit(1);
    }

    // abre o arquivo que sera alterado para escrita
    arq2 = fopen(s, "w");
    // faz a conversao do arquivo
    {
    while ((i = fgetc(arq1)) != EOF)
        fputc(toupper(i), arq2);
    }

    fclose(arq1);
    fclose(arq2);
    return 0;
}
