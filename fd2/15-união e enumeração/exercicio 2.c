/**
 * @file exercicio2.c
 * @Luiz Fernando Rolim Vieira
 * @brief
 * @version 0.1
 * @date 2022-08-24
 *
 * @copyright Copyright (c) 2022
 *
 */

/*Crie um programa de cadastro que receba, armazene, e em seguida, exiba os dados de 5 pessoas.
Cada pessoa possui: nome, idade, peso, data de nascimento, brasileiro ou estrangeiro. Caso seja Brasileiro, armazene o CPF, caso estrangeiro, armazene o passaporte.

Regra: Utilize structs, typedef, union e enum.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// registro 1
typedef enum{
  Brasileiro,
  Estrangeiro
} Tipo;

// registro 2
typedef struct{
  char Nome[50];
  int Idade;
  float Peso;
  char Nascimento[50];
  Tipo tipo;
  union{
    char Passaporte[20];
    char CPF[20];
  } Registro;
} Pessoa;

// main
int main(){
  char Entrada[50];
  int F = 0;
  Pessoa Pessoa[5];

//recebe dados
  for (size_t i = 0; i < 5; i++){
    F = 0;
    //recebe nome
    printf("----------------------------\n");
    printf("Insira o nome da %i° pessoa: \n", i + 1);
    printf("----------------------------\n");

    setbuf(stdin, NULL);
    fgets(Pessoa[i].Nome, 50, stdin);
    Pessoa[i].Nome[strcspn(Pessoa[i].Nome, "\n")] = '\0';
    setbuf(stdin, NULL);
    system("clear");

    //recebe idade
    printf("---------------------\n");
    printf("Qual a idade de %s: \n", Pessoa[i].Nome);
    printf("---------------------\n");
    scanf("%i", &Pessoa[i].Idade);
    system("clear");

    //recebe peso
    printf("--------------------\n");
    printf("Qual o peso de %s: \n", Pessoa[i].Nome);
    printf("--------------------\n");
    scanf("%f", &Pessoa[i].Peso);
    system("clear");

    //recebe nascimento
    printf("----------------------------------------------------------------\n");
    printf("Qual a data de nascimento de %s (Utilize o formato DD/MM/YYYY): \n", Pessoa[i].Nome);
    printf("----------------------------------------------------------------\n");
    setbuf(stdin, NULL);
    fgets(Pessoa[i].Nascimento, 50, stdin);
    Pessoa[i].Nascimento[strcspn(Pessoa[i].Nascimento, "\n")] = '\0';
    setbuf(stdin, NULL);
    system("clear");

    do{
      printf("-------------------------------------------\n");
      printf("Essa pessoa é brasileira ou estrangeira?: \n");
      printf("-------------------------------------------\n");
      setbuf(stdin, NULL);
      fgets(Entrada, 50, stdin);
      Entrada[strcspn(Entrada, "\n")] = '\0';
      setbuf(stdin, NULL);

      //caso brasileiro

      //!strcasecmp (compara automaticamente se é iagual)

      if (!strcasecmp(Entrada, "Brasileira") || !strcasecmp(Entrada, "Brasileiro")){
        Pessoa[i].tipo = Brasileiro;
        system("clear");
        printf("-------------------\n");
        printf("Insira o CPF de %s: \n", Pessoa[i].Nome);
        printf("-------------------\n");

        setbuf(stdin, NULL);
        fgets(Pessoa[i].Registro.CPF, 50, stdin);
        setbuf(stdin, NULL);
        Pessoa[i].Registro.CPF[strcspn(Pessoa[i].Registro.CPF, "\n")] = '\0';
        F = 1;
      }

      //estrangeiro
      else if (!strcasecmp(Entrada, "Estrangeira") || !strcasecmp(Entrada, "Estrangeiro")){
        Pessoa[i].tipo = Estrangeiro;
        system("clear");

        printf("--------------------------\n");
        printf("Insira o Passaporte de %s: \n", Pessoa[i].Nome);
        printf("--------------------------\n");

        fgets(Pessoa[i].Registro.Passaporte, 50, stdin);
        setbuf(stdin, NULL);
        Pessoa[i].Registro.Passaporte[strcspn(Pessoa[i].Registro.Passaporte, "\n")] = '\0';
        F = 1;
      }

      //tratamento de erro
      if (!F){
        printf("Insira um valor correto!.\n");
      }
    } while (!F);
  }

    system("clear");
    //escreve na tela
    printf("-----------------------------------------------------------------");
  for (size_t i = 0; i < 5; i++){
    printf("\nNome: %s\nIdade: %i\nPeso: %.2f\nData de Nascimento: %s\n", Pessoa[i].Nome, Pessoa[i].Idade, Pessoa[i].Peso, Pessoa[i].Nascimento);
    //analiza se é brasileiro ou não
    //cpf
    if (Pessoa[i].tipo == Estrangeiro){
      printf("Passaporte: %s\n", Pessoa[i].Registro.Passaporte);
    }
    //passaporte
    else if (Pessoa[i].tipo == Brasileiro){
      printf("CPF: %s\n", Pessoa[i].Registro.CPF);
    }
  }
    printf("-----------------------------------------------------------------");

} // main