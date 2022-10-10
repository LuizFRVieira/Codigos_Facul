/**
 * @file exercicio 2.c
 * @Luiz Fernando Rolim Vieira
 * @brief 
 * @version 0.1
 * @date 2022-03-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*Escreva um trecho de código para fazer a criação dos novos tipos de dados conforme solicitado abaixo:• Horário: composto de hora, minutos e segundos.• 
Data: composto de dia, mês e ano.• Compromisso: local, horário e texto que descreve o compromisso.*/

#include <stdio.h>
#include <stdio.h>

//strut de tempo
typedef struct
{
    int hora;
    int minutos;
    int segundos;

}Tempo;


//strut data
typedef struct 
{
   int dia;
   int mes;
   int ano;
}Data;

//strut de compromisso
typedef struct 
{
   char lugar[20];
   struct tempo;
   char descrição[50];
   
}compromisso;
