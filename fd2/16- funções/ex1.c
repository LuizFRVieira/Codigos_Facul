/**
 * @file exercicio 1.c
 * @Luiz Fernando Rolim Vieira
 * @brief 
 * @version 0.1
 * @date 2022-03-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*Faça um algoritmo que implemente uma função que receba 3 números inteiros e retorne o maior valor. 
Se algum número for negativo retorne -1*/

#include <stdio.h>
#include <stdlib.h>


void funcao (){
int a, b, c, menor, maior;
 scanf("%d%d%d", &a, &b, &c);
    menor = a;
    maior = a;

    if(menor > b)
        menor = b;
    if(menor > c)
        menor = c;

    if(maior < b)
        maior = b;
    if(maior < c)
        maior = c;
    

    printf(" Maior: %d\n", maior);
}//void

int main() {
    
    printf("Digite tres valores: ");
   funcao();
}//main
