/**
 * @file ex6.c
 * @Luiz Fernando Rolim Vieira
 * @brief 
 * @version 0.1
 * @date 2022-05-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
/*Elabore um programa no qual o usuário informe o nome de um arquivo texto e uma palavra, 
e o programa informe o número de vezes que aquela palavra aparece*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *arq;

    char e[20];
    char pal[20];
    char c;
    char comp[20];

    int cont =0;

printf("Digite o nome do arquivo:\n");
    fgets(e,20,stdin);
    e[strcspn(e,"\n")]='\0';
    setbuf(stdin,NULL);
//caso de erro
arq = fopen(e,"r");
 if (arq == NULL){
  printf("Arquivo nao encontrado");
  exit(1);
 }


//caça a palvra

 printf("Insira a palavra que voce quer buscar: ");
 fgets(pal, 20, stdin);
 pal[strcspn(pal, "\n")] = '\0';
 setbuf(stdin,NULL);

 while ((c = fgetc(arq)) != EOF){
  if (c == pal[0]){
   comp[0] = c;
   for (size_t i = 1; i < strlen(pal); i++){
    comp[i] = fgetc(arq);
   }
   if (!strcasecmp(pal, comp)){
    cont++;
   }//if interno
  }//if
 }//while

//impressão
if (cont==0){
    printf("Nao foi encontrada a palavara %sno arquivo",pal);
    exit(1);
}

if (cont==1){
    printf("foi encontrada 1 vez a palavra %s no arquivo",pal);
    exit(1);
}

printf("foi encontrada %i vezes a palavra %s no arquivo",cont,pal);
fclose(arq);
    return 0;
}