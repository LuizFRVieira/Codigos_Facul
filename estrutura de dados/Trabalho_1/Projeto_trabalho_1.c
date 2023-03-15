#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Sexo
typedef enum{
    masculino = 1,
    feminino = 2
} Sexo;
//Estado_civil

typedef enum{
    casado = 1,
    solteiro = 2,
    Separado = 3,
    Divorciado = 4,
    viuvo = 5

} Estado_civil;

//Endereço
typedef struct{
    int Numero_rua;
    char rua[21];
    char cidade[21];
    char estado[21];

} Endereço;

//cadastro_funcionario
typedef struct
{
    char Nome[21];
    Endereço endereço;
    Estado_civil estado;
    float Salario;
    int Idade;
    Sexo sexo;

} Cadastro;




//main
int main()
{
    return 0;
}