/**
 * @file ex5.c
 * @Luiz Fernando Rolim Vieira
 * @brief 
 * @version 0.1
 * @date 2022-05-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*Elabore um programa para calcular e exibir o número de vezes que cada letra ocorre dentro de um arquivo texto.
 Ignore as letras com acento. O usuário deverá informar o nome do arquivo.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
 FILE *arq1;
 char letras[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'}, entrada[20], c, aux[500];
 int quantidade[26];

 printf("Qual o nome do arquivo a ser lido: ");
 fgets(entrada, 20, stdin);
 entrada[strcspn(entrada, "\n")] = '\0';
 arq1 = fopen(entrada, "r");

 if (arq1 == NULL)
 {
  printf("Arquivo n?o foi encontrado!");
  exit(1);
 }
 for (size_t i = 0; i < 26; i++)
 {
  quantidade[i] = 0;
 }
 while ((c = fgetc(arq1)) != EOF)
 {
  for (size_t j = 0; j < 26; j++)
  {
   if (c == letras[j] || c == toupper(letras[j]))
   {
    quantidade[j] += 1;
   }
  }
 }
 printf("Letras contidas nesse arquivo: \n");
 for (size_t i = 0; i < strlen(letras) - 6; i++)
 {
  printf("%c - %i vezes\n", letras[i], quantidade[i]);
 }
}