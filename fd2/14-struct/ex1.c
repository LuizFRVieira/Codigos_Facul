/**
 * @file exercicio 1.c
 * @Luiz Fernando Rolim Vieira
 * @brief
 * @version 0.1
 * @date 2022-03-15
 *
 * @copyright Copyright (c) 2022
 *
 */

/*Crie uma estrutura para representar as coordenadas de um ponto no plano (posições X e Y).
Em seguida, declare e leia do teclado dois pontos e exiba a distância entre eles.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

 /*Crie uma estrutura para representar as coordenadas de
um ponto no plano (posições X e Y). Em seguida, declare
e leia do teclado dois pontos e exiba a distância entre
eles.*/


//coordenadas
struct Posicao{
 float x;
 float y;
};//struct
struct Posicao Posicao1, Posicao2;


int main (){

    float Distancia = 0;
//entrada de dados
    printf("insira a coordenada x do ponto 1\n");
    scanf("%f", &Posicao1.x);

    printf("insira a coordenada y do ponto 1\n");
    scanf("%f", &Posicao1.y);

    printf("insira a coordenada x do ponto 2\n");
    scanf("%f", &Posicao2.x);

    printf("insira a coordenada y do ponto 2\n");
    scanf("%f", &Posicao2.y);

 //medir a distancia
    Distancia = sqrt(pow((Posicao1.x - Posicao2.x),2) + pow((Posicao1.y - Posicao2.y),2));

    printf("a distancia entre os pontos e: %f \n", Distancia);

    return 0;


}