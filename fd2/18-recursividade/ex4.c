/**
 * @file exercicio4.c
 * @Luiz Fernando Rolim Vieira
 * @brief 
 * @version 0.1
 * @date 2022-04-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
/*Faça uma função recursiva que retorne o n-ésimo termo da sequência de Fibonacci, sendo que n é recebido por parâmetro. 
Utilize essa função para desenvolver um programa que mostre no main() os n termos dessa sequência na tela, 
a partir do valor de n recebido pelo teclado. Sabe-se que o 1º termo é 0 e o 2º termo é 1.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fibo(int n)
{
 if (n == 0)
 {
  return 0;
 }
 else if (n == 1)
 {
  return 1;
 }
 else
 {
  return (fibo(n - 1) + fibo(n - 2));
 }
}
int main()
{
 int n;
 scanf("%i", &n);
 for (int i = 0; i < n; i++)
 {
    printf("%i\n", fibo(i));
 }
} 