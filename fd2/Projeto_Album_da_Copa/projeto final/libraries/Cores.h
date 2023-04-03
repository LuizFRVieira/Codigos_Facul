
#ifndef CORES_H  // Se não definido
#define CORES_H  //Define CORES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Resetar()  //Reseta a cor do texto
{
    printf("\033[0m");  //Reseta a cor do texto
}  //Reseta a cor do texto

void Ciano(char *Mensagem)  //Define a cor do texto ciano
{
    printf("\033[0;36m");  //Define a cor do texto ciano
    while (*Mensagem != '\0')  //Enquanto não chegar no fim da string
    {
        printf("%c", *(Mensagem));  //Imprime o caractere
        Mensagem++;  //Avança para o proximo caractere
    }  //Fim do while
    Resetar();  //Reseta a cor do texto
}  //Fim da funcao

void Roxo(char *Mensagem)  //Define a cor do texto roxo
{
    printf("\033[0;35m");  //Define a cor do texto roxo
    while (*Mensagem != '\0')   //Enquanto não chegar no fim da string
    {
        printf("%c", *(Mensagem));  //Imprime o caractere
        Mensagem++;  //Avança para o proximo caractere
    }  //Fim do while
    Resetar();  //Reseta a cor do texto
}  //Fim da função

void Azul(char *Mensagem)  //Define a cor do texto azul
{
    printf("\033[0;34m");  //Define a cor do texto azul
    while (*Mensagem != '\0')   //Enquanto não chegar no fim da string
    {
        printf("%c", *(Mensagem));  //Imprime o caractere
        Mensagem++;  //Avança para o proximo caractere
    }  //Fim do while
    Resetar();  //Reseta a cor do texto
}  //Fim da função

void Amarelo(char *Mensagem)  //Define a cor do texto amarelo
{
    printf("\033[0;33m");  //Define a cor do texto amarelo
    while (*Mensagem != '\0')  //Enquanto não chegar no fim da string
    {
        printf("%c", *(Mensagem));  //Imprime o caractere
        Mensagem++;  //Avança para o proximo caractere
    }  //Fim do while
    Resetar();  //Reseta a cor do texto
}  //Fim da função

void Verde(char *Mensagem)  //Define a cor do texto verde
{
    printf("\033[0;32m");  //Define a cor do texto verde
    while (*Mensagem != '\0')  // Enquanto não chegar no fim da string
    {
        printf("%c", *(Mensagem)); //Imprime o caractere
        Mensagem++;  //Avança para o proximo caractere
    }  //Fim do while
    Resetar(); //Reseta a cor do texto
}  //Fim da função

void Vermelho(char *Mensagem)  //Define a cor do texto vermelho
{
    printf("\033[0;31m");  //Define a cor do texto vermelho
    while (*Mensagem != '\0')  // Enquanto não chegar no fim da string
    {
        printf("%c", *(Mensagem));  //Imprime o caractere
        Mensagem++;  //Avança para o proximo caractere
    }  //Fim do while
    Resetar();  //Reseta a cor do texto
}  //Fim da função

#endif  //CORES_H