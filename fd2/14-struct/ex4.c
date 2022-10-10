/*Faça um programa que controla o consumo de energia dos eletrodomésticos de uma casa e:

–Crie e leia 5 eletrodomésticos que contém nome (máximo 15 letras), potência (real, em kW) e tempo ativo por dia (real, em horas).

–Leia um tempo t (em dias), calcule e mostre o consumo total na casa e o consumo relativo de cada eletrodoméstico (consumo/consumo total)
nesse período de tempo. Apresente este último dado em porcentagem.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// strutura
typedef struct{
   char nome[16];
   float potencia;
   int horas;
   float consumodia;
   float consumogeral;
} eletro;

int main(){
   eletro eletros[5];
   int dias;
   float consumo_total;
   // recebe
   for (size_t i = 0; i < 5; i++){

      printf("digite o nome do eletro domestico\n");
      fgets(eletros[i].nome, 15, stdin);
      eletros[i].nome[strcspn(eletros[i].nome, "\n")] = '\0';
      setbuf(stdin, NULL);
      system("cls");

      printf("insira a potencia real em kw\n");
      scanf("%f", &eletros[i].potencia);
      setbuf(stdin, NULL);
      system("cls");

      printf("insira o tempo ativo por dia (em horas)\n");
      scanf("%d", &eletros[i].horas);
      setbuf(stdin, NULL);
      system("cls");

      printf("digite o numero de dias\n");
      scanf("%d", &dias);
      setbuf(stdin, NULL);
      system("cls");
   }
//calcula o consumo de dia
   for (size_t i = 0; i < 5; i++){
      eletros[i].consumodia = eletros[i].potencia * eletros[i].horas;
   }
//consumo geral
   for (size_t i = 0; i < 5; i++){
      eletros[i].consumogeral = eletros[i].consumodia * dias;
   }
//consumo total
   for (size_t i = 0; i < 5; i++){
      consumo_total = consumo_total + eletros[i].consumogeral;
   }
//printa no terminal
   for (size_t i = 0; i < 5; i++){
      printf("o consumo do eletro %-5s e de %-5.2f\n", eletros[i].nome, eletros[i].consumogeral);
   }

   printf("A soma do consumo de todos os eletro é de %.2f%%\n", consumo_total);

   return 0;
}
