/**
 * @file exercico1.c
 * @Luiz Fernando Rolim Vieira
 * @brief 
 * @version 0.1
 * @date 2022-08-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*Crie uma enumeração representando os meses do ano. 
Agora, escreva um programa que leia um valor inteiro do teclado e 
exiba o nome do mês correspondente e a quantidade de dias que ele possui.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//enumeração
enum mes{JANEIRO=1, FEVEREIRO, MARCO, ABRIL, MAIO, JUNHO, JULHO, AGOSTO, SETEMBRO, OUTUBRO, NOVEMBRO, DEZEMBRO};
//main
int main(){
    menu();
    return 0;
}//main

void menu(){
    int opcao;
do{
    printf("Digite um mes do ano, de 1 a 12:\n");
    scanf("%d",&opcao);
//switch
    switch (opcao){
    case JANEIRO:
        system("clear");
        printf("----------------------------------------\n");
        printf("Voce selecionou o mes de janeiro\n");
        printf("ele possui 31 dias\n");
        printf("----------------------------------------\n");
        break;

        case FEVEREIRO:
        system("clear");
        printf("----------------------------------------\n");
        printf("Voce selecionou o mes de Fevereiro\n");
        printf("ele possui 28 dias\n");
        printf("----------------------------------------\n");
        break;

        case MARCO:
        system("clear");
        printf("----------------------------------------\n");
        printf("Voce selecionou o mes de Marco\n");
        printf("ele possui 31 dias\n");
        printf("----------------------------------------\n");
        break;

        case ABRIL:
        system("clear");
        printf("----------------------------------------\n");
        printf("Voce selecionou o mes de Abril\n");
        printf("ele possui 30 dias\n");
        printf("----------------------------------------\n");
        break;

        case MAIO:
        system("clear");
        printf("----------------------------------------\n");
        printf("Voce selecionou o mes de Maio\n");
        printf("ele possui 31 dias\n");
        printf("----------------------------------------\n");
        break;

        case JUNHO:
        system("clear");
        printf("----------------------------------------\n");
        printf("Voce selecionou o mes de Junho\n");
        printf("ele possui 30 dias\n");
        printf("----------------------------------------\n");
        break;

        case JULHO:
        system("clear");
        printf("----------------------------------------\n");
        printf("Voce selecionou o mes de Julho\n");
        printf("ele possui 31 dias\n");
        printf("----------------------------------------\n");
        break;

        case AGOSTO:
        system("clear");
        printf("----------------------------------------\n");
        printf("Voce selecionou o mes de Agosto\n");
        printf("ele possui 31 dias\n");
        printf("----------------------------------------\n");
        break;

        case SETEMBRO:
        system("clear");
        printf("----------------------------------------\n");
        printf("Voce selecionou o mes de Setembro\n");
        printf("ele possui 30 dias\n");
        printf("----------------------------------------\n");
        break;

        case OUTUBRO:
        system("clear");
        printf("----------------------------------------\n");
        printf("Voce selecionou o mes de Outubro\n");
        printf("ele possui 31 dias\n");
        printf("----------------------------------------\n");
        break;

        case NOVEMBRO:
        system("clear");
        printf("----------------------------------------\n");
        printf("Voce selecionou o mes de Novembro\n");
        printf("ele possui 30 dias\n");
        printf("----------------------------------------\n");
        break;

        case DEZEMBRO:
        system("clear");
        printf("----------------------------------------\n");
        printf("Voce selecionou o mes de Dezembro\n");
        printf("ele possui 31 dias\n");
        printf("----------------------------------------\n");
        break;
    
    }
}while(opcao<JANEIRO||opcao>DEZEMBRO);
}