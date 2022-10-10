/**
 * @file exercico 2.c
 * @Luiz Fernando Rolim Vieira
 * @brief 
 * @version 0.1
 * @date 2022-03-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*Elabore uma função que receba por parâmetro o sexo (char) e a altura de uma pessoa (real), calcule e retorne seu peso ideal. 
Para isso, utilize as fórmulas a seguir:

Para homens: (72.7*altura) - 58
Para mulheres: (62.1*altura) – 44.7
*/

#include <stdio.h>
#include<stdlib.h>

//função
void funcao(){
 char genero;
    float peso, altura;
    scanf("%c",&genero);

    switch(genero){
        //caso feminino
    case 'f':
    case 'F':

        printf("digite sua altura:\n");
        scanf("%f",&altura);

        peso = (62.1*altura)-44.7;

        printf("seu peso ideal e %f",peso);
//caso masculino
    case 'm':
    case 'M':

        printf("digite sua altura:\n");
        scanf("%f",&altura);

        peso = (72.2*altura)-58;

        printf("seu peso ideal e %.2f",peso);
    }
    return; //retorna pra função
}



//main
int main(){
   
    printf("aperte F para feminio ou M para masculino\n");
    funcao();
    
return 0;
}//main