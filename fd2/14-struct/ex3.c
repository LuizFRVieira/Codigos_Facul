/**
 * @file exercicio 3.c
 * @Luiz Fernando Rolim Vieira
 * @brief
 * @version 0.1
 * @date 2022-03-15
 *
 * @copyright Copyright (c) 2022
 *
 */

/*Construa uma estrutura aluno com nome, curso e 4 notas, média e situação. Leia as informações nome, curso e notas do teclado, calcule a média e armazene a situação do aluno:

media ≥ 7 → Aprovado;
3 ≤ media < 7 → Exame;
media < 3 → Reprovado;*/

#include <stdio.h>
#include <stdlib.h>

// struct alunos
typedef struct
{
    char nome[10];
    char curso[20];
    float notas[4];
    float media;
    char situacao[10];
} Aluno;

int main(){
    Aluno aluno_1;

    // alunos
    printf("Digite o nome do aluno : ");
    fgets(aluno_1.nome, 10, stdin);
    aluno_1.nome[strcspn(aluno_1.nome, "\n")] = '\0';
    setbuf(stdin, NULL);

    // curso

    printf("Digite o nome do curso : ");
    fgets(aluno_1.curso, 10, stdin);
    aluno_1.curso[strcspn(aluno_1.curso, "\n")] = '\0';
    setbuf(stdin, NULL);

    // nota do aluno

    for (size_t i = 0; i < 4; i++)
    {
        printf("digite a media do aluno %i :", i + 1);
        scanf("%f", &aluno_1.notas[i]);
    }

    // media do aluno

    aluno_1.media = (aluno_1.notas[0] + aluno_1.notas[1] + aluno_1.notas[2] + aluno_1.notas[3]) / 4;

    // situação do aluno

    if (aluno_1.media >= 7)
    {
        strcpy(aluno_1.situacao, "aprovado");
    } // if
    
    else if (aluno_1.media >= 3 && aluno_1.media < 7)
    {
        strcpy(aluno_1.situacao, "reprovado");
    } // else if

    // retorno
    printf("Nome do aluno :%s\n", aluno_1.nome);
    printf("nome de curso : %s\n", aluno_1.curso);

    for (size_t i = 0; i < 4; i++)
    {
        printf("Nota%i do aluno: %2.f\n", i, aluno_1.notas[i]);
    }
    printf("media do aluno %2.f\n", aluno_1.media);
    printf("situacao do aluno: %s\n", aluno_1.situacao);

    return 0;

} // main
