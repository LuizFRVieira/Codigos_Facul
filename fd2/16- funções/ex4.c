/**
 * @file exercicio 4.c
 * @Luiz Fernando Rolim Vieira
 * @brief 
 * @version 0.1
 * @date 2022-03-23
 * 
 * @copyright Copyright (c) 2022
 * 
 
/*Faça uma função que receba a média final de um aluno por parâmetro e retorne o seu conceito, conforme a tabela abaixo:

Nota Conceito
[ 9 - 10]  A
[ 7 – 9 [  B
[ 5 - 7 [  C
[ 0 – 5 [  D
*/
#include <stdio.h>
#include <stdlib.h>

char Julgamento(float nota) {
    if(nota >= 9) {
        return 'A';
    } else if(nota >= 7 && nota < 9) {
        return 'B';
    } else if(nota >= 5 && nota < 7) {
        return 'C';
    } else if(nota < 5) {
        return 'D';
    }
}

int main() {
float n1 = 0;
printf("Insira a nota do aluno (1 a 10): ");
scanf("%f", &n1);
while(n1 > 10 || n1 < 0) {
    printf("Insira a nota novamente: ");
    scanf("%f", &n1);
}
printf("Conceito recebido: %c", Julgamento(n1));
return 0;
}