/**
 * @file exercicio 5.c
 * @Luiz Fernando Rolim Vieira
 * @brief 
 * @version 0.1
 * @date 2022-03-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
/*Crie uma função que que receba o valor de um inteiro positivo N, calcule e retorne o fatorial desse número.*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int funcao (int n){
    int fat;
for(fat = 1; n > 1; n = n - 1){
fat = fat * n;
}//for

return fat;
}//main

int main()
{
int res;
int n;

printf("Insira um valor para o qual deseja calcular seu fatorial: ");
scanf("%d", &n);

res = funcao(n);

printf("\nO fatorial: %d", res);
return 0;
}